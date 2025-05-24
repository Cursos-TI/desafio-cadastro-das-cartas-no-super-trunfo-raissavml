#include <stdio.h>
#include <string.h>


#define NUM_CARDS 6

typedef struct {
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

// Create a card
void createCard(Card deck[], int numCards) { // 1-4
    char state[2];
    char name[50];
    int population;
    float area;
    double gdp;
    int landmark;

    //insert new card data
    printf("Insira o nome do estado (deve ser uma letra de A a H) ");
    scanf(" %49[^\n]", &state);
    printf("Insira o nome da cidade: ");
    scanf(" %49[^\n]", &name);
    printf("Insira o tamanho da população da cidade: ");
    scanf(" %d", &population);
    printf("Insira a área da cidade: ");
    scanf(" %f", &area);
    printf("Insira o PIB da cidade: ");
    scanf(" %lf", &gdp);
    printf("Insira o número de pontos turísticos da cidade: ");
    scanf(" %d[^\n]", &landmark);


    Card newCity;
    strcpy(newCity.city, name);
    sprintf(newCity.id, "%c%02d", state[0], numCards++);
    newCity.population = population;
    newCity.area = area;
    newCity.GDP = gdp;
    newCity.landmark = landmark;
    newCity.popDensity =  (newCity.area > 0) ? (double)newCity.population / newCity.area : 0;
    newCity.GDPPerCapita = (newCity.population > 0) ? (double)newCity.GDP / newCity.population : 0;


    deck[numCards] = newCity;
    (numCards)++;

    printf("%s foi criada com sucesso!\n Confira a nova carta:\n", newCity.city);
    printCard(deck, numCards - 1);
    return;
    
}

//Print card function
void printCard (Card deck[], int cardIndex){
    printf("(%s)\n Estado: %s \n Cidade: %s \n População: %d Habitantes \n Área: %f m² \n PIB: %f moeda local \n Densidade populacional: %f \n PIB per capita: %f moeda local \n Número de pontos turísticos: \n%d\n", 
        deck[cardIndex].id, 
        deck[cardIndex].state, 
        deck[cardIndex].city, 
        deck[cardIndex].population, 
        deck[cardIndex].area, 
        deck[cardIndex].GDP, 
        deck[cardIndex].popDensity, 
        deck[cardIndex].GDPPerCapita, 
        deck[cardIndex].landmark
    );
    return;
}
    
int main() {
    Card deck[NUM_CARDS] = {0};
    int numCards = 0;

    // Create two cards
    createCard(deck, numCards);
    createCard(deck, numCards);
}