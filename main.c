#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// --- Funções de utilidade ---

void limpar_tela() {
    #ifdef _WIN32
        system("cls");  // Comando para Windows
    #else
        system("clear");  // Comando para Linux/macOS
    #endif
}


void limpar_buffer(){
    int c;
    c = getchar();
    while(c != '\n' && c != EOF){
        c = getchar();
    };
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
int indice_territorio = 0;


// -- Funções das opções selecionadas --
int cadastrar(){
    printf("---------  Cadastro de Novo Território  ---------\n");

    if (indice_territorio >= TERRITORIOS){ // Verifica se ainda tem espaço para territorios
        printf("\nNão é possível cadastrar mais territórios. Limite atingido\n");
        return 0;
    }

    // Captura o nome do territorio e salva no array de posiçao indice_territorio, depois retira o \n
    printf("Digite o nome do territorio: ");
    fgets(cartas[indice_territorio].nome, 30, stdin);
    cartas[indice_territorio].nome[strcspn(cartas[indice_territorio].nome, "\n")] = '\0';

    printf("Digite a cor do exército: ");
    fgets(cartas[indice_territorio].cor, 10, stdin);
    cartas[indice_territorio].cor[strcspn(cartas[indice_territorio].cor, "\n")] = '\0';

    printf("Digite a quantidade de tropas: ");
    scanf("%d", &cartas[indice_territorio].tropas);
    limpar_buffer();

    indice_territorio++;
    printf("\nTerritório cadastrado com sucesso!\n");
    return 1;
}

int listar(){
    printf("------------  Lista de Territórios  ------------\n\n");

    if (indice_territorio == 0){ // Verifica se há territorios para listagem
        printf("Nenhum território criado!\n");
        return 0;
    }

    limpar_tela();
    for (int i=0; i<indice_territorio; i++){
        printf("--------------------------------------\n");
        printf("TERRITÓRIO: %d\n", i+1);
        printf("--------------------------------------\n");
        printf("Nome: %s\n", cartas[i].nome);
        printf("Cor do exército: %s\n", cartas[i].cor);
        printf("Quantidade de tropas: %d\n\n", cartas[i].tropas);  
    };
    printf("--------------------------------------\n");

    return 1;
};




// --- Função Principal ---
int main (){
    int opc;
    char input[1];
    

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
        fgets(input, sizeof(input), stdin);
        int opc = input[0] - '0';

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