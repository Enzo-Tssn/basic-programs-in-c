#include <stdio.h>

int main() {
    int semente, senha, num_tenta, tenta;
	int contador = 0;

    printf("Bem vinda(o) ao Numle\n");
    printf("Digite a semente para sortear a senha (0 a 10000): ");
    scanf("%d", &semente);
    semente = semente % 134456;

    /* sorteia um numero ’aleatorio’ entre 0 e 9 */
    senha = ((8121 * semente + 28411) % 134456) % 10;

     printf("Quantidade de tentativas (1 a 10): ");
     scanf("%d", &num_tenta);

     while (contador != num_tenta){

     printf("Digite a tentativa (0 a 9): ");
     scanf("%d", &tenta);

     if (tenta == senha){
     	printf("\nVoce acertou! A senha eh de fato %d \n", senha);
        contador = num_tenta;

	 }  else {
	 	contador++;
	 	if(contador == num_tenta){
            printf("\nVoce perdeu! A senha era %d \n", senha);
            }
        }
    }
    return 0;
 }
