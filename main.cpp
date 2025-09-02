/*
2 de septiembre de 2024
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
using namespace std;

/* ------------------------- Functions ------------------------- */
void diplayMenu() {
    cout << endl
         << "\n.----------------."
            "\n||  -{ MENU }-  ||"
            "\n.----------------."
            "\n| [1] Imprimir tablero  |"
            "\n| [2] Opción 2.  |"
            "\n|     [3] Salir  |"
            "\n.----------------.\n";
}

void endTitle() {
    cout << "\n  ^~^  , * ------------- *"
            "\n ('Y') ) |  Hasta luego! | "
            "\n /   \\/  * ------------- *"
            "\n(\\|||/)        FIN      \n";
}

void printBoard() {
    /* - Auxiliaries - */
    int i, j, size = 8;

    for (i = 0; i <= (size * 2); i++) {
        if (i % 2 == 0) {
            for (j = 0; j <= (size * 2); j++) {
                if (j == 0) {
                    cout << "   +";
                }
                cout << "---+";
            }
        } else {
            cout << "a";
        }
        cout << endl;
    }
}

int main() {
    /* ------------------------- Variables ------------------------- */
    /* - Menu - */
    int userChoice;
    bool run = true;

    /* --------------------------- Code ---------------------------- */
    while (run == true) {
        diplayMenu();
        while (!((cin >> userChoice) && (userChoice >= 1 && userChoice <= 3))) {
            cin.clear();
            cin.ignore();
        }

        switch (userChoice) {
            case 1:
                printBoard();
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