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
    char country[50];
    int id;
    State states[NUM_STATES];
} Country;
typedef struct {
    char state[50];
    int countryId;
    int id;
    Card cities[NUM_CITIES];
} State;

// Create a country
void createCountry(Country deck[], int *numCountries) {
    // Check the deck space
        if (*numCountries >= NUM_COUNTRIES) {
        printf("O limite de países foi atingido!\n");
        return 1;
    }

    char name[50];
    printf("Cadastre um país, você deve inserir o nome dele:");
    scanf("%49[^/n]", name);

    for (int i = 0; i < *numCountries; i++) {
        if (strcmp(deck[i].country, name) == 0) {
            int countryId = deck[i].id;
            printf("Esse país já está cadastrado! Aguarde um momento, estamos verificando se todas as cartas do país %c estão completas.\n", name);
            
        for (int j = 0; j < NUM_STATES; i++) {
        if (deck[i].states[j] == 0) { // Assume 0 means empty state
        char answer;
        printf("Este país não tem todos os estados cadastrados, você gostaria de cadastrar um novo estado? /n Digite s para sim e n para não.");
        scanf("%c", answer);
        if (answer== "s") {
            createState(countryId);
        } else{
            for (int i = 0; i < NUM_STATES; i++) {
        // Check for empty cities in each state
        for (int j = 0; j < NUM_STATES; j++) {
                if (deck[i].states[j] > 0) {  // Only check populated states
                    int stateId = deck[i].states[j];
                    char state = deck[i].states[j].state;
                    char answer2;
                    for (int k = 0; k < NUM_CITIES; k++) {
                        if (stateId == 0) {  // Assume 0 means empty city
                            printf("O estado %c não tem todas as cidades cadastradas, você gostaria de cadastrar uma nova cidade? /n Digite s para sim e n para não.", state);
        scanf("%c", answer2);
        if (answer2== "s") {
            createCard(countryId, stateId);
        } else{
            countCards();
            char answer3;
                     printf("Você gostaria de começar a jogar com as cartas que tem? /n Digite s para sim e n para não.");
        scanf("%c", answer3);
        if (answer3== "s") {
            startGame();
        } else {
            return;
        }
    }
        }
            return 0;  // Return 0 if an empty state is found
        }
    }

    // Check if all cities in the states are filled
    for (int i = 0; i < NUM_STATES; i++) {
        // Check for empty cities in each state
        if (c->states[i] > 0) {  // Only check populated states
            for (int j = 0; j < NUM_CITIES; j++) {
                if (c->states[i] == 0) {  // Assume 0 means empty city
                    return 0;  // Return 0 if an empty city is found
                }
            }
        }
    }

    return 1;  // Country has all states and cities filled
}
            return;
        }
    }


    // Compute values correctly
   // c->popDensity = (area > 0) ? (double)population / area : 0;
    //c->GDPPerCapita = (population > 0) ? (double)GDP / population : 0;
}

// Create a state
void createState() {


}


// Create a card
void createCard() {
    printf("Cadastre sua carta");
    strcpy(c->city, name);
    c->id = id;
    c->population = population;
    c->area = area;
    c->GDP = GDP;
    strcpy(c->landmarks, landmarks);
    
    // Compute values correctly
    c->popDensity = (area > 0) ? (double)population / area : 0;
    c->GDPPerCapita = (population > 0) ? (double)GDP / population : 0;
}

void countCards() {
}

void startGame() {

}

int main() {
     Country deck[NUM_COUNTRIES];
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    printf("Seja bem vindo ao Super Trunfo: Países! /n Está preparado para cadastrar as suas cartas?");
    createCountry();
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    return 0;
}
