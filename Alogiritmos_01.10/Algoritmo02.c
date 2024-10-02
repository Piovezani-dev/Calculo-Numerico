#include <stdio.h>
#include <stdlib.h>

void ElimGauss(int n, double a[n][n], double b[n], double x[n]) {
    int i, j, k;
    double m, s;

    //Eliminação
    for (k = 0; k < n - 1; k++) {
        for (i = k + 1; i < n; i++) {
            m = a[i][k] / a[k][k];

            for (j = k; j < n; j++) {
                a[i][j] = a[i][j] - m * a[k][j];
            }
            b[i] = b[i] - m * b[k];
        }
    }

    //resolução do sistema
    x[n-1] = b[n-1] / a[n-1][n-1];

    for (k = n - 2; k >= 0; k--) { 
        s = 0.0;
        for (j = k + 1; j < n; j++) {
            s += a[k][j] * x[j]; 
        }
        x[k] = (b[k] - s) / a[k][k]; 
    }
}

int main() {
    int n = 4;  // dimensão
    
    //matriz de exemplo do slide aula 3, slide de numero 26
    double a[4][4] = { 
        {1,6,2,4},
        {3,19,4,15},
        {1,4,8,-12},
        {5,33,9,3}
    };

    //vetor b
    double b[4] = {8,25,18,72};

    //vetor para guardar a solução
    double x[4];

    ElimGauss(n, a, b, x);

    printf("Solução do sistema:\n");
    for (int i = 0; i < n; i++) {
        printf("x_%d = %.2f\n", i+1, x[i]);
    }

    return 0;
}
