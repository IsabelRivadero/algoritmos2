#include <stdio.h>

int check_win(int mat[][3], int n) {
    int i, j;
    int common_elem; // elemento común en una fila, columna o diagonal
    
    // Verificar si hay una fila donde todos los elementos son iguales
    for (i = 0; i < n; i++) {
        common_elem = mat[i][0];
        for (j = 1; j < n; j++) {
            if (mat[i][j] != common_elem) {
                break;
            }
        }
        if (j == n) {
            return 1; // fila con elementos iguales encontrada
        }
    }
    
    // Verificar si hay una columna donde todos los elementos son iguales
    for (j = 0; j < n; j++) {
        common_elem = mat[0][j];
        for (i = 1; i < n; i++) {
            if (mat[i][j] != common_elem) {
                break;
            }
        }
        if (i == n) {
            return 1; // columna con elementos iguales encontrada
        }
    }
    
    // Verificar si hay una diagonal principal donde todos los elementos son iguales
    common_elem = mat[0][0];
    for (i = 1; i < n; i++) {
        if (mat[i][i] != common_elem) {
            break;
        }
    }
    if (i == n) {
        return 1; // diagonal principal con elementos iguales encontrada
    }
    
    // Verificar si hay una diagonal secundaria donde todos los elementos son iguales
    common_elem = mat[0][n-1];
    for (i = 1; i < n; i++) {
        if (mat[i][n-1-i] != common_elem) {
            break;
        }
    }
    if (i == n) {
        return 1; // diagonal secundaria con elementos iguales encontrada
    }
    
    // No se encontró ninguna fila, columna o diagonal con elementos iguales
    return 0;
}

int main() {
