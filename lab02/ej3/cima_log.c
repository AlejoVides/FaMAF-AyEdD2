#include <stdio.h>
#include <stdbool.h>
#include "cima_log.h"

/*
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima
 * usando la estrategia divide y venceras.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 * La cima es el elemento que se encuentra en la posición k.
 * PRECONDICION: tiene_cima(a, length)
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
int cima_log(int a[], int length) {
    return cima_log_rec(a, 0, length-1, length);
    return 0;
}

int cima_log_rec(int a[], int izq, int der, int length){
    int cima;
    int mid = (izq+der)/2;
    
    if (es_cima(a, mid, length)) {
        cima = mid;
    }
    else if (izq_cima(a, mid)) {
        cima = cima_log_rec(a, izq, mid-1, length);
    }
    else if (der_cima(a, mid, length)) {
        cima = cima_log_rec(a, mid+1, der, length);
    }
    return cima;
}

bool es_cima(int a[], int i, int length){
    return (i == 0 || a[i] > a[i-1]) && (i == length-1 || a[i] > a[i+1]);
}

bool izq_cima(int a[], int i){
    return i > 0 && a[i] < a[i-1];
}

bool der_cima(int a[], int i, int length){
    return i < length - 1 && a[i] < a[i+1];
}