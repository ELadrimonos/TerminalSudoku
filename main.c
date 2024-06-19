#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int finpartida(int array[9] [9]){
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            if (array [i] [j] == 0){
                return 1;
            }
        }
    }
    return 0;
}

int diezporciento(){
    int diez = rand() % 10;
    if (diez == 1){
        return 1;
    } else return 0;
}

int verificarvalor(int farray[9] [9], int anchura, int altura, int fvalor){
    if (farray [altura] [anchura] == fvalor){
        return 1;
    } else return 0;
}

void empezarjuego(){
    srand((time(NULL)));
    int solucion [9] [9], jugador [9] [9], x, y, valor, fallos = 0;
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            solucion [i] [j] = rand() % 9 + 1;
            if (diezporciento()){
                jugador [i] [j] = solucion [i] [j];
            } else {
                jugador [i] [j] = 0;
            }
        }
    }
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            printf("%d ",solucion [i] [j]);
        }
        printf("\n");
    }
    do{
        //system("clear");
        printf("\n-------------------\n");
        for (int i=0;i<9;i++){
        printf("|");
            for (int j=0;j<9;j++){
                printf("%d|",jugador [i] [j]);
            }
        printf("\n-------------------\n");
    }
        printf("\nDame una posición (Y:X) -> 1-9:\n");
        scanf(" %d%d", &y, &x);
        x--;
        y--;
        printf("Dame un valor (1-9)):\n");
        scanf(" %d", &valor);
        if (verificarvalor(solucion, x, y, valor)){
            printf("Valor correcto!\n");
            jugador [y] [x] = valor;
            printf("jugador [%d] [%d] -> %d\n", y, x, jugador [y] [x]);
        } else{
            printf("Valor incorrecto.\n");
            fallos++;
        }
    } while (finpartida(jugador) && fallos != 3);
        printf("Fin de la partida");
    if (fallos == 3){
        printf(" (Demasiados fallos).");
    } else printf(". Has ganado enhorabuena!!!");
}



void main()
{
    empezarjuego();
}
