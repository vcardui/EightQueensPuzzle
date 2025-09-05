/*
4 de septiembre de 2024
Vanessa Reteguín - 375533

Problema de las 7 reinas

Universidad Aútonoma de Aguascalientes
Ingeniería en Computación Inteligente (ICI)
Semestre V

Grupo 5 - A
Optimización Inteligente
Luis Fernando Gutiérrez Marfileño

Instrucciones:
*/

/* ------------------------- Libraries ------------------------- */
#include <stdlib.h> /* srand */
#include <time.h>   /* time */

#include <iostream> /* cin/cout */
#include <map>
using namespace std;

/* ------------------------- Functions ------------------------- */
void diplayMenu() {
    cout << endl
         << "\n.-----------------------."
            "\n||      -{ MENU }-     ||"
            "\n.-----------------------."
            "\n| [1] Imprimir tablero  |"
            "\n| [2] Optimizar tablero |"
            "\n|            [3] Salir  |"
            "\n.-----------------------.\n";
}

void endTitle() {
    cout << "\n  ^~^  , * ------------- *"
            "\n ('Y') ) |  Hasta luego! | "
            "\n /   \\/  * ------------- *"
            "\n(\\|||/)        FIN      \n";
}

void printBoard(int queensCoordinates[][8]) {
    /* - Auxiliaries - */
    int i, j, k = 1, size = 8;

    cout << "     ";
    for (i = 0; i < size; i++) {
        cout << (char)(65 + i) << "   ";
    }
    cout << endl;

    for (i = 0; i <= (size * 2); i++) {
        if (i % 2 == 0) {
            for (j = 0; j < size; j++) {
                if (j == 0) {
                    cout << "   +";
                }
                cout << "---+";
            }
        } else {
            cout << " " << k;
            for (j = 0; j < size; j++) {
                if (j == 0) {
                    cout << " |";
                }

                if (queensCoordinates[k - 1][j] == 1) {
                    if (j % 2 == 0 && (k % 2 == 0)) {
                        cout << "█♛█|";
                    } else if (j % 2 == 1 && (k % 2 == 1)) {
                        cout << "█♛█|";
                    } else {
                        cout << " ♛ |";
                    }
                } else {
                    if (j % 2 == 0 && (k % 2 == 0)) {
                        cout << "███|";
                    } else if (j % 2 == 1 && (k % 2 == 1)) {
                        cout << "███|";
                    } else {
                        cout << "   |";
                    }
                }
            }
            k++;
        }

        cout << endl;
    }
}

int randomNum(int lower, int upper) {
    int num;

    num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

void newRandomIndividual() {
    int i;
    int individual[8];  // = 24 bits

    for (i = 0; i < 8; i++) {
        individual[i] = randomNum(0, 8);
        cout << individual[i];
    }

    cout << endl;
}

void optimizeChessBoard(int populationSize, int generations) {
    int i;

    for (i = 0; i < populationSize; i++) {
        cout << "#" << i + 1 << " ";
        newRandomIndividual();
    }
}

int main() {
    /* ------------------------- Variables ------------------------- */
    /* - Menu - */
    int userChoice;
    bool run = true;

    /* - Chess Board - */
    int queensCoordinates[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};

    /* - Algorithm constraints - */
    int populationSize, generations;

    /* Random numbers seed */
    srand(time(NULL));

    /* --------------------------- Code ---------------------------- */
    while (run == true) {
        diplayMenu();
        while (!((cin >> userChoice) && (userChoice >= 1 && userChoice <= 3))) {
            cin.clear();
            cin.ignore();
        }

        switch (userChoice) {
            case 1:
                printBoard(queensCoordinates);
                break;

            case 2:
                cout << "Ingrese tamaño de la población: ";
                while (!((cin >> populationSize) &&
                         (populationSize >= 1 && populationSize <= 200))) {
                    cin.clear();
                    cin.ignore();
                }

                cout << "Ingrese el número de generaciones: ";
                while (!((cin >> generations) &&
                         (generations >= 1 && generations <= 200))) {
                    cin.clear();
                    cin.ignore();
                }

                optimizeChessBoard(populationSize, generations);

                break;

            case 3:
                endTitle();
                run = false;
                break;
        }
    }

    return 0;
}
