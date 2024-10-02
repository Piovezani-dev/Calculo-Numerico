#include <stdio.h>
#include <math.h>

//fatoração de Cholesky
void choleskyDecomposition(double A[3][3], int n, double G[3][3]) {
    int i, j, k;
    double soma;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            G[i][j] = 0.0;
        }
    }

    for (k = 0; k < n; k++) {
        soma = 0.0;
        for (j = 0; j < k; j++) {
            soma += G[k][j] * G[k][j];
        }
        G[k][k] = sqrt(A[k][k] - soma);

        for (i = k + 1; i < n; i++) {
            soma = 0.0;
            for (j = 0; j < k; j++) {
                soma += G[i][j] * G[k][j];
            }
            G[i][k] = (A[i][k] - soma) / G[k][k];
        }
    }
}

int main() {
    int n = 3;

    //matriz exemplo da aula 05, exercício do slide 34
    double A[3][3] = {
        {1,2,1},
        {2,8,10},
        {1,10,26}
    };

    //matriz G
    double G[3][3];

    choleskyDecomposition(A, n, G);

    printf("Matriz G (resultado da fatoração de Cholesky):\n(Ex.:Posição [linha][coluna])\n\n");
    
    int ii, jj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            ii = i+1;
            jj = j+1;
            printf("Posição G[%i][%i]: %f ",ii ,jj , G[i][j]);
        }
        printf("\n");
    }

    return 0;
}
