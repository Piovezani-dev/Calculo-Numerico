#include <stdio.h>

//Função criada para fazer exatamente o que o algoritmo dado pediu
void TriSup(int n, double a[n][n], double b[n], double x[n]) { 
    double s;
    
    x[n-1] = (b[n-1]) / (a[n-1][n-1]);
    
    for (int k = n - 2; k >= 0; k--) {
        s = 0.0;
        for (int j = k + 1; j < n; j++) {
            s += a[k][j] * x[j];
        }
        x[k] = (b[k] - s) / (a[k][k]);
    }
}

int main() {
    int n = 4; //dimensão da matriz

    //matriz de exemplo, neste caso foi utilizado o mesmo exemplo da Aula 3 slide 30
    double a[4][4] = {
        {1,6, 2,  4},
        {0,1,-2,  3},
        {0,0, 2,-10},
        {0,0, 0, -1}
    };

    // vetor b
    double b[4] = {8,1,12,-1};

    // vetor para receber as respostas 
    double x[4];

    // chamada de função
    TriSup(n, a, b, x);

    printf("Solução do sistema:\n");
    for (int i = 0; i < n; i++) {
        printf("x_%d = %.2f\n", i+1, x[i]);
    }

    return 0;
}
