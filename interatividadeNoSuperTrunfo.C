#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Carta
struct Carta {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para comparar cartas
void compararCartas(struct Carta carta1, struct Carta carta2) {
    int opcao;
    
    do {
        printf("\n=== Menu de Comparação ===\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("6 - Sair\n");
        printf("Escolha o atributo para comparação: ");
        
        if (scanf("%d", &opcao) != 1) { // Validação da entrada
            printf("Entrada inválida! Tente novamente.\n");
            limparBuffer();
            continue;
        }
        
        switch(opcao) {
            case 1: // População
                printf("\nComparando população:\n");
                printf("%s: %d habitantes\n", carta1.nome, carta1.populacao);
                printf("%s: %d habitantes\n", carta2.nome, carta2.populacao);
                
                if (carta1.populacao > carta2.populacao) {
                    printf("%s venceu!\n", carta1.nome);
                } else if (carta2.populacao > carta1.populacao) {
                    printf("%s venceu!\n", carta2.nome);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 2: // Área
                printf("\nComparando área:\n");
                printf("%s: %.2f km²\n", carta1.nome, carta1.area);
                printf("%s: %.2f km²\n", carta2.nome, carta2.area);
                
                if (carta1.area > carta2.area) {
                    printf("%s venceu!\n", carta1.nome);
                } else if (carta2.area > carta1.area) {
                    printf("%s venceu!\n", carta2.nome);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 3: // PIB
                printf("\nComparando PIB:\n");
                printf("%s: %.2f bilhões\n", carta1.nome, carta1.pib);
                printf("%s: %.2f bilhões\n", carta2.nome, carta2.pib);
                
                if (carta1.pib > carta2.pib) {
                    printf("%s venceu!\n", carta1.nome);
                } else if (carta2.pib > carta1.pib) {
                    printf("%s venceu!\n", carta2.nome);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 4: // Pontos Turísticos
                printf("\nComparando pontos turísticos:\n");
                printf("%s: %d pontos\n", carta1.nome, carta1.pontosTuristicos);
                printf("%s: %d pontos\n", carta2.nome, carta2.pontosTuristicos);
                
                if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                    printf("%s venceu!\n", carta1.nome);
                } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                    printf("%s venceu!\n", carta2.nome);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 5: // Densidade Demográfica (regra invertida)
                printf("\nComparando densidade demográfica:\n");
                printf("%s: %.2f hab/km²\n", carta1.nome, carta1.densidadeDemografica);
                printf("%s: %.2f hab/km²\n", carta2.nome, carta2.densidadeDemografica);
                
                if (carta1.densidadeDemografica < carta2.densidadeDemografica) {
                    printf("%s venceu!\n", carta1.nome);
                } else if (carta2.densidadeDemografica < carta1.densidadeDemografica) {
                    printf("%s venceu!\n", carta2.nome);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 6: // Sair
                printf("Saindo do jogo...\n");
                break;
                
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 6); // Condição de saída corrigida

    printf("Jogo encerrado. Obrigado por jogar!\n"); // Mensagem final
}

// Função principal para teste
int main() {
    struct Carta carta1 = {"Cidade A", 1000000, 500.5, 200.0, 10, 2000.0};
    struct Carta carta2 = {"Cidade B", 800000, 600.0, 250.0, 15, 1500.0};
    
    compararCartas(carta1, carta2);
    return 0;
}