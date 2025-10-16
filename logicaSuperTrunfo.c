#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Estrutura simples das cartas
    char pais1[20] = "Brasil";
    char pais2[20] = "Japao";

    // Atributos das cartas
    float populacao1 = 213.3, populacao2 = 125.8;
    float area1 = 8516.0, area2 = 377.9;
    float pib1 = 2.05, pib2 = 5.0;
    float densidade1 = 25.1, densidade2 = 334.0;

    int opcao1, opcao2;
    float valor1A, valor2A, valor1B, valor2B;
    float soma1, soma2;

    printf("=== SUPER TRUNFO - DESAFIO FINAL ===\n");
    printf("Carta 1: %s\nCarta 2: %s\n\n", pais1, pais2);

    // Mostra menu para escolher o primeiro atributo
    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Demografica\n");
    printf("Opcao: ");
    scanf("%d", &opcao1);

    // Verifica se a escolha é válida
    if (opcao1 < 1 || opcao1 > 4) {
        printf("Opcao invalida!\n");
        return 0;
    }

    // Menu do segundo atributo (não pode repetir o primeiro)
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    if (opcao1 != 1) printf("1 - Populacao\n");
    if (opcao1 != 2) printf("2 - Area\n");
    if (opcao1 != 3) printf("3 - PIB\n");
    if (opcao1 != 4) printf("4 - Densidade Demografica\n");
    printf("Opcao: ");
    scanf("%d", &opcao2);

    if (opcao2 < 1 || opcao2 > 4 || opcao2 == opcao1) {
        printf("Opcao invalida!\n");
        return 0;
    }

    // Atribui os valores do primeiro atributo
    if (opcao1 == 1) { valor1A = populacao1; valor2A = populacao2; }
    if (opcao1 == 2) { valor1A = area1; valor2A = area2; }
    if (opcao1 == 3) { valor1A = pib1; valor2A = pib2; }
    if (opcao1 == 4) { valor1A = densidade1; valor2A = densidade2; }

    // Atribui os valores do segundo atributo
    if (opcao2 == 1) { valor1B = populacao1; valor2B = populacao2; }
    if (opcao2 == 2) { valor1B = area1; valor2B = area2; }
    if (opcao2 == 3) { valor1B = pib1; valor2B = pib2; }
    if (opcao2 == 4) { valor1B = densidade1; valor2B = densidade2; }

    // Calcula soma dos dois atributos
    soma1 = valor1A + valor1B;
    soma2 = valor2A + valor2B;

    // Mostra os valores
    printf("\n=== RESULTADOS ===\n");
    printf("Atributo 1 (opcao %d): %s = %.2f | %s = %.2f\n", opcao1, pais1, valor1A, pais2, valor2A);
    printf("Atributo 2 (opcao %d): %s = %.2f | %s = %.2f\n", opcao2, pais1, valor1B, pais2, valor2B);

    printf("\nSoma dos atributos:\n");
    printf("%s = %.2f\n%s = %.2f\n", pais1, soma1, pais2, soma2);

    // Exceção: densidade menor é melhor
    if (opcao1 == 4) {
        if (valor1A < valor2A) printf("\n%s vence no primeiro atributo (menor densidade)\n", pais1);
        else if (valor2A < valor1A) printf("\n%s vence no primeiro atributo (menor densidade)\n", pais2);
        else printf("\nEmpate no primeiro atributo!\n");
    } else {
        if (valor1A > valor2A) printf("\n%s vence no primeiro atributo\n", pais1);
        else if (valor2A > valor1A) printf("\n%s vence no primeiro atributo\n", pais2);
        else printf("\nEmpate no primeiro atributo!\n");
    }

    if (opcao2 == 4) {
        if (valor1B < valor2B) printf("%s vence no segundo atributo (menor densidade)\n", pais1);
        else if (valor2B < valor1B) printf("%s vence no segundo atributo (menor densidade)\n", pais2);
        else printf("Empate no segundo atributo!\n");
    } else {
        if (valor1B > valor2B) printf("%s vence no segundo atributo\n", pais1);
        else if (valor2B > valor1B) printf("%s vence no segundo atributo\n", pais2);
        else printf("Empate no segundo atributo!\n");
    }

    // Decide o vencedor pela soma
    if (soma1 > soma2) printf("\n>>> %s venceu a rodada!\n", pais1);
    else if (soma2 > soma1) printf("\n>>> %s venceu a rodada!\n", pais2);
    else printf("\n>>> Empate!\n");

    return 0;
}
