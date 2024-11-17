//Mila Gallegos Vazquez 

#include <stdio.h>
#include <stdlib.h>

#define PUEBLOS 100
#define BEBIDAS 8

// Función para inicializar matrices
void inicializar_matriz(int matriz[PUEBLOS][BEBIDAS]) {
    for (int i = 0; i < PUEBLOS; i++) {
        for (int j = 0; j < BEBIDAS; j++) {
            matriz[i][j] = 0;
        }
    }
    printf("Se inicializó la matriz de forma correcta.\n");
}

// Función para llenar la matriz con datos
void llenar_matriz(int matriz[PUEBLOS][BEBIDAS]) {
    int bebida, cantidad;
    for (int i = 0; i < PUEBLOS; i++) {
        printf("Dame la bebida correspondiente del pueblo %d (-1 para terminar): ", i);
        scanf("%d", &bebida);
        while (bebida != -1) {
            printf("Dame la cantidad en litros: ");
            scanf("%d", &cantidad);
            matriz[i][bebida] += cantidad; // Se suma para manejar múltiples entradas
            printf("Dame otra bebida (-1 para terminar): ");
            scanf("%d", &bebida);
        }
    }
}

// Función para determinar la bebida más consumida entre todos los pueblos
int bebida_mas_consumida(int matriz[PUEBLOS][BEBIDAS], int total[]) {
    int max = 0, bebida = 0;

    // Sumar consumos por bebida
    for (int j = 0; j < BEBIDAS; j++) {
        total[j] = 0;
        for (int i = 0; i < PUEBLOS; i++) {
            total[j] += matriz[i][j];
        }
        if (total[j] > max) {
            max = total[j];
            bebida = j;
        }
    }

    printf("La bebida %d es la que más se consume con %d litros.\n", bebida, max);
    return bebida;
}

// Función para determinar la bebida alcohólica más consumida
int bebida_alcoholica_mas_consumida(int matriz[PUEBLOS][BEBIDAS], int total[]) {
    int max = 0, bebida = 0;

    for (int i = 0; i < BEBIDAS; i++) {
        if (i != 1 && i != 6) { // Excluir bebidas no alcohólicas
            total[i] = 0;
            for (int j = 0; j < PUEBLOS; j++) {
                total[i] += matriz[j][i];
            }
            if (total[i] > max) {
                max = total[i];
                bebida = i;
            }
        }
    }

    printf("La bebida alcohólica %d es la más consumida con %d litros.\n", bebida, max);
    return bebida;
}

// Función para determinar el pueblo que más alcohol consume
int pueblo_mas_consumidor(int matriz[PUEBLOS][BEBIDAS], int total[]) {
    int max = 0, pueblo = 0;

    for (int i = 0; i < PUEBLOS; i++) {
        total[i] = 0;
        for (int j = 0; j < BEBIDAS; j++) {
            if (j != 1 && j != 6) { // Excluir bebidas no alcohólicas
                total[i] += matriz[i][j];
            }
        }
        if (total[i] > max) {
            max = total[i];
            pueblo = i;
        }
    }

    printf("El pueblo %d consume más alcohol con %d litros.\n", pueblo, max);
    return pueblo;
}

int main() {
    int matriz[PUEBLOS][BEBIDAS];
    int total_bebidas[BEBIDAS];
    int total_pueblos[PUEBLOS];

    // Inicializar matriz
    inicializar_matriz(matriz);

    // Llenar matriz con información
    llenar_matriz(matriz);

    // Determinar la bebida más consumida entre todos los pueblos
    bebida_mas_consumida(matriz, total_bebidas);

    // Determinar la bebida alcohólica más consumida
    bebida_alcoholica_mas_consumida(matriz, total_bebidas);

    // Determinar el pueblo que más alcohol consume
    pueblo_mas_consumidor(matriz, total_pueblos);

    return 0;
}
