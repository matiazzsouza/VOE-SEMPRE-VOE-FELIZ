// numero máximo de voos = 15
// espaços abertos na lista de voos, código do voo == 0
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

#define numVoos 15
#define nEscalas 5
#define ciano "\033[0;36m"
#define reset "\033[0m"
#define vermelho "\033[1;31m"
#define verde "\033[1;32m"

typedef struct voo{
    int codigo, numEscalas;
    char origem[30], destino[30], escalas[nEscalas][30];
} voo;

int codigoVooExiste(int cod, voo lista[]){
    for (int i = 0; i < numVoos; i++){
        if (lista[i].codigo == cod){
            return 1;
        }
    }
    return 0;
}

void incluir_voo(voo lista[]){
    int i, nCodigo, indice = -1;
    fflush(stdin);

    for(i = 0; i < numVoos; i++){
        if(lista[i].codigo == 0){
            indice = i;
            break;
        }
    }

    if(indice == -1){
        printf("\n\tA lista de voos já está lotada. Aperte enter para continuar ...");
        fflush(stdin);
        getchar();
    }
    else{
        do{
            printf("\n\tDigite o código do voo: ");
            scanf("%d", &nCodigo);

            if(codigoVooExiste(nCodigo, lista)){
                printf("\n\tEste código já está sendo utilizado, digite um diferente");
                scanf("%d", &lista[indice].codigo);
            }
            else{
                lista[indice].codigo = nCodigo;
            }
        } while(lista[indice].codigo != nCodigo);

        printf("\n\tDigite a cidade de origem do voo %d: ", lista[indice].codigo);
        fflush(stdin);
        strupr(gets(lista[indice].origem));

        printf("\n\tDigite a cidade de destino do voo %d, que sai de %s: ", lista[indice].codigo, lista[indice].origem);
        fflush(stdin);
        strupr(gets(lista[indice].destino));

        printf("\n\tDigite o número de escalas desse voo: ");
        scanf("%d", &lista[indice].numEscalas);

        while((lista[indice].numEscalas > nEscalas) || (lista[indice].numEscalas < 0)){
            printf(vermelho "\n\tNúmero inválido, digite novamente: " reset);
            scanf("%d", &lista[indice].numEscalas);
        }

        if(lista[indice].numEscalas > 0){
            for(i = 0; i < lista[indice].numEscalas ; i++)
            {
                fflush(stdin);
                printf("\n\tDigite a cidade de parada número %d: ", i+1);
                strupr(gets(lista[indice].escalas[i]));
            }
        }
    }
    fflush(stdin);
    printf(verde "\n\t Voo adicionado com sucesso, aperte enter para voltar ao menu principal" reset);
    getchar();
}

void alterar_voo(voo lista[]){
    int cod, nCodigo, opcao = 1, indice, i;

    do{
        printf("\n\tDigite o código do voo que deseja alterar: ");
        scanf("%d", &cod);
        for(i = 0; i < numVoos; i++){
            if(lista[i].codigo == cod){
                indice = i;
                cod = -1;
                break;
            }
        }
        if(cod > 0){
            printf(vermelho "\n\tCódigo inválido, tente novamente ou digite -1 para voltar ao menu" reset);
        }
    } while(cod > 0);

    while(opcao > 0){
        printf("\n\tSelecione qual informação desse voo deseja alterar: ");
        printf("\n\t1. Código");
        printf("\n\t2. Cidade de origem");
        printf("\n\t3. Cidade de destino");
        printf("\n\t4. Escalas");
        printf("\n\t5. Voltar ao menu\n");
        scanf("%d", &opcao);
        fflush(stdin);
        switch(opcao){
            case 1:
                printf("\n\tDigite o novo código: ");
                scanf("%d", &lista[indice].codigo);
                printf(verde "\n\tInformação alterada com sucesso\n" reset);
                break;

            case 2:
                printf("\n\tDigite a nova cidade de origem: ");
                strupr(gets(lista[indice].origem));
                printf(verde "\n\tInformação alterada com sucesso\n" reset);
                break;

            case 3:
                printf("\n\tDigite a nova cidade de destino: ");
                strupr(gets(lista[indice].destino));
                printf(verde "\n\tInformação alterada com sucesso\n" reset);
                break;

            case 4:
                printf("\n\tDigite o novo número de escalas: ");
                scanf("%d", &lista[indice].numEscalas);
                while(lista[indice].numEscalas > nEscalas){
                    printf(vermelho "\n\n\tNúmero de escalas inválido, digite novamente: " reset);
                    scanf("%d", &lista[indice].numEscalas);
                }

                for(i = 0; i < lista[indice].numEscalas; i++){
                    fflush(stdin);
                    printf("\n\tDigite a cidade de parada número %d: ", i+1);
                    strupr(gets(lista[indice].escalas[i]));
                }
                printf(verde "\n\tInformação alterada com sucesso\n\n" reset);
                break;

            case 5:
                opcao = -1;
                break;

            default:
                printf(vermelho "\n\n\tNúmero inválido, aperte enter para continuar" reset);
                getchar();
                break;
        }
    }
    printf(verde "\n\n\tPressione enter para retornar ao menu principal" reset);
    fflush(stdin);
    getchar();
}

void apagar_voo(voo lista[]){
    int cod, nEncontrado = 1;
    printf("\n\tDigite o código do voo que deseja apagar: ");
    scanf("%d", &cod);
    fflush(stdin);
    for(int i = 0; i < numVoos; i++){
        if(lista[i].codigo == cod){
            lista[i].codigo = 0;
            printf(verde "\n\tVoo apagado com sucesso.\n" reset);
            nEncontrado = 0;
        }
    }

    if(nEncontrado){
        printf(vermelho "\n\tVoo de código %d, não foi encontrado\n" reset);
    }

    printf("\n\n\t\tPressione ENTER para retornar ao menu principal");
    getchar();
}

void voos_por_origem(voo lista[]){
    int i, x = 0;
    char origem[30];
    fflush(stdin);
    printf("\n\tDigite a cidade origem: ");
    strupr(gets(origem));
    for(i = 0; i < numVoos; i++){
        if(strcmp(origem, lista[i].origem) == 0){
            printf("\n\t O voo %d, vai à cidade %s", lista[i].codigo, lista[i].destino);
            x++;
        }
    }
    printf("\n\n\tUm total de %d voos saem da cidade %s", x, origem);

    printf(verde "\n\n\tPressione enter para retornar ao menu principal\n" reset);
    fflush(stdin);
    getchar();
}

void imprimir_menor_escala(voo lista[]){
    int i, temp = 7, index = 7;
    char orig[30], dest[30];
    fflush(stdin);
    printf("\n\tDigite a cidade de origem: ");
    strupr(gets(orig));
    fflush(stdin);
    printf("\n\tAgora digite a cidade de destino: ");
    strupr(gets(dest));

    for(i = 0; i < numVoos; i++){
        if((strcmp(lista[i].destino, dest) == 0) && (strcmp(lista[i].origem, orig) == 0)){
            if(lista[i].numEscalas < temp){
                temp = lista[i].numEscalas;
                index = i;
            }
        }
    }
    if(temp == 7){
        printf("\n\tNão há nenhum voo que sai de %s e chega em %s", orig, dest);
    }
    else{
        printf("\n\tO voo de código: %d\n\tSai de %s\n\tChega em %s\n\tFaz %d escalas, passando por: ", lista[index].codigo, orig, dest, lista[index].numEscalas);
        for(i = 0; i < lista[index].numEscalas; i++){
            printf("%s, ", lista[index].escalas[i]);
        }
    }
    printf(verde "\n\tPressione enter para retornar ao menu principal" reset);
    fflush(stdin);
    getchar();
}

void voos_por_destino(voo lista[]){
    int i, x = 0;
    char destino[30];
    fflush(stdin);
    printf("\n\tDigite o nome de uma cidade de destino: ");
    strupr(gets(destino));
    for(i = 0; i < numVoos; i++){
        if(strcmp(destino, lista[i].destino) == 0){
            printf("\n\t O voo %d, sai da cidade %s", lista[i].codigo, lista[i].origem);
            x++;
        }
    }
    printf("\n\n\tUm total de %d voos saem da cidade %s", x, destino);
    printf(verde "\n\n\tPressione enter para retornar ao menu principal\n" reset);
    fflush(stdin);
    getchar();
}

void imprimir_todos_voos(voo lista[]){
    printf(ciano "\n\n\t\t\tLISTA COM TODOS OS VOOS\n" reset);
    int i, j;
    for(i = 0; i < numVoos; i++){
        if(lista[i].codigo > 0){
            printf("\n\n\t\t%d. Código do voo: %d", i+1, lista[i].codigo);
            printf("\n\t\t   Esse voo sai de: %s\n\t\t    Com destino a: %s", lista[i].origem, lista[i].destino);
            if(lista[i].numEscalas == 1){
                printf("\n\t\t   Esse voo tem 1 escala, que passa por: %s", lista[i].escalas[0]);
            }
            else if(lista[i].numEscalas > 1){
                printf("\n\t\t   Esse voo tem %d escalas, passando por: ", lista[i].numEscalas);
                for(j = 0; j < lista[i].numEscalas; j++){
                    printf("%s, ", lista[i].escalas[j]);
                }
            }
            else{
                printf("\n\t\t   Esse voo não possui escalas.");
            }
        }
    }
    printf(verde "\n\t Pressione ENTER para voltar ao menu principal " reset);
    getchar();
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    voo lista[numVoos];
    int opcao = 0;
    // Inicializa a lista de voos
    for(int i = 0; i < numVoos; i++){
        lista[i].codigo = 0;
    }

    do {
        printf(ciano "\n\t\t  Sistema de Gerenciamento de Voos" reset);
        printf("\n\t1. Incluir voo");
        printf("\n\t2. Alterar voo");
        printf("\n\t3. Apagar voo");
        printf("\n\t4. Consultar voos por origem");
        printf("\n\t5. Consultar voos por destino");
        printf("\n\t6. Consultar voo com menor número de escalas");
        printf("\n\t7. Imprimir todos os voos");
        printf("\n\t0. Sair\n");
        printf("\n\tEscolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: incluir_voo(lista); break;
            case 2: alterar_voo(lista); break;
            case 3: apagar_voo(lista); break;
            case 4: voos_por_origem(lista); break;
            case 5: voos_por_destino(lista); break;
            case 6: imprimir_menor_escala(lista); break;
            case 7: imprimir_todos_voos(lista); break;
            case 0: break;
            default: printf(vermelho "\nOpção inválida. Tente novamente.\n" reset); break;
        }
    } while(opcao != 0);

    return 0;
}
