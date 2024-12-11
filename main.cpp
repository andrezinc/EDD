#include <iostream> 
#include <string.h>
#include <stdio.h>
#include "Sequencial.h"
#include "Encadeada.h"
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
		std::cout<<"7-Pesquisar"<<std::endl<<"8- Imprimir"<<std::endl<<"9-Salvar em arquivo"<<std::endl<<"10- InsertionSort"<<std::endl;
		std::cout<<"11-Selection"<<std::endl<<"12 - Bubble"<<std::endl<<"13- Shell"<<std::endl<<"14- Quick"<<std::endl;
		std::cout<<"15-Pesquisa Binaria"<<std::endl<<"16-Sair"<<std::endl;
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
						t1 = clock(); 
						n->insertSort();
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco1;
				case 11:
						t1 = clock(); 
						n->selectionSort();
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco1;
				case 12:
						t1 = clock(); 
						n->bubbleSort();
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco1;
				case 13:
						t1 = clock(); 
						n->shellSort();
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco1;
				case 14:
						t1 = clock(); 
						n->QUICKSORT();
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco1;
				case 15:
						int rg;
						std::cout<<std::endl;
						std::cin>>rg;
						t1 = clock(); 
						n->PesquisaBianria(rg);
						t2 = clock(); // pega esse instante
						diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
						std::cout<<"abriu em "<<diff<<" segundos"<<std::endl;
goto comeco1;


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
					T=fopen("arquivocomprimidonomerg/NomeRG10K.txt","r");
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
