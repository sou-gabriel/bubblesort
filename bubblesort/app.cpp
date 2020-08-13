#include <iostream>
#include <stdlib.h> 
#include <string.h>
#include <locale.h>
#include <time.h>
using namespace std;

#define TAMANHO_VETOR 8 
#define MAXIMO_NUMEROS_ALEATORIOS 100 

// DECLARAÇÃO DAS FUNÇÕES
void criarVetor(int *v);
void exibirVetor(int *v);
void bubblesort (int *v);

int main()
{
    setlocale(LC_ALL,"");
    
    int vetor[TAMANHO_VETOR], opcao;
    bool continua;
    
    continua = true;
    
    do 
    {
    	system("cls");
    	cout << "=== ESTRUTURAS DE DADOS ===\n\n";
    	cout << "1. CRIAR NOVO VETOR\n";
    	cout << "2. EXIBIR VETOR ATUAL\n";
    	cout << "3. BUBBLEOSRT\n";
    	cout << "0. SAIR (S/N)\n";
    	cout << "\nSUA OPÇÃO: ";
    	cin >> opcao;
    	
    	switch(opcao){
    		case 1: 
				criarVetor(vetor);
    			break;
    			
    		case 2:
    			exibirVetor(vetor);
    			break;
    			
    		case 3:
    			bubblesort(vetor);
    			break;
    			
    		case 4:
    			break;
    			
    		case 0:
    			continua = false;
    			break;
    			
    		default: 
    			cout << "Opção Inválida!\n";
    			system("pause"); // Pessoa para pessoa aperta "Enter"
		}
	}while(continua);

    system("pause");
    return 0;
}

// FUNÇÕES
void criarVetor(int *v)
{
	int i;
	srand(time(NULL));
	
	for (i = 0; i < TAMANHO_VETOR; i++) 
	{
		v[i] = rand()%MAXIMO_NUMEROS_ALEATORIOS;		
	}	
	cout << "VETOR CRIADO COM SUCESSO!\n\n";
	system("pause");
}

void exibirVetor(int *v)
{
	int i;
	cout << "\n=== VETOR ATUAL ===\n";
	
	for (i = 0; i < TAMANHO_VETOR; i++)
	{
		cout << "Índice: " << i << " -> " << v[i] << "\n";
	}
	cout << "\n=== FIM DO VETOR ===\n";
	system("pause");
	system("cls");
}

void bubblesort(int *v) 
{
	int i, j, aux;
	
	exibirVetor(v);
	
	for (i = 0; i < TAMANHO_VETOR; i++) 
	{
		cout << i + 1 <<"° PASSAGEM PELO VETOR\n";
		
		for (j = 0; j < TAMANHO_VETOR - 1; j++) 
		{
			cout << j+1 << "° COMPARAÇÃO\n";
						
			if (v[j] > v[j+1])
			{
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;			
			}
			exibirVetor(v);
		} 
	}
	cout << "O VETOR FOI ORDENADO\n";
	system("pause");
}
