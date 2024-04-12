#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

const int ROW = 6;
const int COL = 6;

void filling(int tablero[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            tablero[i][j] = 0;
        }
    }
}

void printing(int tablero[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {   
        printf("\t");
        for (int j = 0; j < COL; j++)
        {
            if(tablero[i][j] == 0){
                printf("❎");
            }else if(tablero[i][j] == 1){
                printf("🚢");
            }else if(tablero[i][j] == 2){
                printf("💥");
            }
            else if(tablero[i][j] == 3){
                printf("❌");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void barcosAleatorios(int tablero[ROW][COL])
{
    srand(time(NULL));

    for (int i = 0; i < 3; i++)
    {
        int filaRandom = rand() % 6;
        int columnaRandom = rand() % 6;

        if (tablero[filaRandom][columnaRandom] == 1)
        {
            i--;
        }
        else
        {
            tablero[filaRandom][columnaRandom] = 1;
        }
    }
}

void posicionarBarcos(int tablero[ROW][COL])
{

    int x, y;
    for (int i = 0; i < 3; i++)
    {
        printf("Coordenadas para el Barco N°%d\n", i + 1);

        do
        {
            printf("Ingrese la coordenada X: ");
            scanf("%d", &x);
        } while (x < 0 || x >= ROW);

        do
        {
            printf("Ingrese la coordenada Y: ");
            scanf("%d", &y);
        } while (y < 0 || y >= COL);

        if (tablero[x][y] == 1)
        {
            printf("¡Error! La posición ya está ocupada. Por favor, elija otra.\n");
            i--;
        }
        else
        {
            tablero[x][y] = 1;
        }
        printf("\n");
    }
}

void atacarPC(int tablero[ROW][COL])
{
    int x, y;
    bool posicionRepetida;

    do
    {
        printf("Ingrese la coordenada X para su ataque: ");
        scanf("%d", &x);

        printf("Ingrese la coordenada Y para su ataque: ");
        scanf("%d", &y);

        // Verificar si la posición ya ha sido atacada
        if (tablero[x][y] == 2 || tablero[x][y] == 3)
        {
            printf("No puedes atacar la misma posición dos veces.\n");
            posicionRepetida = true;
        }
        else
        {
            posicionRepetida = false;
            if (tablero[x][y] == 1)
            {
                printf("¡Ha golpeado un barco enemigo!\n");
                tablero[x][y] = 2;
            }
            else
            {
                printf("El ataque ha fallado.\n");
                tablero[x][y] = 3;
            }
        }
    } while (posicionRepetida);
}

void atacarJugador(int tablero[ROW][COL])
{
    int x, y;
    bool posicionRepetida;

    srand(time(NULL));

    do
    {
        x = rand() % 6;
        y = rand() % 6;

        if (tablero[x][y] != 2 && tablero[x][y] != 3)
        {
            posicionRepetida = false;
            printf("La computadora ha atacado la posicion: %d %d", x, y);
            if (tablero[x][y] == 1)
            {
                printf("\n¡La computadora ha golpeado un barco enemigo!\n");
                tablero[x][y] = 2;
            }
            else
            {
                printf("\nLa computadora ha fallado el ataque!\n");
                tablero[x][y] = 3;
            }
        }
        else
        {
            posicionRepetida = true;
        }

    } while (posicionRepetida);
}
int barcosHundidos(int tablero[ROW][COL])
{
    int barcosHundidos = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (tablero[i][j] == 2)
            {
                barcosHundidos++;
            }
        }
    }
    return barcosHundidos;
}

void simularJuego(int tableroPC[ROW][COL], int tableroJugador[ROW][COL])
{

    // Filling
    filling(tableroPC);
    filling(tableroJugador);
    barcosAleatorios(tableroPC);

    // Positioning
    posicionarBarcos(tableroJugador);
    printing(tableroJugador);

    printf("Que empiece la batalla Naval!\n");

    do
    {
        int barcosGolpeadosPC = 0, barcosGolpeadosJugador = 0;

        printf("Turno del jugador: ");
        atacarPC(tableroPC);
        printing(tableroPC);

        barcosGolpeadosPC = barcosHundidos(tableroPC);

        if (barcosGolpeadosPC == 3)
        {
            printf("¡Felicitaciones, has ganado!\n");
            break; // Terminar el juego si el jugador se queda sin vidas
        }

        printf("Turno de la computadora: ");
        atacarJugador(tableroJugador);
        printing(tableroJugador);

        barcosGolpeadosJugador = barcosHundidos(tableroJugador);

        if (barcosGolpeadosJugador == 3)
        {
            printf("¡La computadora ha ganado!\n");
            break; // Terminar el juego si el jugador se queda sin vidas
        }
        printf("\n \n");

    } while (true);
}

int main(void)
{
    int tableroPC[ROW][COL];
    int tableroJugador[ROW][COL];

    simularJuego(tableroPC, tableroJugador);
}
