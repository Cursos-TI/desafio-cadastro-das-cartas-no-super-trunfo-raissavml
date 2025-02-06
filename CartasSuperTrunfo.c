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

// Defining structures
typedef struct {
    char city[50];
    int id;
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
    int id;
    Card cities[NUM_CITIES];
} State;

typedef struct {
    char country[50];
    int id;
    State states[NUM_STATES];
} Country;

// Create a state
void createState(Country deck[], int countryId, int *numStates) {
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
                        for (int j = 0; j < NUM_STATES; j++) {
                if (deck[i].states[j].cities == 0) {
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

    State newState;
    strcpy(newState.state, name);
    newState.id = *numStates + 1;
    newState.countryId = countryId;

    for (int i = 0; i < NUM_CITIES; i++) {
        newState.cities[i].id = 0;
        newState.cities[i].city[0] = '\0';
    }

    deck[countryIndex].states[*numStates] = newState;
    (*numStates)++;

    printf("O estado %s foi criado com sucesso!\n", newState.state);
}

// Create a card
void createCard(int countryId, int stateId) { // 1-4
    printf("Criando cidade para o país %d e estado %d...\n", countryId, stateId);

        // Compute values correctly
    // c->popDensity = (area > 0) ? (double)population / area : 0;
    // c->GDPPerCapita = (population > 0) ? (double)GDP / population : 0;
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

int main() {
    Country deck[NUM_COUNTRIES] = {0};
    int numCountries = 0;
    int numCities = 0;

    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.

    printf("Seja bem-vindo ao Super Trunfo: Países!\n");


    //============================== instructions ==================================
    printf("escrever as instruções aqui");
    //====================================================================================

    
    createCountry(deck, &numCountries);

    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    return 0;
}