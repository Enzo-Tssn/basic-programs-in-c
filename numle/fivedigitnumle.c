#include <stdio.h>

int main() {
    int semente, senha, num_tenta, tenta;
	int contador = 0;

    printf("Bem vinda(o) ao Numle\n");
    printf("Digite a semente para sortear a senha (0 a 10000): ");
    scanf("%d", &semente);
    semente = semente % 134456;

    /* sorteia um numero ’aleatorio’ entre 0 e 99999 */
    senha = ((8121 * semente + 28411) % 134456) % 100000;

    int a = senha/10000;
    int b = (senha/1000)%10;
    int c = (senha/100)%10;
    int d = (senha/10)%10;
    int e = senha%10;

    printf("Quantidade de tentativas (1 a 10): ");
    scanf("%d", &num_tenta);


    while (contador != num_tenta && tenta != senha){

    printf("\nDigite a tentativa (0 a 99999): ");
    scanf("%d", &tenta);

    int f = tenta/10000;
    int g = (tenta/1000)%10;
    int h = (tenta/100)%10;
    int i = (tenta/10)%10;
    int j = tenta%10;

    if (tenta == senha)
        printf("Voce acertou! A senha eh de fato %d\n", senha);

    else{

    if(a == f){
        printf("Primeiro digito certo!\n");
        }
    else if (f == b && b != g
            || f == c && c != h
            || f == d && d != i
            || f == e && e != j){
        printf("Primeiro digito em posicao incorreta.\n");
        }

    if(b == g){
        printf("Segundo digito certo!\n");
        }
    else if (g == a && a != f
            || g == c && c != h && (f!=c||g==a||g==d)
            || g == d && d != i && (f!=d||g==a||g==c)
            || g == e && e != j && (f!=e||g==a||g==d)){
        printf("Segundo digito em posicao incorreta.\n");
        }

    if(c == h){
        printf("Terceiro digito certo!\n");
        }
    else if (h == a && a != f && (g!=a||h==b)
            || h == b && b != g && (f!=b||h==a)
            || h == d && d != i && (f!=d||h==a) && (g!=d||h==b)
            || h == e && e != j && (f!=e||h==a) && (g!=e||h==b)){
        printf("Terceiro digito em posicao incorreta.\n");
        }

    if(d == i){
        printf("Quarto digito certo!\n");
        }
    else if (i == a && a != f && (g!=a||i==b||i==c) && (h!=a||i==b||i==c)
            || i == b && b != g && (f!=b||i==a||i==c) && (h!=b||i==a||i==c)
            || i == c && c != h && (f!=c||i==a||i==b) && (g!=c||i==a||i==b)
            || i == e && e != j && (f!=e||i==a||i==c) && (g!=e||i==a||i==b) && (h!=e||i==b||i==c)){
        printf("Quarto digito em posicao incorreta.\n");
        }

    if(e == j){
        printf("Quinto digito certo!\n");
        }
    else if (j == a && a != f && (g!=a||j==b) && (h!=a||j==c) && (i!=a||j==d)
            || j == b && b != g && (f!=b||j==a) && (h!=b||j==c) && (i!=b||j==d)
            || j == c && c != h && (f!=c||j==a) && (g!=c||j==b) && (i!=c||j==d)
            || j == d && d != i && (f!=d||j==a) && (g!=d||j==b) && (h!=d||j==c)){
        printf("Quinto digito em posicao incorreta.\n");
        }


    contador++;

    if (contador == num_tenta)
        printf("Voce perdeu! A senha era %d.\n",senha);

    }
    }
    return 0;
}
