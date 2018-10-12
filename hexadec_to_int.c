#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {
	if (argc == 1) {
		printf("ERRO: Faltam argumentos para o programa.\n");
		printf("Insira um numero em hexadecimal na linha de comando.\n");
		return 0;
	}

	//limites definidos pela tabela ascii
	//para numeros de 0 a 9: 48 a 57;
	const int lim_baix_num = 48, lim_cima_num = 57;

	//para letras maiusculas de 'A' a 'F': 65 a 70;
	const int lim_baix_LETRA = 65, lim_cima_LETRA = 70;

	//para letras minusculas de 'a' a 'f': 97 a 102.
	const int lim_baix_letra = 97, lim_cima_letra = 102;

	const int tamanho_entrada = 10;
	int multiplicador, expoente;
	double resultado = 0;
	char string_hex[tamanho_entrada];
	strcpy(string_hex, argv[1]);
	expoente = strlen(argv[1]) - 1;
	
	for (int i = 0; i < tamanho_entrada; i++) {
		if (string_hex[i] == '\0') {
			break;
		} else {
			if ((int)string_hex[i] >= lim_baix_num && (int)string_hex[i] <= lim_cima_num) {
				multiplicador = ((int)string_hex[i] - lim_baix_num);

			} else if ((int)string_hex[i] >= lim_baix_LETRA && (int)string_hex[i] <= lim_cima_LETRA){
				multiplicador = ((int)string_hex[i] - lim_baix_LETRA + 10);

			} else if ((int)string_hex[i] >= lim_baix_letra && (int)string_hex[i] <= lim_cima_letra) {
				multiplicador = ((int)string_hex[i] - lim_baix_letra + 10);

			} else {
				printf("Entrada invalida: nao e um numero hexadecimal valido.\n");
				return 0;
			}
			resultado += (multiplicador * pow(16, expoente));
			expoente--;
		}
	}
	printf("%.0lf\n", resultado);
	return 0;
}
