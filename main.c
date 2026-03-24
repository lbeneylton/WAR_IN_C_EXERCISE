#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// --- Funções de utilidade ---

void limpar_tela(){     // Para limpar tela
    system("clear");
}


void limpar_buffer(){   // Para limpar buffer de entrada do teclado
    int c;
    while((c=getchar()) != EOF && c != '\n');
}


void espera(){
    printf("\nPressione qualquer tecla para continuar...");
    getchar();
}

// --- Struct ---
typedef struct {        // Estrutura para os territorios
    char nome[30];
    char cor[10];
    unsigned int tropas;
} Territorio;


// --- Constantes Globais
#define TERRITORIOS 5

// Necessario ser global para as funções poderem acessar
Territorio cartas[TERRITORIOS]; // tipo identificador [quantidade]
int carta = 0;


// -- Funções das opções selecionadas --
int cadastrar(){
    printf("---------  Cadastro de Novo Território  ---------\n");

    if (carta >= TERRITORIOS){
        printf("\nNão é possível cadastrar mais territórios. Limite atingido\n");
        return 0;
    }

    // Captura o nome do territorio e salva no array de posiçao carta, depois retira o \n
    printf("Digite o nome do territorio: ");
    fgets(cartas[carta].nome, 30, stdin);
    cartas[carta].nome[strcspn(cartas[carta].nome, "\n")] = '\0';

    printf("Digite a cor do exército: ");
    fgets(cartas[carta].cor, 10, stdin);
    cartas[carta].cor[strcspn(cartas[carta].cor, "\n")] = '\0';

    printf("Digite a quantidade de tropas: ");
    scanf("%d", &cartas[carta].tropas);
    limpar_buffer();

    carta++;
    printf("\nTerritório cadastrado com sucesso!\n");
    return 1;
}

int listar(){
    printf("------------  Lista de Territórios  ------------\n\n");

    
};




// --- Função Principal ---
int main (){
    int opc;
    

    do{     // loop principal de escolhas
        limpar_tela();
        printf("==================================================\n");
        printf("                 WAR - TERRITORIOS\n");
        printf("==================================================\n");
        printf("1 - Cadastrar\n");
        printf("2 - Ver Cartas\n");
        printf("0 - Sair\n");
        printf("--------------------------------------------------\n");
        printf("Escolha uma opção: ");


        // Leitura e seleção da escolha
        scanf("%d", &opc);
        limpar_buffer();
        limpar_tela();
        switch (opc){
            case 1:
                cadastrar();
                break;

            case 2:
                listar();
                break;

            case 0:
                printf("Você escolheu sair do sistema...\n");
                
                break;

            default:
                printf("Escolha uma opção válida");
                break;
        };  

        espera(); // Garante que com qualquer escolha tenha uma tela de espera

    }while(opc != 0);

    return 0;
};