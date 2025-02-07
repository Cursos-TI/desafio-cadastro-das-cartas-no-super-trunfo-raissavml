#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

// Defining number of countries, states and cities
#define NUM_STATES 8
#define NUM_CITIES 4
#define NUM_COUNTRIES 5
#define NUM_LANDMARKS 3

// Defining structures
typedef struct {
    char city[50];
    char id[4];
    int population;
    int area;
    int GDP;
    double popDensity;
    double GDPPerCapita;
    char landmarks[300];
} Card;

typedef struct {
    char state[50];
    int countryId;
    char id;
    Card cities[NUM_CITIES];
} State;

typedef struct {
    char country[50];
    int id;
    State states[NUM_STATES];
} Country;

// Create a state
void createState(Country deck[], int countryId, int *numStates) {
    int numCities = 0;
    char *stateIds[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int countryIndex = -1;
    for (int i = 0; i < NUM_COUNTRIES; i++) {
        if (deck[i].id == countryId) {
            countryIndex = i;
            break;
        }
    }

    if (countryIndex == -1) {
        printf("País com ID %d não encontrado!\n", countryId);
        return;
    }

    if (*numStates >= NUM_STATES) {
        printf("O limite de estados foi atingido para este país!\n");
        return;
    }

    char name[50];
    printf("Insira o nome do estado: ");
    scanf(" %49[^\n]", name);

    for (int i = 0; i < *numStates; i++) {
        if (strcmp(deck[countryIndex].states[i].state, name) == 0) {
            printf("O estado %s já está cadastrado neste país!\n", name);
                        for (int j = 0; j < NUM_CITIES; j++) {
                if (deck[countryIndex].states[i].cities[j].id == 0) {
                    char answer;
                    printf("Este estado não tem todas as cidades cadastradas. Cadastrar uma nova cidade? (s/n): ");
                    scanf(" %c", &answer);

                    if (answer == 's') {
                        //------------------------------------------->createCard(deck, countryId, &numCities); //<--------- create card here
                    } else {
                        return;
                    }
                }
            }
            return;
        }
    }

    State newState;
    strcpy(newState.state, name);
    newState.id = stateIds[1];
    newState.countryId = countryId;

    for (int i = 0; i < NUM_CITIES; i++) {
        newState.cities[i].id;
        newState.cities[i].population = 0;
        newState.cities[i].area = 0;
        newState.cities[i].GDP = 0;
        newState.cities[i].popDensity = 0;
        newState.cities[i].GDPPerCapita = 0;
        newState.cities[i].landmarks[0] = '\0';
    }

    deck[countryIndex].states[*numStates] = newState;
    (*numStates)++;

    printf("O estado %s foi criado com sucesso!\n Vamos dar início a criação da cidade?", newState.state);
    createCard(deck,countryIndex, newState.id, &numCities);
}

// Create a card
void createCard(Country deck[], int countryIndex, char stateId, int *numCities) { // 1-4
    int numStates = 0;
    int stateIndex = -1;

    for (int i = 0; i < NUM_COUNTRIES; i++) {
        if (deck[countryIndex].states[i].id == stateId) {
            stateIndex = i;
            break;
        }
    }

    if (stateIndex == -1) {
        printf("País com ID %d não encontrado!\n", stateId);
        return;
    }


    if (*numCities >= NUM_CITIES) {
        printf("O limite de cidades foi atingido para este estado!\n");
        return;
    }
    char name[50];
    printf("Insira o nome da cidade: ");
    scanf(" %49[^\n]", name);

    for (int i = 0; i <= *numCities; i++) {
        if (strcmp(deck[countryIndex].states[stateIndex].cities[i].city, name) == 0) {
            printf("A cidade %s já está cadastrada neste estado!\n", name);
            return;
        }
    }
    int population, area, gdp;
    char landmark1[50], landmark2[50], landmark3[50];

    printf("Insira o tamanho da população da cidade: ");
    scanf(" %d", &population);
    printf("Insira a área da cidade: ");
    scanf(" %f", &area);
    printf("Insira o PIB da cidade: ");
    scanf(" %f", &gdp);
    printf("Insira o nome de três pontos turísticos da cidade separadamente: ");
    scanf(" %49[^\n]", &landmark1);
    scanf(" %49[^\n]", &landmark2);
    scanf(" %49[^\n]", &landmark3);

    Card newCity;
    strcpy(newCity.city, name);
    sprintf(newCity.id, numCities, stateId);
    newCity.population = population;
    newCity.area = area;
    newCity.GDP = gdp;
    snprintf(newCity.landmarks, sizeof(newCity.landmarks), "%s, %s, %s", landmark1, landmark2, landmark3);
    newCity.popDensity =  (newCity.area > 0) ? (double)newCity.population / newCity.area : 0;
    newCity.GDPPerCapita = (newCity.population > 0) ? (double)newCity.GDP / newCity.population : 0;


    deck[countryIndex].states[stateIndex].cities[*numCities] = newCity;
    (*numCities)++;

    printf("%s foi criada com sucesso!\n Confira a carta criada:", newCity.city);
    printCard(deck, countryIndex, stateIndex, *numCities);
}

// Create a country
void createCountry(Country deck[], int *numCountries) {
        int numStates = 0;
    // There is no space
    if (*numCountries >= NUM_COUNTRIES) {
        printf("O limite de países foi atingido!\n");
        return;
    }

    char name[50];
    printf("Cadastre um país, insira o nome: ");
    scanf(" %49[^\n]", name);

    for (int i = 0; i < *numCountries; i++) {
        // Pre existent country
        if (strcmp(deck[i].country, name) == 0) {
            int countryId = deck[i].id;
            printf("%s já está cadastrado! Verificando estados...\n", name);

            for (int j = 0; j < NUM_STATES; j++) {
                if (deck[i].states[j].id == 0) {
                    char answer;
                    printf("Este país não tem todos os estados cadastrados. Cadastrar um novo estado? (s/n): ");
                    scanf(" %c", &answer);

                    if (answer == 's') {
                        createState(deck, countryId, &numStates);
                    } else {
                        return;
                    }
                }
            }
            return;
        }
    }

    // New country
    Country newCountry;
    strcpy(newCountry.country, name);
    newCountry.id = *numCountries;
    
    for (int i = 0; i < NUM_STATES; i++) {
        newCountry.states[i].id = 0;
        newCountry.states[i].state[0] = '\0';
        newCountry.states[i].countryId = newCountry.id;
    }

    deck[*numCountries] = newCountry;
    (*numCountries)++;

    printf("O país %s foi criado com sucesso!\n Vamos dar início a criação do estado?", newCountry.country);
    createState(deck, newCountry.id, &numStates);
}

void printCard (Country deck[], int countryIndex, int stateIndex, int cityIndex){
        printf("País: %c \n Estado: %c \n Cidade: %c \n População: %d habitantes \n Área: %f m² \n PIB: %f moeda local \n Densidade populacional: %f \n PIB per capita: %f moeda local \n Pontos Turísticos: \n - %c \n - %c \n - %c \n", deck[countryIndex].country, deck[countryIndex].states[stateIndex].state, 
    deck[countryIndex].states[stateIndex].cities[cityIndex].city, deck[countryIndex].states[stateIndex].cities[cityIndex].population, 
    deck[countryIndex].states[stateIndex].cities[cityIndex].area, deck[countryIndex].states[stateIndex].cities[cityIndex].GDP, 
    deck[countryIndex].states[stateIndex].cities[cityIndex].popDensity, deck[countryIndex].states[stateIndex].cities[cityIndex].GDPPerCapita, 
    deck[countryIndex].states[stateIndex].cities[cityIndex].landmarks[0], deck[countryIndex].states[stateIndex].cities[cityIndex].landmarks[1],
    deck[countryIndex].states[stateIndex].cities[cityIndex].landmarks[2]);
    return;
}

int main() {
    Country deck[NUM_COUNTRIES] = {0};
    int numCountries = 0;

    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.

    printf("Seja bem-vindo ao Super Trunfo Países!\n");


    //============================== instructions ==================================
    printf("escrever as instruções aqui\n");
    //====================================================================================

    
    createCountry(deck, &numCountries);

    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    return 0;
}