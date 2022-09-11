#include <stdio.h>

int collatz(unsigned int);
void proximonum (unsigned int, unsigned int);

int main(){
    unsigned int i, f;

    printf(" Digite os limites do intervalo: ");
    scanf("%u %u", &i, &f);
    proximonum(i, f);

    return 0;
}

void proximonum (unsigned int m, unsigned int n){
    if (m >= n){
        while (m >= n){
            printf(" %u: %d passos\n", m, collatz(m));
            m--;
        }
    }
    else {
        while (m <= n){
            printf(" %u: %d passos\n", m, collatz(m));
            m++;
        }
    }
}

int collatz(unsigned int n){
    int contador;

    if(n == 1 || n == 2 || n == 4 || n == 8){
        for(contador = 0; n != 1; contador++)
            n /= 2;
    }
    else {
        for(contador = 4; n != 16; contador++){
            if (n % 2 == 0)
                n /= 2;
            else
                n = n*3 + 1;
        }
    }

    return contador;
}

