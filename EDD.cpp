#include <iostream> 
#include <string.h>
#include <stdio.h>
class Elemento{
	private:
			int rgP;
			char nomeP[10];
	public:
			Elemento():rgP(0),nomeP(""){
			}
			~Elemento(){

			}
			void setRg(int rg){
					rgP=rg;
			}
			int getRg(){
					return rgP;
			}
			void setNome(const char *nome){
					strcpy(nomeP,nome);
			}
			char *getNome(){
					return nomeP;
			}
};
class Vetor{
		private:
				Elemento *Nome_Rg;
				int tamanho;
				int capacidade;
				FILE *arquivo;
				void aumentar(){
					capacidade*=2;
					Elemento *novo = new Elemento[capacidade];
					for(int i=0;i<tamanho;i++){
						novo[i]=Nome_Rg[i];	
					}
					delete[] Nome_Rg;
					Nome_Rg=novo;
				}
				void deslocar(int n){
						if(tamanho+1==capacidade)
								aumentar();
						for(int i=tamanho;i>n;i--)
								Nome_Rg[i]=Nome_Rg[i-1];
				}
				void remover(int n){
						n=n-1;
						Elemento aux;
						for(int i=n;i<tamanho;i++){
								Nome_Rg[i]=Nome_Rg[i+1];
						}
				}
		public:
			Vetor():Nome_Rg(nullptr),capacidade(100),tamanho(0),arquivo(nullptr){
				Nome_Rg = new Elemento[100];
			}
			~Vetor(){
					delete[] Nome_Rg;
					arquivo=nullptr;
			}
			void adicionar(Elemento n){
					if(tamanho==capacidade)
						aumentar();
					Nome_Rg[tamanho]=n;
					tamanho++;
			}
			void adiciona_inciar(Elemento n){
				 deslocar(0);
				 Nome_Rg[0]=n;
				 tamanho++;
			}
			void adiciona_final(Elemento n){
					adicionar(n);
			}
			void adiciona_posicaoN(Elemento n,int pos){
					deslocar(pos);
					Nome_Rg[pos]=n;
			}
			void remove_inciar(){
						remover(1);	
						tamanho--;
			}
			void remover_final(){
					tamanho--;
			}
			void remover_posicaoN(int posicao){
					remover(posicao);
					tamanho--;
			}
			void pesquisar(int rg){
					int linha=0;
					for(int i=0;i<tamanho;i++){
							linha++;
							if(Nome_Rg[i].getRg()==rg){
									std::cout<<Nome_Rg[i].getNome()<<" "<<Nome_Rg[i].getRg()<<" na linha:"<<linha<<std::endl;
									break;
							}
					}
			}
			void imprimir(){
					for(int i=0;i<tamanho;i++){
							std::cout<<Nome_Rg[i].getNome()<<" "<<Nome_Rg[i].getRg()<<std::endl;
					}
			}
			void criarArquivo(){
			arquivo=fopen("NOVO.txt","w+");
			if(arquivo!=nullptr)
					for(int i=0;i<tamanho;i++)
						fprintf(arquivo,"%s %i\n",Nome_Rg[i].getNome(),Nome_Rg[i].getRg());
			fclose(arquivo);
			}

};
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
};

int menu_encadeada(Bloco *lista_encadeada){
		Conjunto* h;
		FILE *arquivo;
		unsigned int rg_pesquisa;
		unsigned int posicao=0;
		clock_t t1=0,t2=0;
		float diff=0;
		int opcao=0;
		char p[10]="";
		int rg=-1;
comeco:
		std::cout<<"1-Adicionar Inicio da lista"<<std::endl<<"2-Adicionar Final da lista"<<std::endl<<"3-Adicionar em N posicao"<<std::endl;
		std::cout<<"4-Retirar Inicio"<<std::endl<<"5-Retirar Final"<<std::endl<<"6-Retirar na N posicao"<<std::endl;
		std::cout<<"7-Pesquisar"<<std::endl<<"8- Imprimir"<<std::endl<<"9-Salvar em arquivo"<<std::endl<<"10-Fechar"<<std::endl;
		std::cin>>opcao;
		switch(opcao){
				case 1:
						std::cout<<"coloque o nome e o rg:";
						std::cin>>p>>rg;
						t1 = clock(); 
						h = new Conjunto();
						h->setNome(p);
						h->setRG(rg);
						lista_encadeada->inserirInicio(h);
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco;
				case 2:
						std::cout<<"coloque o nome e o rg:";
						std::cin>>p>>rg;
						t1 = clock(); 
						h = new Conjunto();
						h->setNome(p);
						h->setRG(rg);
						lista_encadeada->inserirFinal(h);
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco;
				case 3:
						std::cout<<"coloque o nome, rg e a posicao:";
						std::cin>>p>>rg>>posicao;
						t1 = clock(); 
						h = new Conjunto();
						h->setNome(p);
						h->setRG(rg);
						lista_encadeada->inserirN(h,posicao);
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco;
				case 4:
						t1 = clock(); 
						lista_encadeada->retirInicio();
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco;
				case 5:
						t1 = clock(); 
						lista_encadeada->retirFinal();
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco;
				case 6:
						std::cout<<"qual posicao quer retirar:";
						std::cin>>posicao;
						t1 = clock(); 
						lista_encadeada->retirN(posicao);
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco;
				case 7:
						std::cout<<"numero do rg para pesquisar:";
						std::cin>>rg_pesquisa;
						t1 = clock(); 
						lista_encadeada->pesquisar(rg_pesquisa);
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco;
				case 8:
						t1 = clock(); 
						lista_encadeada->imprimir();
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco;
				case 9:
						t1 = clock(); 
						lista_encadeada->criarArquivo();
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco;
				default:
					return 0;

		}
		return 0;
}
int menu_sequencial(Vetor *n){
		FILE *arquivo;
		Elemento um;
		unsigned int rg_pesquisa;
		unsigned int posicao=0;
		clock_t t1=0,t2=0;
		float diff=0;
		int opcao=0;
		char p[10]="";
		int rg=-1;
comeco1:
		std::cout<<"1-Adicionar Inicio da lista"<<std::endl<<"2-Adicionar Final da lista"<<std::endl<<"3-Adicionar em N posicao"<<std::endl;
		std::cout<<"4-Retirar Inicio"<<std::endl<<"5-Retirar Final"<<std::endl<<"6-Retirar na N posicao"<<std::endl;
		std::cout<<"7-Pesquisar"<<std::endl<<"8- Imprimir"<<std::endl<<"9-Salvar em arquivo"<<std::endl<<"10-Fechar"<<std::endl;
		std::cin>>opcao;
		switch(opcao){
				case 1:
						std::cout<<"nome e rg:";
						std::cin>>p>>rg;
						um.setRg(rg);
						um.setNome(p);
						t1 = clock(); 
						n->adiciona_inciar(um);
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco1;
				case 2:
						std::cout<<"nome e rg:";
						std::cin>>p>>rg;
						um.setRg(rg);
						um.setNome(p);
						t1 = clock(); 
						n->adiciona_final(um);
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco1;
				case 3:
						std::cout<<"nome e rg e posicao:";
						std::cin>>p>>rg>>posicao;
						um.setRg(rg);
						um.setNome(p);
						t1 = clock(); 
						n->adiciona_posicaoN(um,posicao);
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco1;
				case 4:
						std::cout<<"removeu inicio";
						t1 = clock(); 
						n->remove_inciar();
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco1;
						
				case 5:
						std::cout<<"removeu final"<<std::endl;
						t1 = clock(); 
						n->remover_final();
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco1;
				case 6:
						std::cout<<"posicao para remover:"<<std::endl;
						std::cin>>posicao;
						t1 = clock(); 
						n->remover_posicaoN(posicao);	
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco1;
				case 7:
						std::cout<<"rg para pesquisar:"<<std::endl;
						std::cin>>rg;
						t1 = clock(); 
						n->pesquisar(rg);
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco1;
				case 8:
						t1 = clock(); 
						n->imprimir();
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco1;
				case 9:
						t1 = clock(); 
						n->criarArquivo();
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco1;
				case 10:
			return 0;
				default:
			return 0;
	}
}
int main(){
		clock_t t1=0,t2=0;
		float diff=0;
		Bloco lista_encadeada;
		char p[10]="";
		int rg=-1;
		FILE *T;
		int a=0;
		int opcao=0;
		Vetor n;
		Elemento sequencial;
		std::cout<<"1-Lista sequencial (Opção 10 aclopada)"<<std::endl<<"2-Lista encadeada(Opção 10 aclopada)"<<std::endl;
		std::cin>>opcao;
		switch(opcao){
				case 1:
				t1 = clock(); // pega esse instante
					T=fopen("arquivocomprimidonomerg/NomeRG10.txt","r");
						if(T!=nullptr){
							fscanf(T,"%9[^,],%d",p,&rg);
							while(rg!=-1){
									sequencial.setNome(p);
									sequencial.setRg(rg);
									n.adicionar(sequencial);
									rg=-1;
									strcpy(p,"");
									fscanf(T,"%9[^,],%d",p,&rg);
							}
						}
				t2 = clock(); // pega esse instante
				diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
				std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
				menu_sequencial(&n);
				return 0;
				case 2:
				t1 = clock(); // pega esse instante
					T=fopen("arquivocomprimidonomerg/NomeRG100M.txt","r");
						if(T!=nullptr){
							fscanf(T,"%9[^,],%d",p,&rg);
							while(rg!=-1){
								Conjunto* h;
								h = new Conjunto();
								h->setNome(p);
								h->setRG(rg);
								lista_encadeada.incluir(h);
								rg=-1;
								strcpy(p,"");
								fscanf(T,"%9[^,],%d",p,&rg);
							}
						fclose(T);
					}
				t2 = clock(); // pega esse instante
				diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
				std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
				menu_encadeada(&lista_encadeada);
				return 0;
				default:
					return 0;
		}
		return 0;
}
