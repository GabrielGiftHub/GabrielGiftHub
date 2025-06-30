#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estrutura para armazenar as informações das cartas de países
typedef struct {
    char nome[50];
    int populacao;              // em milhões
    float area;                 // em mil km²
    float pib;                  // em trilhões de dólares
    float idh;                  // índice de 0 a 1
    float densidadeDemografica; // habitantes por km²
} Carta;

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para exibir o menu de escolha de atributos
int exibirMenuAtributos(int atributoExcluido) {
    int opcao;
    
    printf("\n=== ESCOLHA UM ATRIBUTO ===\n");
    
    // Exibe apenas as opções que não foram escolhidas anteriormente
    if (atributoExcluido != 1)
        printf("1. População\n");
    if (atributoExcluido != 2)
        printf("2. Área\n");
    if (atributoExcluido != 3)
        printf("3. PIB\n");
    if (atributoExcluido != 4)
        printf("4. IDH\n");
    if (atributoExcluido != 5)
        printf("5. Densidade Demográfica\n");
    
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    limparBuffer();
    
    // Verifica se a opção escolhida é válida e não é a mesma que já foi escolhida
    if (opcao < 1 || opcao > 5 || opcao == atributoExcluido) {
        printf("Opção inválida ou já escolhida. Tente novamente.\n");
        return exibirMenuAtributos(atributoExcluido);
    }
    
    return opcao;
}

// Função para obter o nome do atributo com base no código
const char* obterNomeAtributo(int codigo) {
    switch (codigo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "IDH";
        case 5: return "Densidade Demográfica";
        default: return "Atributo desconhecido";
    }
}

// Função para obter o valor do atributo com base no código
float obterValorAtributo(Carta carta, int codigo) {
    switch (codigo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.idh;
        case 5: return carta.densidadeDemografica;
        default: return 0;
    }
}

// Função para comparar um atributo específico entre duas cartas
// Retorna 1 se carta1 vence, -1 se carta2 vence, 0 se empate
int compararAtributo(Carta carta1, Carta carta2, int codigoAtributo) {
    float valor1 = obterValorAtributo(carta1, codigoAtributo);
    float valor2 = obterValorAtributo(carta2, codigoAtributo);
    
    // Para densidade demográfica, menor valor vence
    if (codigoAtributo == 5) {
        return valor1 < valor2 ? 1 : (valor1 > valor2 ? -1 : 0);
    } 
    // Para os demais atributos, maior valor vence
    else {
        return valor1 > valor2 ? 1 : (valor1 < valor2 ? -1 : 0);
    }
}

// Função para exibir o resultado da comparação
void exibirResultado(Carta carta1, Carta carta2, int atributo1, int atributo2) {
    float valor1Atrib1 = obterValorAtributo(carta1, atributo1);
    float valor2Atrib1 = obterValorAtributo(carta2, atributo1);
    float valor1Atrib2 = obterValorAtributo(carta1, atributo2);
    float valor2Atrib2 = obterValorAtributo(carta2, atributo2);
    
    // Resultados das comparações individuais
    int resultado1 = compararAtributo(carta1, carta2, atributo1);
    int resultado2 = compararAtributo(carta1, carta2, atributo2);
    
    // Calcula a soma dos atributos para cada carta
    float soma1 = valor1Atrib1 + valor1Atrib2;
    float soma2 = valor2Atrib1 + valor2Atrib2;
    
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n\n");
    
    // Exibe os países e os valores dos atributos
    printf("País 1: %s\n", carta1.nome);
    printf("- %s: %.2f\n", obterNomeAtributo(atributo1), valor1Atrib1);
    printf("- %s: %.2f\n", obterNomeAtributo(atributo2), valor1Atrib2);
    printf("- Soma dos atributos: %.2f\n\n", soma1);
    
    printf("País 2: %s\n", carta2.nome);
    printf("- %s: %.2f\n", obterNomeAtributo(atributo1), valor2Atrib1);
    printf("- %s: %.2f\n", obterNomeAtributo(atributo2), valor2Atrib2);
    printf("- Soma dos atributos: %.2f\n\n", soma2);
    
    // Exibe o resultado de cada comparação individual
    printf("Comparação de %s: ", obterNomeAtributo(atributo1));
    if (resultado1 == 1) {
        printf("%s vence\n", carta1.nome);
    } else if (resultado1 == -1) {
        printf("%s vence\n", carta2.nome);
    } else {
        printf("Empate\n");
    }
    
    printf("Comparação de %s: ", obterNomeAtributo(atributo2));
    if (resultado2 == 1) {
        printf("%s vence\n", carta2.nome);
    } else if (resultado2 == -1) {
        printf("%s vence\n", carta2.nome);
    } else {
        printf("Empate\n");
    }
    
    // Exibe o resultado final baseado na soma dos atributos
    printf("\nRESULTADO FINAL: ");
    if (soma1 > soma2) {
        printf("%s VENCE com %.2f pontos contra %.2f pontos!\n", carta1.nome, soma1, soma2);
    } else if (soma1 < soma2) {
        printf("%s VENCE com %.2f pontos contra %.2f pontos!\n", carta2.nome, soma2, soma1);
    } else {
        printf("EMPATE! Ambos os países têm %.2f pontos.\n", soma1);
    }
}

// Função principal
int main() {
    // Pré-cadastro de cartas de países
    Carta cartas[5] = {
        {"Brasil", 212, 8516.0, 1.87, 0.765, 24.9},
        {"Estados Unidos", 331, 9834.0, 21.5, 0.926, 33.6},
        {"China", 1402, 9597.0, 14.72, 0.761, 146.1},
        {"Índia", 1366, 3287.0, 2.87, 0.645, 415.7},
        {"Rússia", 144, 17125.0, 1.64, 0.824, 8.4}
    };
    
    printf("=== SUPER TRUNFO DE PAÍSES - VERSÃO AVANÇADA ===\n\n");
    
    // Exibe as cartas disponíveis
    printf("Cartas disponíveis:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, cartas[i].nome);
    }
    
    // Seleção das cartas
    int escolha1, escolha2;
    
    printf("\nEscolha a primeira carta (1-5): ");
    scanf("%d", &escolha1);
    limparBuffer();
    
    if (escolha1 < 1 || escolha1 > 5) {
        printf("Opção inválida. O programa será encerrado.\n");
        return 1;
    }
    
    printf("Escolha a segunda carta (1-5): ");
    scanf("%d", &escolha2);
    limparBuffer();
    
    if (escolha2 < 1 || escolha2 > 5 || escolha2 == escolha1) {
        printf("Opção inválida ou igual à primeira escolha. O programa será encerrado.\n");
        return 1;
    }
    
    // Ajusta os índices
    Carta carta1 = cartas[escolha1 - 1];
    Carta carta2 = cartas[escolha2 - 1];
    
    printf("\nVocê escolheu %s vs %s!\n", carta1.nome, carta2.nome);
    
    // Escolha do primeiro atributo
    printf("\nAgora, escolha dois atributos diferentes para comparar:\n");
    int atributo1 = exibirMenuAtributos(0); // 0 indica que nenhum atributo foi excluído ainda
    
    // Escolha do segundo atributo (excluindo o primeiro)
    int atributo2 = exibirMenuAtributos(atributo1);
    
    printf("\nVocê escolheu comparar os atributos: %s e %s\n", 
           obterNomeAtributo(atributo1), obterNomeAtributo(atributo2));
    
    // Exibe o resultado da comparação
    exibirResultado(carta1, carta2, atributo1, atributo2);
    
    return 0;
}