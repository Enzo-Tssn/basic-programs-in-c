#include <stdio.h>

int ehsoma (int n);
int ehprimo (int num);

int main(){
    int m;
    printf("Digite um numero m > 0: ");
    scanf("%d", &m);
    ehsoma(m);

    return 0;
}

int ehsoma(int n){
    int primo_1, primo_2, j, l;
    primo_1 = 0;
    primo_2 = 0;

    for (j = n - 1; j > 1; j--){
        if (ehprimo(j) == 1){
            for (l = j; l > 1; l--){
                if(ehprimo(l) == 1 && j + l == n){
                    primo_1 = j;
                    primo_2 = l;
                    printf("%d eh soma dos primos %d e %d\n", n, primo_2, primo_1);
                }
            }
        }
    }

    if (primo_1 == 0)
        printf("%d nao eh soma de primos\n", n);
}

int ehprimo(int num){
    int abs, i, k;
    abs = 1;

    for(i = 2; i < num && abs == 1; i++){
        for (k = 2; k < num && abs == 1; k++){
            if (i * k == num)
                abs = 0;
        }
    }

    return abs;
}

