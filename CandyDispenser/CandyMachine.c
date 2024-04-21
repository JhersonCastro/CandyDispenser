#include "CandyMachine.h" 
#include "List.h"
#include "Queue.h"
#include <stdio.h>
float getNumber(char* prmEtiqueta) {
    char varInput[50];
    float varNumber;
    while (1)
    {
        printf("%s", prmEtiqueta);
        fgets(varInput, 50, stdin);
        char* varEnd;
        varNumber = strtod(varInput, &varEnd);
        if (varEnd == varInput || *varEnd != '\n')
        {
            printf("Invalid Input\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {} // limpiar búfer de entrada
        }
        else
            break;
    }
    printf("\n");
    return varNumber;
}

void initCandyMachine(CandyMachine* candyMachine) {
    int denomination[4] = {100,200,500,1000};
#pragma region INIT_COIN
    listInit(&candyMachine->Coins);
    for (int i = 0; i < sizeof(denomination)/sizeof(int); i++)
    {
        Queue temp;
        queueInit(&temp);
        Coin tempCoin = makeCoin(denomination[i]);
        int minCoins;
        printf("¿Cuantas monedas %i vas almacenar?", denomination[i]);
        minCoins = getNumber("");
        for (int i = 0; i < minCoins; i++)
        {
            enqueue(&temp, &tempCoin);
        }
        listAddQueue(&candyMachine->Coins, temp);
    }
#pragma endregion

    listInit(&candyMachine->Candies);
    queueInit(&candyMachine->InsertedCoins);
    free(denomination);
}





































/*
#define MAX_CANDIES 5
#define MAX_COINS 4

typedef struct Candy {
    int id;
    char name[50];
    int quantity;
    float price;
} Candy;

// Structure to represent a coin
typedef struct Coin {
    float value;
    struct Coin* next;
} Coin;




// Función para inicializar la máquina
void initializeMachine(Candy candies[], int numCandies, Coin availableCoins[], int numCoins) {
    char* candyNames[] = { "Barra de chocolates","Caramelos", "Gomas", "chicles", "Bombones"};
    float candyPrices[] = { 1200, 400, 200, 300, 300 };

    // Cargar los dulces disponibles
    for (int i = 0; i < numCandies; i++) {
        candies[i].id = i + 1;
        strcpy(candies[i].name, candyNames[i]);
        candies[i].quantity = 10; // Cantidad inicial de cada dulce
        candies[i].price = candyPrices[i]; // Precio de cada dulce
    }

    // Establecer el inventario inicial de monedas
    float denominations[] = { 100, 200, 500, 1000 };
    for (int i = 0; i < numCoins; i++) {
        availableCoins[i].value = denominations[i]; // Valores de las monedas
        availableCoins[i].next = NULL;
    }
}

// Función para recibir monedas y almacenarlas en una cola
void receiveCoin(Coin coins[], int numCoins) {
    float coinValue;
    printf("Ingrese el valor de la moneda: ");
    scanf("%f", &coinValue);

    // Buscar la moneda en el arreglo y agregarla a la cola
    for (int i = 0; i < numCoins; i++) {
        if (coins[i].value == coinValue) {
            // Aquí se agregaría la moneda a la cola
            printf("Moneda de %.2f pesos recibida.\n", coinValue);
            return;
        }
    }
    printf("Moneda no válida.\n");
}

// Función para validar si el monto ingresado es suficiente para comprar un dulce
int validatePayment(float candyPrice) {
    float enteredAmount;
    printf("Ingrese el monto: ");
    scanf("%f", &enteredAmount);

    if (enteredAmount >= candyPrice)
        return 1; // Pago válido
    else {
        printf("El monto ingresado no es suficiente.\n");
        return 0; // Pago insuficiente
    }
}

// Función para entregar un dulce seleccionado
void deliverCandy(Candy* selectedCandy) {
    if (selectedCandy->quantity > 0) {
        printf("Dulce \"%s\" entregado.\n", selectedCandy->name);
        selectedCandy->quantity--;
    }
    else {
        printf("No hay existencias de \"%s\".\n", selectedCandy->name);
    }
}

// Función para calcular el cambio a devolver al usuario
void calculateChange(float candyPrice, Coin change[], int* numCoinChange) {
    float enteredAmount;
    printf("Ingrese el monto ingresado: ");
    scanf("%f", &enteredAmount);

    *numCoinChange = 0;
    float totalChange = enteredAmount - candyPrice;

    // Calcular el cambio utilizando la menor cantidad de monedas
    for (int i = MAX_COINS - 1; i >= 0; i--) {
        while (totalChange >= change[i].value) {
            totalChange -= change[i].value;
            (*numCoinChange)++;
        }
    }
}

// Función para entregar el cambio al usuario
void giveChange(Coin change[], int numCoinChange) {
    printf("El cambio se entregará en: \n");
    for (int i = MAX_COINS - 1; i >= 0; i--) {
        while (numCoinChange > 0 && change[i].value <= numCoinChange * change[i].value) {
            printf("%.2f pesos\n", change[i].value);
            numCoinChange--;
        }
    }
}

// Función para actualizar el inventario de monedas disponibles
void updateCoinsInventory(Coin change[], int numCoinChange) {
    // Definir las denominaciones de monedas disponibles
    float denominations[] = { 100, 200, 500, 1000 };
    int numDenominations = sizeof(denominations) / sizeof(float);

    // Recorrer el arreglo de cambio y actualizar el inventario de monedas disponibles
    for (int i = 0; i < numCoinChange; i++) {
        for (int j = 0; j < numDenominations; j++) {
            if (change[i].value == denominations[j]) {
                // Aquí se podría decrementar la cantidad de esa moneda en el inventario
                printf("Actualizando inventario: Moneda de %.2f pesos utilizada.\n", change[i].value);
                break;
            }
        }
    }
}

// Función para mostrar el inventario actualizado de dulces disponibles
void showCandiesInventory(Candy candies[], int numCandies) {
    printf("Inventario de dulces:\n");
    for (int i = 0; i < numCandies; i++) {
        printf("%s - Cantidad: %d - Precio: %.2f pesos\n", candies[i].name, candies[i].quantity, candies[i].price);
    }
}

*/