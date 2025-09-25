#include <stdio.h>
#include <string.h>

// Função para limpar o buffer do teclado após scanf
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Estrutura para armazenar os dados da carta
struct Carta {
    char estado[3];            // Ex: "SP"
    char codigo[5];            // Ex: "A01"
    char nomeCidade[50];       // Nome da cidade
    int populacao;             // População total
    float pib;                 // Produto Interno Bruto (em bilhões, por ex.)
    float area;                // Área em km²
    int pontosTuristicos;      // Quantidade de pontos turísticos
    float densidade;           // População / Área
    float pibPerCapita;        // PIB / População
};

int main() {
    struct Carta carta;

    printf("=== Cadastro de Carta Super Trunfo ===\n\n");

    printf("Digite o estado (ex: SP): ");
    scanf("%2s", carta.estado);
    limparBuffer();

    printf("Digite o código da carta (ex: A01): ");
    scanf("%4s", carta.codigo);
    limparBuffer();

    printf("Digite o nome da cidade: ");
    fgets(carta.nomeCidade, 50, stdin);
    carta.nomeCidade[strcspn(carta.nomeCidade, "\n")] = '\0'; // remove quebra de linha

    printf("Digite a populacao da cidade: ");
    scanf("%d", &carta.populacao);
    limparBuffer();

    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%f", &carta.pib);
    limparBuffer();

    printf("Digite a area da cidade (em km²): ");
    scanf("%f", &carta.area);
    limparBuffer();

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta.pontosTuristicos);
    limparBuffer();

    // Cálculos derivados
    carta.densidade = carta.populacao / carta.area;
    carta.pibPerCapita = (carta.pib * 1000000000) / carta.populacao; // convertendo PIB para unidades

    // Exibindo os dados
    printf("\n=== Carta Registrada ===\n");
    printf("Estado: %s\n", carta.estado);
    printf("Codigo: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.nomeCidade);
    printf("Populacao: %d habitantes\n", carta.populacao);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Area: %.2f km²\n", carta.area);
    printf("Pontos Turisticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade);
    printf("PIB per Capita: %.2f R$/habitante\n", carta.pibPerCapita);

    return 0;
}
