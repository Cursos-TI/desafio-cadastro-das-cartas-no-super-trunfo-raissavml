#include <stdio.h>
#include <string.h>

#define NUM_CARDS 6

typedef struct
{
    char state[2];
    char city[50];
    char id[4];
    int population;
    float area;
    double GDP;
    double popDensity;
    double GDPPerCapita;
    int landmark;
} Card;

// Print card function
void printCard(Card deck[], int cardIndex)
{
    printf("(%s)\n Estado: %s \n Cidade: %s \n População: %d Habitantes \n Área: %f m² \n PIB: %f dólares \n Densidade demográfica: %f pessoas por m² \n PIB per capita: %f dólares por pessoa \n Número de pontos turísticos: \n%d\n",
           deck[cardIndex].id,
           deck[cardIndex].state,
           deck[cardIndex].city,
           deck[cardIndex].population,
           deck[cardIndex].area,
           deck[cardIndex].GDP,
           deck[cardIndex].popDensity,
           deck[cardIndex].GDPPerCapita,
           deck[cardIndex].landmark);
    return;
}

// Create a card
void createCard(Card deck[], int *numCards)
{
    char state[2];
    char name[50];
    int population;
    float area;
    double gdp;
    int landmark;

    // insert new card data
    printf("Insira o nome do estado (deve ser uma letra de A a H) ");
    scanf(" %49[^\n]", state);
    printf("Insira o nome da cidade: ");
    scanf(" %49[^\n]", name);
    printf("Insira o tamanho da população da cidade: ");
    scanf(" %d", &population);
    printf("Insira a área da cidade: ");
    scanf(" %f", &area);
    printf("Insira o PIB da cidade: ");
    scanf(" %lf", &gdp);
    printf("Insira o número de pontos turísticos da cidade: ");
    scanf(" %d", &landmark);

    Card newCity;
    strcpy(newCity.city, name);
    int index = *numCards;
    sprintf(newCity.id, "%c%02d", state[0], index);
    newCity.population = population;
    newCity.area = area;
    newCity.GDP = gdp;
    newCity.landmark = landmark;
    newCity.popDensity = (newCity.area > 0) ? (double)newCity.population / newCity.area : 0;
    newCity.GDPPerCapita = (newCity.population > 0) ? (double)newCity.GDP / newCity.population : 0;

    deck[index] = newCity;
    (*numCards)++;

    printf("%s foi criada com sucesso!\n Confira a nova carta:\n", newCity.city);
    printCard(deck, *numCards - 1);
    return;
}

// Choose Attribute function
void chooseAttribute( Card deck[], int *numCards ) 
{
    int attribute;

    printf("Escolha qual atributo será utilizado para comparar as cartas:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Densidade demográfica\n");
    printf("5. PIB per capita\n");
    printf("6. Número de pontos turísticos\n");
    printf("Escolha uma opção digitando o número dela: \n");
    scanf("%d", &attribute);

    switch (attribute)
    {
    case 1:
        // Population
        deck[0].population > deck[1].population ? printf("A cidade %s ganhou, com uma população de %d habitantes, comparada a cidade %s, com uma população de %d habitantes.", deck[0].city, deck[0].population, deck[1].city, deck[1].population) : deck[0].population < deck[1].population ? printf("A cidade %s ganhou, com uma população de %d habitantes, comparada a cidade %s, com uma população de %d habitantes.", deck[1].city, deck[1].population, deck[0].city, deck[0].population) : printf("Empate! As duas cidades apresentam população de %d habitantes", deck[0].population);
        break;
    case 2:
        // Area
        deck[0].area > deck[1].area ? printf("A cidade %s ganhou, com uma área de %f m², comparada a cidade %s, com uma área de %f m².", deck[0].city, deck[0].area, deck[1].city, deck[1].area) : deck[0].area < deck[1].area ? printf("A cidade %s ganhou, com uma área de %f m², comparada a cidade %s, com uma área de %f m².", deck[1].city, deck[1].area, deck[0].city, deck[0].area) : printf("Empate! As duas cidades apresentam área de %f m²", deck[0].area);
        break;
    case 3:
        // GDP
        deck[0].GDP > deck[1].GDP ? printf("A cidade %s ganhou, com um PIB de %f dólares, comparada a cidade %s, com um PIB de %f dólares.", deck[0].city, deck[0].GDP, deck[1].city, deck[1].GDP) : deck[0].GDP < deck[1].GDP ? printf("A cidade %s ganhou, com um PIB de %f dólares, comparada a cidade %s, com um PIB de %f dólares.", deck[1].city, deck[1].GDP, deck[0].city, deck[0].GDP) : printf("Empate! As duas cidades apresentam PIB de %f dólares", deck[0].GDP);
        break;
    case 4:
        // Population density
        deck[0].popDensity < deck[1].popDensity ? printf("A cidade %s ganhou, com densidade demográfica de %f pessoas por m², comparada a cidade %s, com densidade demográfica de %f pessoas por m².", deck[0].city, deck[0].popDensity, deck[1].city, deck[1].popDensity) : deck[0].popDensity > deck[1].popDensity ? printf("A cidade %s ganhou, com densidade demográfica de %f pessoas por m², comparada a cidade %s, com densidade demográfica de %f pessoas por m².", deck[1].city, deck[1].popDensity, deck[0].city, deck[0].popDensity) : printf("Empate! As duas cidades apresentam densidade demográfica de %f pessoas por m²", deck[0].popDensity);
        break;
    case 5:
        // GDP Per Capita
        deck[0].GDPPerCapita > deck[1].GDPPerCapita ? printf("A cidade %s ganhou, com um PIB per capita de %f dólares por pessoa, comparada a cidade %s, com um PIB per capita de %f dólares por pessoa.", deck[0].city, deck[0].GDPPerCapita, deck[1].city, deck[1].GDPPerCapita) : deck[0].GDPPerCapita < deck[1].GDPPerCapita ? printf("A cidade %s ganhou, com um PIB per capita de %f dólares por pessoa, comparada a cidade %s, com um PIB per capita de %f dólares por pessoa.", deck[1].city, deck[1].GDPPerCapita, deck[0].city, deck[0].GDPPerCapita) : printf("Empate! As duas cidades apresentam PIB per capita de %f dólares por pessoa", deck[0].GDPPerCapita);
        break;
    case 6:
        // Total Landmarks
        deck[0].landmark > deck[1].landmark ? printf("A cidade %s ganhou, com um total de %d pontos turísticos, comparada a cidade %s, com um total de %d pontos turísticos.", deck[0].city, deck[0].landmark, deck[1].city, deck[1].landmark) : deck[0].landmark < deck[1].landmark ? printf("A cidade %s ganhou, com um total de %d pontos turísticos, comparada a cidade %s, com um total de %d pontos turísticos.", deck[1].city, deck[1].landmark, deck[0].city, deck[0].landmark) : printf("Empate! As duas cidades apresentam total de %d pontos turísticos", deck[0].landmark);
        break;
    default:
        printf("Opção inválida, tente novamente.\n");
        chooseAttribute(deck, numCards);
    }
}

// Play game function
void playGame(Card deck[], int *numCards)
{
    printf("Vamos começar!\n Primeiro jogador, crie sua carta:\n");
    createCard(deck, numCards);
    printf("Segundo jogador, crie sua carta:\n");
    createCard(deck, numCards);
    chooseAttribute(deck, numCards);
}

// Menu Function
void menu(Card deck[], int *numCards) 
{
    int option;

    printf("Menu Principal\n");
    printf("1. Ver as regras\n");
    printf("2. Iniciar o jogo\n");
    printf("3. Sair\n");
    printf("Escolha uma opção digitando o número: \n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        // Rulles
    printf("Cada usuário deverá criar uma carta,\n preenchendo os dados dos atributos solicitados.\n Depois, um atributo deve ser escolhido para comparar as duas cartas. \n Ao final, será dito qual é a carta vencedora!");
    printf("Vamos começar o jogo!\n");
    playGame(deck, numCards);

    break;
    case 2:
        // Play
        printf("Vamos começar o jogo!\n");
        playGame(deck, numCards);
        break;
    case 3:
        // End game
        char saida;
        printf("Já vai? Digite s para sim e n para não.");
        scanf("%c", &saida);
        (saida == 'n' || saida == 'N') ? playGame(deck, numCards) : printf("Foi bom te ter por aqui! Volte logo!");
        break;
    default:
        printf("Opção inválida, tente novamente.\n");
        menu(deck, numCards);
    }
}

int main()
{
    Card deck[NUM_CARDS] = {0};
    int numCards = 0;

    menu(deck, &numCards);
}