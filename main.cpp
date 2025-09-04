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
                cout << endl << "Opción 2";
                break;

            case 3:
                endTitle();
                run = false;
                break;
        }
    }

    return 0;
}
