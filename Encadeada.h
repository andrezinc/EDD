#pragma once
#include <iostream> 
#include <string.h>
#include <stdio.h>
class Conjunto{
		private:
			char nomeP[10];
			unsigned int rgP;
			Conjunto *proximo;
			Conjunto *anterior;
	public:
			Conjunto():nomeP(""),rgP(0),proximo(nullptr),anterior(nullptr){

			}
			~Conjunto(){
					proximo=nullptr;
					anterior=nullptr;
			}
			void setNome(const char*nome){
					strcpy(nomeP,nome);
			}
			void setRG(int rg){
					rgP=rg;
			}
			void setProx(Conjunto *prox){
					proximo=prox;
			}
			void setAntes(Conjunto *antes){
					anterior=antes;
			}
			char *getNome(){
					return nomeP;
			}
			int getRg(){
					return rgP;
			}
			Conjunto *getProx(){
					return proximo;
			}
			Conjunto *getAntes(){
					return anterior;
			}
			
};
class Bloco{
		private: 
			Conjunto *primeiro;
			Conjunto *ultimo;
			unsigned int tamanho;
			FILE *arquivo;
		public:
			Bloco():primeiro(nullptr),ultimo(nullptr),tamanho(0),arquivo(nullptr){

			}
			~Bloco(){
				Conjunto *aux,*aux1;
				aux=primeiro;
				aux1=primeiro;
				while(aux!=nullptr){
						aux1=aux->getProx();
						delete aux;
						aux=aux1;
				}
				aux=nullptr;
				aux1=nullptr;
				arquivo=nullptr;
			}
		void incluir(Conjunto *p){
				if(primeiro==nullptr){
						primeiro=p;
						ultimo=p;
				}
				else{
						p->setAntes(ultimo);
						ultimo->setProx(p);
						ultimo=p;
				}
				tamanho++;
		}
		void inserirInicio(Conjunto *p){
				p->setProx(primeiro);
				primeiro->setAntes(p);
				primeiro=p;
				tamanho++;
		}
		void inserirFinal(Conjunto *p){
				p->setAntes(ultimo);
				ultimo->setProx(p);
				ultimo=p;
				tamanho++;
		}
		void inserirN(Conjunto *p,int n){
				if(n>1 && n<tamanho-2){
						Conjunto *aux=primeiro;
						for(int i=0;i<n-1;i++){
								aux=aux->getProx();
						}
						Conjunto *aux1=aux->getAntes();
						p->setProx(aux);
						aux->setAntes(p);
						aux1->setProx(p);
						p->setAntes(aux1);
						tamanho++;
				}
				else{
						std::cout<<"ai nao ne paizao '-' "<<std::endl;
				}
		}
		void retirInicio(){
				if(tamanho>1){
					Conjunto *aux=primeiro;
					Conjunto *aux1=aux->getProx();
					aux1->setAntes(nullptr);
					aux->setProx(nullptr);
					primeiro=aux1;
					delete aux;
					tamanho--;		
					}
				else 
						std::cout<<"ai nao ne paizao '-' "<<std::endl;
		}
		void retirFinal(){
				if(tamanho>1){
					Conjunto *aux=ultimo;
					Conjunto *aux1=aux->getAntes();
					aux1->setProx(nullptr);
					aux->setAntes(nullptr);
					ultimo=aux1;
					delete aux;
					tamanho--;			
				}
				else 
						std::cout<<"ai nao ne paizao '-' "<<std::endl;
		}
		void retirN(int n){
				if(n>1 && n<tamanho-2){
						Conjunto *aux=primeiro;
						for(int i=0;i<n-1;i++){
								aux=aux->getProx();
						}
						Conjunto *aux1=aux->getAntes();
						Conjunto *aux2=aux->getProx();
						aux->setProx(nullptr);
						aux->setAntes(nullptr);
						aux1->setProx(aux2);
						aux2->setAntes(aux1);
						delete aux;
				}
		}
		void pesquisar(int rg){
				int p=1;
				Conjunto *aux=primeiro;
				while(aux!=nullptr && rg!=aux->getRg()){
						aux=aux->getProx();
						p++;
				}
				if(aux!=nullptr)
					std::cout<<aux->getNome()<<" "<<aux->getRg()<<"posicao:"<<p<<std::endl;
				else 
						std::cout<<"xiiii nem achei"<<std::endl;
		}
		void criarArquivo(){
			arquivo=fopen("NOVO.txt","w+");
			Conjunto *aux=primeiro;
			if(arquivo!=nullptr){
				while(aux!=nullptr){
						fprintf(arquivo,"%s %i\n",aux->getNome(),aux->getRg());
						aux=aux->getProx();
					}
			}
			fclose(arquivo);
		}
		void imprimir(){
				Conjunto *aux;
				aux=primeiro;
				while(aux!=nullptr){
						std::cout<<aux->getNome()<<" "<<aux->getRg()<<std::endl;
						aux=aux->getProx();
				}
		}
		void insertSort(){
					int i=0;
					for(i=1;i<tamanho;i++){
							Conjunto *pivo=primeiro;//pega o segundo numero da lista
							int j=i-1; //pega o primeiro 
							std::cout<<std::endl;
							imprimir();
							std::cout<<std::endl;
							}
							std::cout<<std::endl<<"fez:"<<i<<std::endl;
					}
			void selectionSort(){
					int cont=0;
					for(int i=0;i<tamanho;i++){
								imprimir();
								std::cout<<std::endl;
							}
				std::cout<<std::endl<<"fez:"<<cont<<std::endl;
			}
};


