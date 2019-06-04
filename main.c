#include <stdio.h>
#define l 3
//Prototipacao
void limpar(char T[][l]);
void tabuleiro(char T[][l]);
int v_jogada(char T[][3], int jogada);
void computador(char T[][l]);
int vertical(char T[][l],char ve);
int horizontal(char T[][l],char ve);
int diagonal(char T[][l],char ve);
int fim(char T[][l],char ve);
int vazio(char T[][l]);

void main(){
    int jogador, fl,fimo,em,fimx, jogada = 0;
    char T[l][l],jogar;

    srand(time(NULL));

    do{
      fimo=0;
      fl=0;
      jogar='N';
      printf("Deseja jogar?: ");
      fflush(stdin); scanf("%c",&jogar);
      jogar=toupper(jogar);
      if(jogar=='S'){
          printf("Quem comecara jogando:\n1-Voce\n2-Computador\n");
          scanf("%d",&jogador);
          limpar(T);

          do{
            tabuleiro(T); ///Imprime o tabuleiro

            if(jogador==1){
              jogador=2; ///Deixa pronto pra proxima repetição
              do{
                jogada=' ';
                printf("\n\nJOGADOR 01 - Escolha uma jogada: ");
                fflush(stdin);
                scanf("%d",&jogada);
                jogada=v_jogada(T,jogada);
              }while(jogada==-1);
            }else{///Jogadas do computador e muda o jogador para 1 para proxima repetição
                computador(T);
                jogador=1;
            }

            ///Recebe valores, para determinar o ganhador
            fimo=fim(T,'O');  ///Se 1 O ganhou
            fimx=fim(T,'X');  ///Se 1 X ganhou
            em=vazio(T); ///Conta os espaços vazios

            if(fimo==1 || fimx==1 || em==0){
                fl=1;
            }

            if(fimo==1){
                tabuleiro(T);
                printf("\n\n========== COMPUTADOR GANHOU =========\n");
            }else if(fimx==1){
                tabuleiro(T);
                printf("\n\n============= VOCE GANHOU ============\n");
            }else if(em==0){
                tabuleiro(T);
                printf("\n\n================ EMPATOU =============\n");
            }

          }while (fl!=1);
      }
    }while(jogar!='N');
}

void limpar(char T[][l]){ ///Realiza a limpeza do vetor
  int j,k;

  for(j=0;j<l;j++){
    for(k=0;k<l;k++){
      T[j][k]=' ';
    }
  }
}

void tabuleiro(char T[][l]){ ///Limpa a tela e imprime o tabuleiro
  system("cls");
  printf ("======================================");
  printf ("\n============ JOGO DA VELHA ===========");
  printf ("\n======================================");
  printf ("\n=== Tabuleiro ====== Jogo da Velha ===\n");
  printf ("\n    1 | 2 | 3           %c | %c | %c", T[0][0], T[0][1], T[0][2]);
  printf ("\n    __|___|__           __|___|__");
  printf ("\n    4 | 5 | 6           %c | %c | %c", T[1][0], T[1][1], T[1][2]);
  printf ("\n    __|___|__           __|___|__");
  printf ("\n    7 | 8 | 9           %c | %c | %c ", T[2][0], T[2][1], T[2][2]);
  printf ("\n      |   |               |   |   ");
  printf ("\n\n======================================");
  printf ("\n Jogador 01-> [X]    Computador 02-> [O]");
  printf ("\n======================================");
}

int v_jogada(char T[][3], int jogada){
    int C, L = 0;    

    if(jogada == 1){
        T[0][0] = 'X';
        return 1;
    }else{
        while(C < 3){
            L = 0;
            while(L < 3){
                if(jogada == 1){
                    if(T[C][L] == ' '){
                        T[C][L] = 'X';
                        return 1;
                    }                       
                    return -1;
                }    
                jogada--;
                L++;
            }
            C++;        
        }

        return -1;
    }

}

void computador(char T[][3]){
    int j,v,aux=0;

    v=vazio(T); ///Verifica se há possições vazias, assim determina se o computador pode realizar uma jogada ou não.
     ///Evitando ficar preso no loop da jogada aleatória

    if(v!=0){
        if( ///Cima esquerda ####PRIORIZA GANHAR####
           (
            (T[0][1]=='O' && T[0][2]=='O')||
            (T[1][0]=='O' && T[2][0]=='O')||
            (T[1][1]=='O' && T[2][2]=='O')
            ) && (T[0][0]==' ')
            ){
            T[0][0]='O';
        }else if( ///Cima meio
                (
                    (T[0][0]=='O' && T[0][2]=='O')||
                    (T[1][1]=='O' && T[2][1]=='O')
                ) && (T[0][1]==' ')
            ){
            T[0][1]='O';
        }else if( ///Cima direita
                (
                    (T[0][0]=='O' && T[0][1]=='O')||
                    (T[1][1]=='O' && T[2][0]=='O')||
                    (T[1][2]=='O' && T[2][2]=='O')
                ) && (T[0][2]==' ')
            ){
            T[0][2]='O';
        }else if( ///Meio esquerda
                (
                    (T[0][0]=='O' && T[2][0]=='O')||
                    (T[1][1]=='O' && T[1][2]=='O')
                ) && (T[1][0]==' ')
            ){
            T[1][0]='O';
        }else if( ///Meio meio
                (
                    (T[0][1]=='O' && T[2][1]=='O')||
                    (T[1][0]=='O' && T[1][2]=='O')||
                    (T[0][0]=='O' && T[2][2]=='O')||
                    (T[0][2]=='O' && T[2][0]=='O')
                ) && (T[1][1]==' ')
            ){
            T[1][1]='O';
            //printf("ENTROU AQUI! %c\n",T[1][1]);
        }else if( ///Meio direita
                (
                    (T[1][0]=='O' && T[1][1]=='O')||
                    (T[0][2]=='O' && T[2][2]=='O')
                ) && (T[1][2]==' ')
            ){
            T[1][2]='O';
        }else if( ///Baixo esquerda
                (
                    (T[0][0]=='O' && T[1][0]=='O')||
                    (T[1][1]=='O' && T[0][2]=='O')||
                    (T[2][1]=='O' && T[2][2]=='O')
                ) && (T[2][0]==' ')
            ){
            T[2][0]='O';
        }else if( ///Baixo meio
                (
                    (T[2][0]=='O' && T[2][2]=='O')||
                    (T[1][1]=='O' && T[0][1]=='O')
                ) && (T[2][1]==' ')
            ){
            T[2][1]='O';
        }else if( ///Baixo direita
                (
                    (T[2][0]=='O' && T[2][1]=='O')||
                    (T[0][0]=='O' && T[1][1]=='O')||
                    (T[0][2]=='O' && T[1][2]=='O')
                ) && (T[2][2]==' ')
            ){
            T[2][2]='O';
        }else if( ///Cima esquerda  ####BLOQUEAR O JOGADOR####
           (
            (T[0][1]=='X' && T[0][2]=='X')|| ///horizontal
            (T[1][0]=='X' && T[2][0]=='X')|| ///vertical
            (T[1][1]=='X' && T[2][2]=='X')|| ///diagonal
            (T[0][1]=='X' && T[1][0]=='X')   ///tatica
            ) && (T[0][0]==' ')
            ){
            T[0][0]='O';
        }else if( ///Cima meio
                (
                    (T[0][0]=='X' && T[0][2]=='X')|| ///horizontal
                    (T[1][1]=='X' && T[2][1]=='X')   ///vertical
                ) && (T[0][1]==' ')
            ){
            T[0][1]='O';
        }else if( ///Cima direita
                (
                    (T[0][0]=='X' && T[0][1]=='X')|| ///horizontal
                    (T[1][1]=='X' && T[2][0]=='X')|| ///diagonal
                    (T[1][2]=='X' && T[2][2]=='X')|| ///vertical
                    (T[0][1]=='X' && T[1][2]=='X')   ///tatica
                ) && (T[0][2]==' ')
            ){
            T[0][2]='O';
        }else if( ///Meio esquerda
                (
                    (T[0][0]=='X' && T[2][0]=='X')|| ///vertical
                    (T[1][1]=='X' && T[1][2]=='X')   ///horizontal
                ) && (T[1][0]==' ')
            ){
            T[1][0]='O';
        }else if( ///Meio meio
                (
                    (T[0][1]=='X' && T[2][1]=='X')|| ///vertical
                    (T[1][0]=='X' && T[1][2]=='X')|| ///horizontal
                    (T[0][0]=='X' && T[2][2]=='X')|| ///diagonal primaria
                    (T[0][2]=='X' && T[2][0]=='X')   ///diagonal secundaria
                ) && (T[1][1]==' ')
            ){
            T[1][1]='O';
            //printf("AAAAAAAAAAHHHH! %c\n",T[1][1]);
        }else if( ///Meio direita
                (
                    (T[1][0]=='X' && T[1][1]=='X')|| ///horizontal
                    (T[0][2]=='X' && T[2][2]=='X')   ///vertical
                ) && (T[1][2]==' ')
            ){
            T[1][2]='O';
        }else if( ///Baixo esquerda
                (
                    (T[0][0]=='X' && T[1][0]=='X')|| ///Vertical
                    (T[1][1]=='X' && T[0][2]=='X')|| ///Diagonal
                    (T[2][1]=='X' && T[2][2]=='X')|| ///Horizontal
                    (T[1][0]=='X' && T[2][1]=='X')   ///Tatica
                ) && (T[2][0]==' ')
            ){
            T[2][0]='O';
        }else if( ///Baixo meio
                (
                    (T[2][0]=='X' && T[2][2]=='X')|| ///Horizontal
                    (T[1][1]=='X' && T[0][1]=='X')   ///Vertical
                ) && (T[2][1]==' ')
            ){
            T[2][1]='O';
        }else if( ///Baixo direita
                (
                    (T[2][0]=='X' && T[2][1]=='X')|| ///Horizontal
                    (T[0][0]=='X' && T[1][1]=='X')|| ///Diagonal
                    (T[0][2]=='X' && T[1][2]=='X')|| ///Vertical
                    (T[2][1]=='X' && T[1][2]=='X')   ///Tatica
                ) && (T[2][2]==' ')
            ){
            T[2][2]='O';
        }else if(T[1][1]==' '){///Prioriza a jogada no meio, se ele não estiver preenchido
            T[1][1]='O';
        }else if(T[0][0]==' ' && T[1][1]=='O' && T[2][2]==' '){ ///TENTA GANHAR
            ///Diagonal Primaria
            j=rand()%2; ///Se a posição do meio estiver preenchida joga em um dos cantos aleatoriamente
            if(j==1){
                T[0][0]='O';
            }else{
                T[2][2]='O';
            }
        }else if(T[0][2]==' ' && T[1][1]=='O' && T[2][0]==' '){///Diagonal Secundaria
            j=rand()%2; ///Se a posição do meio estiver preenchida joga em um dos cantos aleatoriamente
            if(j==1){
                T[0][2]='O';
            }else{
                T[2][0]='O';
            }
        }else if(T[0][0]==' ' && T[0][1]=='O' && T[0][2]==' '){///Horizontal cima
            j=rand()%2; ///Se a posição do meio estiver preenchida joga em um dos cantos aleatoriamente
            if(j==1){
                T[0][0]='O';
            }else{
                T[0][2]='O';
            }
        }else if(T[1][0]==' ' && T[1][1]=='O' && T[1][2]==' '){///Horizontal meio
            j=rand()%2; ///Se a posição do meio estiver preenchida joga em um dos cantos aleatoriamente
            if(j==1){
                T[1][0]='O';
            }else{
                T[1][2]='O';
            }
        }else if(T[2][0]==' ' && T[0][1]=='O' && T[2][2]==' '){///Horizontal baixo
            j=rand()%2; ///Se a posição do meio estiver preenchida joga em um dos cantos aleatoriamente
            if(j==1){
                T[2][0]='O';
            }else{
                T[2][2]='O';
            }
        }else if(T[0][0]==' ' && T[1][0]=='O' && T[2][0]==' '){///Vertical esquerda
            j=rand()%2; ///Se a posição do meio estiver preenchida joga em um dos cantos aleatoriamente
            if(j==1){
                T[0][0]='O';
            }else{
                T[2][0]='O';
            }
        }else if(T[0][1]==' ' && T[1][1]=='O' && T[2][1]==' '){///Vertical meio
            j=rand()%2; ///Se a posição do meio estiver preenchida joga em um dos cantos aleatoriamente
            if(j==1){
                T[0][1]='O';
            }else{
                T[2][1]='O';
            }
        }else if(T[0][2]==' ' && T[1][2]=='O' && T[2][2]==' '){///Vertical direita
            j=rand()%2; ///Se a posição do meio estiver preenchida joga em um dos cantos aleatoriamente
            if(j==1){
                T[0][2]='O';
            }else{
                T[0][2]='O';
            }
        }else{///###JOGAR ALEATORIO### ///Caso ocorra alguma jogada que não esta no escopo acima (Altamente improvavel,mas ta por garantia)
            aux=0;
            do{
                j=rand()%10;
                switch(j){
                    case 0: //Primeira fileira
                        if(T[0][0]==' '){
                            T[0][0]='O';
                            aux=0;
                        }else{
                            aux=1;
                        }
                        break;
                    case 1:
                        if(T[0][1]==' '){
                            T[0][1]='O';
                            aux=0;
                        }else{
                            aux=1;
                        }
                        break;
                    case 2:
                        if(T[0][2]==' '){
                            T[0][2]='O';
                            aux=0;
                        }else{
                            aux=1;
                        }
                        break;
                    case 3: //Segunda fileira
                        if(T[1][0]==' '){
                            T[1][0]='O';
                            aux=0;
                        }else{
                            aux=1;
                        }
                        break;
                    case 4:
                        if(T[1][1]==' '){
                            T[1][1]='O';
                            aux=0;
                        }else{
                            aux=1;
                        }
                        break;
                    case 5:
                        if(T[1][1]==' '){
                            T[1][1]='O';
                            aux=0;
                        }else{
                            aux=1;
                        }
                        break;
                    case 6:
                        if(T[1][2]==' '){
                            T[1][2]='O';
                            aux=0;
                        }else{
                            aux=1;
                        }
                        break;
                    case 7://Terceira fileira
                        if(T[2][0]==' '){
                            T[1][2]='O';
                            aux=0;
                        }else{
                            aux=1;
                        }
                        break;
                    case 8:
                        if(T[2][1]==' '){
                            T[2][1]='O';
                            aux=0;
                        }else{
                            aux=1;
                        }
                        break;
                    case 9:
                        if(T[2][2]==' '){
                            T[2][2]='O';
                            aux=0;
                        }else{
                            aux=1;
                        }
                        break;
                }
            }while(aux==1);
        }
    }

}

int fim(char T[][l],char ve){ ///#VE SE O
    int h,v,f,d;

    f=0;
    v=0;
    h=0;
    d=0;

    v=vertical(T,ve);
    h=horizontal(T,ve);
    d=diagonal(T,ve);

    if(v==1){
        f=1;
    }
    if(h==1){
        f=1;
    }
    if(d==1){
        f=1;
    }

    return f;
}

int vertical(char T[][l],char ve){
    int x=0;

    if(T[1][0]==ve && T[2][0]==ve && T[0][0]==ve){ ///Cima esquerda
        x=1;
    }else if(T[1][1]==ve && T[2][1]==ve && T[0][1]==ve){ ///Cima meio
        x=1;
    }else if(T[1][2]==ve && T[2][2]==ve && T[0][2]==ve){ ///Cima direita
        x=1;
    }

    return x;
}

int horizontal(char T[][l],char ve){
    int x=0;

    if(T[0][0]==ve && T[0][1]==ve && T[0][2]==ve){ ///Lado cima
        x=1;
    }else if(T[1][0]==ve && T[1][1]==ve && T[1][2]==ve){ ///Cima meio
        x=1;
    }else if(T[2][0]==ve && T[2][1]==ve && T[2][2]==ve){ ///Cima baixo
        x=1;
    }

    return x;
}

int diagonal(char T[][l],char ve){
    int x=0;

    if(T[0][0]==ve && T[1][1]==ve && T[2][2]==ve){
        x=1;
    }else if(T[0][2]==ve && T[1][1]==ve && T[2][0]==ve){
        x=1;
    }

    return x;
}

int vazio(char T[][l]){
    int f,j,k;

    f=0;

    for(j=0;j<l;j++){
        for(k=0;k<l;k++){
            if(T[j][k]==' '){
                f++;
            }
        }
    }


    return f;
}
