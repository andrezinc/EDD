#pragma once
#include <string>
#include <string.h>
#include <iostream>
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
					int cont=0;
					int ifs=0;
					int linha=0;
					for(int i=0;i<tamanho;i++){
							cont++;
							linha++;
							if(Nome_Rg[i].getRg()==rg){
									ifs++;
									std::cout<<Nome_Rg[i].getNome()<<" "<<Nome_Rg[i].getRg()<<" na linha:"<<linha<<std::endl;
									break;
							}
					}
					std::cout<<std::endl<<"fez:"<<cont<<std::endl;
					std::cout<<std::endl<<"if mais ou menos ifs:"<<ifs<<std::endl;
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
			void insertSort(){
					int i=0;
					int cont=0;
					for(i=1;i<tamanho;i++){
							Elemento pivo=Nome_Rg[i];//pega o segundo numero da lista
							int j=i-1; //pega o primeiro 
							cont++;
							while(j>=0&&Nome_Rg[j].getRg()>pivo.getRg()){ //compara pra ver se é maior que o pivo 
									cont++;
									Nome_Rg[j+1]=Nome_Rg[j]; // vai jogando pra frente a lista 
									j--; //vai passando pro de tras e vai comparando pra ver se é maior
							}
							Nome_Rg[j+1]=pivo; //quando termina coloca o lugar vazio com ele
							//std::cout<<std::endl;
							//imprimir();
							//std::cout<<std::endl;
							}
							std::cout<<std::endl<<"fez:"<<cont<<std::endl;
					}
			void selectionSort(){
					int cont=0;
					int ifs=0;
					for(int i=0;i<tamanho;i++){
							cont++;
							int menor =i; //pega o lugar atual
							for(int j=i+1;j<tamanho;j++){ //percorre todo o resto do vetor
									cont++;
									if(Nome_Rg[j].getRg()<Nome_Rg[menor].getRg()){ // se achar um numero menor 
											menor=j; //coloca aquele numero menor ai
											ifs++;
									}
							}
							if(menor!=i){ //se for diferente do lugar onde ele tava
											ifs++;
											Elemento aux=Nome_Rg[menor]; //troca de lugar os termos
											Nome_Rg[menor]=Nome_Rg[i];
											Nome_Rg[i]=aux;
							}
							//	std::cout<<std::endl;
							//	imprimir();
							//	std::cout<<std::endl;
							}
				std::cout<<std::endl<<"fez:"<<cont<<std::endl;
				std::cout<<std::endl<<"if"<<ifs<<std::endl;
			}				
			void bubbleSort(){
					int cont=0;
					int ifs=0;
					for(int i=0;i<tamanho-1;i++){
							for(int j=0;j<tamanho-i-1;j++){
									cont++;
									if(Nome_Rg[j].getRg()>Nome_Rg[j+1].getRg()){
											std::swap(Nome_Rg[j],Nome_Rg[j+1]);
									}
							}
						//std::cout<<std::endl;
						//imprimir();
						//std::cout<<std::endl;
					}
					std::cout<<std::endl<<"fez:"<<cont<<std::endl;
					std::cout<<std::endl<<"if"<<ifs<<std::endl;
			}
			void shellSort(){
					int cont=0;
					int ifs=0;
					for(int gap=tamanho/2;gap>0;gap=gap/2){
							for(int i=gap;i<tamanho;i++){
									cont++;
									Elemento t=Nome_Rg[i];
									int j;
									for(j=i;j>=gap && Nome_Rg[j-gap].getRg()>t.getRg();j-=gap){
											ifs++;
											Nome_Rg[j]=Nome_Rg[j-gap];
									}
									Nome_Rg[j]=t;
								}
						}
					std::cout<<std::endl<<"fez:"<<cont<<std::endl;
					std::cout<<std::endl<<"if mais ou menos ifs:"<<ifs<<std::endl;
			}
			int contQ=0;
			int ifsQ=0;
			void quickSort(int inicio,int finalz){
					int i=inicio,j=finalz;
					Elemento pivo=Nome_Rg[(i+j)/2];
					do{
						while(Nome_Rg[i].getRg()<pivo.getRg())
						{
								i=i+1;
								contQ++;
						}
						while(Nome_Rg[j].getRg()>pivo.getRg())
						{
								j=j-1;
								contQ++;
						}
						if(i<=j){
								ifsQ++;
								std::swap(Nome_Rg[i],Nome_Rg[j]);
								i++;
								j--;
						}
					}while(i<=j);
					if(j>inicio)
							quickSort(inicio,j);
					if(i<finalz)
							quickSort(i,finalz);
			}
			void QUICKSORT(){
					contQ=0;
					ifsQ=0;
					quickSort(0,tamanho);
					std::cout<<std::endl<<"fez:"<<contQ<<std::endl;
					std::cout<<std::endl<<"if mais ou menos ifs:"<<ifsQ<<std::endl;
			}
			void PesquisaBianria(int Valor){
					int ifs=0;
					int cont=0;
					int limiteInf=0;
					int meio;
					int limiteSup=tamanho;
					while(limiteInf<=limiteSup){
						cont++;
						meio=(limiteInf+limiteSup)/2;	
						if(Nome_Rg[meio].getRg()==Valor){
								ifs++;
								std::cout<<Nome_Rg[meio].getNome()<<" "<<Nome_Rg[meio].getRg()<<std::endl;
								break;
						}
						if(Nome_Rg[meio].getRg()>Valor)
						{
								ifs++;
								limiteSup=meio-1;
						}
						else{
								ifs++;
								limiteInf=meio+1;
						}
					}
					std::cout<<std::endl<<"fez:"<<cont<<std::endl;
					std::cout<<std::endl<<"if mais ou menos ifs:"<<ifs<<std::endl;
			}
};
