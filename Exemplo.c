#include <stdio.h>

int main() {

	int jogador, final;
	char mat[3][3];
	char jogar, jogada;

	jogar = 's';
	jogar = toupper (jogar);
	while(jogar == 'S' ) {

		jogador = 1;
        final=0;

		do {
			system("cls");
			printf ("======================================");
			printf ("\n============ JOGO DA VELHA ===========");
			printf ("\n======================================");
			printf ("\n=== Tabuleiro ====== Jogo da Velha ===\n");
			printf ("\n    a | b | c           %c | %c | %c", a, b, c);
			printf ("\n    __|___|__           __|___|__");
			printf ("\n    d | e | f           %c | %c | %c", d, e, f);
			printf ("\n    __|___|__           __|___|__");
			printf ("\n    g | h | i           %c | %c | %c ", g, h, i);
			printf ("\n      |   |               |   |   ");
			printf ("\n\n======================================");
			printf ("\n Jogador 01-> [O]    Jogador 02-> [X]");
			printf ("\n======================================");

			if(jogador == 1) {
                do{
                j=0;
				printf("\n\nJOGADOR 01 - Escolha uma jogada: ");
				fflush(stdin);
				scanf("%c", &jogada);
				j=funcao(); /// j=1;
                }while(j==1);
				jogador = 2;
			}
			else {
				printf("\n\nJOGADOR 02 - Escolha uma jogada: ");
				fflush(stdin);
				scanf("%c", &jogada);

				// Verifica Jogada - Jogador 01
				switch(jogada) {

					case 'a':
							a = 'X';
							break;

					case 'b':
							b = 'X';
							break;

					case 'c':
							c = 'X';
							break;

					case 'd':
							d = 'X';
							break;

					case 'e':
							e = 'X';
							break;

					case 'f':
							f = 'X';
							break;

					case 'g':
							g = 'X';
							break;

					case 'h':
							h = 'X';
							break;

					case 'i':
							i = 'X';
							break;
				}

				jogador = 1;
			}

		} while (final != 1);

		printf("\n\nJogar novamente (s) ou (n)? ");
		fflush(stdin);
		scanf("%c", &jogar);
		system("cls");
	}

	printf("\n\n");
	return 0;
}
