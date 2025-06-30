/**
 * Jogo de Batalha Naval com Habilidades Especiais
 * 
 * Este programa implementa um jogo de Batalha Naval com habilidades especiais
 * que têm diferentes áreas de efeito (Cone, Cruz e Octaedro).
 * 
 * O tabuleiro é representado por uma matriz 10x10, onde:
 * - 0 representa água
 * - 3 representa navios
 * - 5 representa áreas afetadas por habilidades
 */

 #include <stdio.h>
 #include <stdlib.h>
 
 /* ===== DEFINIÇÕES E CONSTANTES ===== */
 
 // Dimensões do tabuleiro e das matrizes de habilidade
 #define TAMANHO_TABULEIRO 10
 #define TAMANHO_HABILIDADE 5 // Tamanho das matrizes de habilidade (5x5)
 
 // Valores para representação visual
 #define AGUA 0
 #define NAVIO 3
 #define AREA_HABILIDADE 5
 
 /* ===== PROTÓTIPOS DAS FUNÇÕES ===== */
 
 // Funções de inicialização e exibição
 void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
 void posicionarNavios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
 void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
 void exibirMatrizHabilidade(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);
 
 // Funções para criação das matrizes de habilidade
 void criarMatrizCone(int matrizCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);
 void criarMatrizCruz(int matrizCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);
 void criarMatrizOctaedro(int matrizOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);
 
 // Função para aplicar habilidade ao tabuleiro
 void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                        int matrizHabilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], 
                        int linhaOrigem, int colunaOrigem);
 
 /* ===== FUNÇÃO PRINCIPAL ===== */
 
 int main() {
     // Declaração de variáveis
     int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
     int matrizCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
     int matrizCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
     int matrizOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
     int linhaOrigem, colunaOrigem;
     int opcaoHabilidade;
     
     // ===== INICIALIZAÇÃO DO JOGO =====
     
     // Inicializa o tabuleiro e posiciona os navios
     inicializarTabuleiro(tabuleiro);
     posicionarNavios(tabuleiro);
     
     printf("\n=== BATALHA NAVAL COM HABILIDADES ESPECIAIS ===\n\n");
     
     printf("Tabuleiro inicial:\n");
     exibirTabuleiro(tabuleiro);
     
     // ===== CRIAÇÃO DAS MATRIZES DE HABILIDADE =====
     
     // Cria as matrizes de habilidade
     criarMatrizCone(matrizCone);
     criarMatrizCruz(matrizCruz);
     criarMatrizOctaedro(matrizOctaedro);
     
     // Exibe as matrizes de habilidade
     printf("\n=== MATRIZES DE HABILIDADE ===\n");
     
     printf("\nMatriz de habilidade - Cone:\n");
     exibirMatrizHabilidade(matrizCone);
     
     printf("\nMatriz de habilidade - Cruz:\n");
     exibirMatrizHabilidade(matrizCruz);
     
     printf("\nMatriz de habilidade - Octaedro:\n");
     exibirMatrizHabilidade(matrizOctaedro);
     
     // ===== INTERAÇÃO COM O USUÁRIO =====
     
     // Solicita ao usuário a escolha da habilidade e o ponto de origem
     printf("\n=== APLICAÇÃO DE HABILIDADE ===\n");
     printf("\nEscolha uma habilidade para aplicar:\n");
     printf("1 - Cone\n");
     printf("2 - Cruz\n");
     printf("3 - Octaedro\n");
     printf("Opção: ");
     scanf("%d", &opcaoHabilidade);
     
     printf("\nInforme o ponto de origem (linha e coluna entre 0 e %d): ", TAMANHO_TABULEIRO - 1);
     scanf("%d %d", &linhaOrigem, &colunaOrigem);
     
     // Verifica se o ponto de origem está dentro dos limites do tabuleiro
     if (linhaOrigem < 0 || linhaOrigem >= TAMANHO_TABULEIRO || 
         colunaOrigem < 0 || colunaOrigem >= TAMANHO_TABULEIRO) {
         printf("\nERRO: Coordenadas inválidas! Encerrando o programa.\n");
         return 1;
     }
     
     // ===== APLICAÇÃO DA HABILIDADE =====
     
     // Aplica a habilidade escolhida ao tabuleiro
     switch (opcaoHabilidade) {
         case 1:
             aplicarHabilidade(tabuleiro, matrizCone, linhaOrigem, colunaOrigem);
             printf("\nTabuleiro após aplicar a habilidade CONE:\n");
             break;
         case 2:
             aplicarHabilidade(tabuleiro, matrizCruz, linhaOrigem, colunaOrigem);
             printf("\nTabuleiro após aplicar a habilidade CRUZ:\n");
             break;
         case 3:
             aplicarHabilidade(tabuleiro, matrizOctaedro, linhaOrigem, colunaOrigem);
             printf("\nTabuleiro após aplicar a habilidade OCTAEDRO:\n");
             break;
         default:
             printf("\nERRO: Opção inválida! Encerrando o programa.\n");
             return 1;
     }
     
     // Exibe o tabuleiro com a habilidade aplicada
     exibirTabuleiro(tabuleiro);
     
     printf("\n=== FIM DO PROGRAMA ===\n");
     
     return 0;
 }
 
 /* ===== IMPLEMENTAÇÃO DAS FUNÇÕES ===== */
 
 /**
  * Inicializa o tabuleiro com água (valor 0)
  * 
  * @param tabuleiro Matriz do tabuleiro a ser inicializada
  */
 void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
     int i, j;
     
     for (i = 0; i < TAMANHO_TABULEIRO; i++) {
         for (j = 0; j < TAMANHO_TABULEIRO; j++) {
             tabuleiro[i][j] = AGUA;
         }
     }
 }
 
 /**
  * Posiciona alguns navios no tabuleiro para exemplo
  * Em um jogo real, esta função seria mais elaborada
  * 
  * @param tabuleiro Matriz do tabuleiro onde os navios serão posicionados
  */
 void posicionarNavios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
     // Posiciona um navio horizontal de tamanho 3
     tabuleiro[1][1] = NAVIO;
     tabuleiro[1][2] = NAVIO;
     tabuleiro[1][3] = NAVIO;
     
     // Posiciona um navio vertical de tamanho 2
     tabuleiro[3][5] = NAVIO;
     tabuleiro[4][5] = NAVIO;
     
     // Posiciona um navio vertical de tamanho 4
     tabuleiro[6][8] = NAVIO;
     tabuleiro[7][8] = NAVIO;
     tabuleiro[8][8] = NAVIO;
     tabuleiro[9][8] = NAVIO;
     
     // Posiciona um navio horizontal de tamanho 3
     tabuleiro[5][2] = NAVIO;
     tabuleiro[5][3] = NAVIO;
     tabuleiro[5][4] = NAVIO;
 }
 
 /**
  * Cria a matriz de habilidade do Cone
  * O cone aponta para baixo, com o topo na parte superior
  * e expandindo-se para a base
  * 
  * @param matrizCone Matriz onde será construída a habilidade cone
  */
 void criarMatrizCone(int matrizCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
     int i, j;
     
     // Inicializa a matriz com zeros
     for (i = 0; i < TAMANHO_HABILIDADE; i++) {
         for (j = 0; j < TAMANHO_HABILIDADE; j++) {
             matrizCone[i][j] = 0;
         }
     }
     
     // Define o centro da matriz para posicionar o cone
     int centro = TAMANHO_HABILIDADE / 2;
     
     // Para cada linha, a largura do cone aumenta
     for (i = 0; i < TAMANHO_HABILIDADE; i++) {
         // A largura do cone em cada linha é proporcional à distância do topo
         int largura = i + 1;
         
         // Ajusta a posição inicial em cada linha para centralizar o cone
         int inicio = centro - largura / 2;
         
         // Define as posições afetadas na linha atual
         for (j = 0; j < largura && j + inicio < TAMANHO_HABILIDADE; j++) {
             if (inicio + j >= 0) {
                 matrizCone[i][inicio + j] = 1;
             }
         }
     }
 }
 
 /**
  * Cria a matriz de habilidade da Cruz
  * A cruz tem o ponto de origem no centro
  * 
  * @param matrizCruz Matriz onde será construída a habilidade cruz
  */
 void criarMatrizCruz(int matrizCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
     int i, j;
     
     // Inicializa a matriz com zeros
     for (i = 0; i < TAMANHO_HABILIDADE; i++) {
         for (j = 0; j < TAMANHO_HABILIDADE; j++) {
             matrizCruz[i][j] = 0;
         }
     }
     
     // Define o centro da matriz para posicionar a cruz
     int centro = TAMANHO_HABILIDADE / 2;
     
     // Define a linha horizontal da cruz
     for (j = 0; j < TAMANHO_HABILIDADE; j++) {
         matrizCruz[centro][j] = 1;
     }
     
     // Define a linha vertical da cruz
     for (i = 0; i < TAMANHO_HABILIDADE; i++) {
         matrizCruz[i][centro] = 1;
     }
 }
 
 /**
  * Cria a matriz de habilidade do Octaedro (losango)
  * O octaedro tem o ponto de origem no centro
  * 
  * @param matrizOctaedro Matriz onde será construída a habilidade octaedro
  */
 void criarMatrizOctaedro(int matrizOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
     int i, j;
     
     // Inicializa a matriz com zeros
     for (i = 0; i < TAMANHO_HABILIDADE; i++) {
         for (j = 0; j < TAMANHO_HABILIDADE; j++) {
             matrizOctaedro[i][j] = 0;
         }
     }
     
     // Define o centro e o raio do losango
     int centro = TAMANHO_HABILIDADE / 2;
     int raio = TAMANHO_HABILIDADE / 2;
     
     // Para cada posição na matriz, verifica se está dentro do losango
     for (i = 0; i < TAMANHO_HABILIDADE; i++) {
         for (j = 0; j < TAMANHO_HABILIDADE; j++) {
             // Calcula a distância Manhattan do centro
             // A distância Manhattan é |x1 - x2| + |y1 - y2|
             int distancia = abs(i - centro) + abs(j - centro);
             
             // Se a distância for menor ou igual ao raio, a posição está dentro do losango
             if (distancia <= raio) {
                 matrizOctaedro[i][j] = 1;
             }
         }
     }
 }
 
 /**
  * Aplica a matriz de habilidade ao tabuleiro a partir do ponto de origem
  * 
  * @param tabuleiro Matriz do tabuleiro do jogo
  * @param matrizHabilidade Matriz da habilidade a ser aplicada
  * @param linhaOrigem Linha do ponto de origem no tabuleiro
  * @param colunaOrigem Coluna do ponto de origem no tabuleiro
  */
 void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                       int matrizHabilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], 
                       int linhaOrigem, int colunaOrigem) {
     int i, j;
     int linhaTab, colunaTab;
     
     // Calcula o deslocamento para centralizar a matriz de habilidade no ponto de origem
     int deslocamentoLinha = TAMANHO_HABILIDADE / 2;
     int deslocamentoColuna = TAMANHO_HABILIDADE / 2;
     
     // Percorre a matriz de habilidade
     for (i = 0; i < TAMANHO_HABILIDADE; i++) {
         for (j = 0; j < TAMANHO_HABILIDADE; j++) {
             // Calcula a posição correspondente no tabuleiro
             linhaTab = linhaOrigem + (i - deslocamentoLinha);
             colunaTab = colunaOrigem + (j - deslocamentoColuna);
             
             // Verifica se a posição está dentro dos limites do tabuleiro
             if (linhaTab >= 0 && linhaTab < TAMANHO_TABULEIRO && 
                 colunaTab >= 0 && colunaTab < TAMANHO_TABULEIRO) {
                 
                 // Se a posição na matriz de habilidade for 1 (afetada), marca no tabuleiro
                 if (matrizHabilidade[i][j] == 1) {
                     // Marca como área afetada pela habilidade apenas se não for um navio
                     if (tabuleiro[linhaTab][colunaTab] != NAVIO) {
                         tabuleiro[linhaTab][colunaTab] = AREA_HABILIDADE;
                     }
                 }
             }
         }
     }
 }
 
 /**
  * Exibe o tabuleiro no console
  * 
  * @param tabuleiro Matriz do tabuleiro a ser exibida
  */
 void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
     int i, j;
     
     // Exibe os índices das colunas
     printf("    ");
     for (j = 0; j < TAMANHO_TABULEIRO; j++) {
         printf("%2d ", j);
     }
     printf("\n");
     
     // Linha separadora
     printf("   +");
     for (j = 0; j < TAMANHO_TABULEIRO; j++) {
         printf("---");
     }
     printf("+\n");
     
     // Exibe o conteúdo do tabuleiro com índices de linha
     for (i = 0; i < TAMANHO_TABULEIRO; i++) {
         printf("%2d |", i);
         for (j = 0; j < TAMANHO_TABULEIRO; j++) {
             printf(" %d ", tabuleiro[i][j]);
         }
         printf("|\n");
     }
     
     // Linha separadora
     printf("   +");
     for (j = 0; j < TAMANHO_TABULEIRO; j++) {
         printf("---");
     }
     printf("+\n");
     
     // Legenda
     printf("\nLegenda: %d - Água | %d - Navio | %d - Área afetada pela habilidade\n", 
            AGUA, NAVIO, AREA_HABILIDADE);
 }
 
 /**
  * Exibe uma matriz de habilidade no console
  * 
  * @param matriz Matriz de habilidade a ser exibida
  */
 void exibirMatrizHabilidade(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
     int i, j;
     
     // Exibe o cabeçalho
     printf("  +");
     for (j = 0; j < TAMANHO_HABILIDADE; j++) {
         printf("---");
     }
     printf("+\n");
     
     // Exibe o conteúdo da matriz de habilidade
     for (i = 0; i < TAMANHO_HABILIDADE; i++) {
         printf("  |");
         for (j = 0; j < TAMANHO_HABILIDADE; j++) {
             // Substitui o valor 1 por 3 para visualização da área afetada
             if (matriz[i][j] == 1) {
                 printf(" 3 ");
             } else {
                 printf(" 0 ");
             }
         }
         printf("|\n");
     }
     
     // Exibe o rodapé
     printf("  +");
     for (j = 0; j < TAMANHO_HABILIDADE; j++) {
         printf("---");
     }
     printf("+\n");
 }