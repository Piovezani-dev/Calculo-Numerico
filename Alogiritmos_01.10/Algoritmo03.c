#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void LU(int n, double A[n][n], int p[n]) {
    int i, j, k, r;
    double pv, aux, m;
    
    //calculo dos fatores
    for (i = 0; i < n; i++) {
        p[i] = i;
    }

    for (k = 0; k < n - 1; k++) {
        pv = fabs(A[k][k]); //A função fabs() calcula o valor absoluto do argumento de ponto flutuante x
        r = k;
        for (i = k + 1; i < n; i++) {
            if (fabs(A[i][k]) > pv) {
                pv = fabs(A[i][k]);
                r = i;
            }
        }

        if (pv == 0) {
            printf("Matriz singular! Não é possível continuar.\n");
            exit(1);
        }

        if (r != k) {
            for (j = 0; j < n; j++) {
                aux = A[k][j];
                A[k][j] = A[r][j];
                A[r][j] = aux;
            }
            aux = p[k];
            p[k] = p[r];
            p[r] = aux;
        }

        // Eliminação
        for (i = k + 1; i < n; i++) {
            m = A[i][k] / A[k][k];
            A[i][k] = m;
            for (j = k + 1; j < n; j++) {
                A[i][j] = A[i][j] - m * A[k][j];
            }
        }
    }
}

//resolução dos sistemas triangulares
void resolveSistemaTriangular(int n, double A[n][n], double b[n], double x[n], int p[n]) {
    double y[n];
    double soma;

    for (int i = 0; i < n; i++) {
        soma = 0.0;
        for (int j = 0; j < i; j++) {
            soma += A[i][j] * y[j];
        }
        y[i] = b[p[i]] - soma;
    }

    for (int i = n - 1; i >= 0; i--) {
        soma = 0.0;
        for (int j = i + 1; j < n; j++) {
            soma += A[i][j] * x[j];
        }
        x[i] = (y[i] - soma) / A[i][i];
    }
}

int main() {
    int n = 3; //dimensão

    // matriz utilizada do exemplo da aula 04, slide 36
    double A[3][3] = {
        {3,2,4},
        {1,1,2},
        {4,3,-2}
    };

    //vetor b
    double b[3] = {1, 2, 3};

    //armazena os resultados
    double x[3];

    //vetor de permutação
    int p[3];

    LU(n, A, p);

    resolveSistemaTriangular(n, A, b, x, p);

    printf("Solução do sistema:\n");
    for (int i = 0; i < n; i++) {
        printf("x_%d = %.2f\n", i + 1, x[i]);
    }

    return 0;
}
