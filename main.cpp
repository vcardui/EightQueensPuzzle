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

/* ------------ Resources / Documentation involved ------------- */
// std::random_shuffle, std::shuffle :
// https://en.cppreference.com/w/cpp/algorithm/random_shuffle.html

/* ------------------------- Libraries ------------------------- */
#include <stdlib.h> /* srand */
#include <time.h>   /* time */

#include <algorithm>
#include <cmath>    /* abs(), floor() */
#include <iostream> /* cin/cout */
#include <iterator>
#include <map>
#include <random>
#include <vector>

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

bool compare(pair<int, string>& a, pair<int, string>& b) {
    return a.second < b.second;
}

vector<int> newIndividual() {
    int i;
    vector<int> individual{0, 1, 2, 3, 4, 5, 6, 7};

    random_device rd;
    mt19937 random(rd());

    shuffle(individual.begin(), individual.end(), random);

    for (auto i = individual.begin(); i != individual.end(); ++i) {
        std::cout << *i << ' ';
    }
    cout << endl;

    return individual;
}

int fitness(vector<int> chromosome) {
    int a = 0, b = 1;
    int globalMax = 28, conflicts = 0;

    for (auto i = chromosome.begin(); i != chromosome.end(); ++i) {
        for (auto j = next(chromosome.begin()); j != chromosome.end(); ++j) {
            // cout << *i << "-" << *j << " ";

            // Same row
            if (*i == *j) {
                conflicts++;
            }

            // Same diagonal: |x1 - x2| == |y1 - y2|
            if (abs(a - b) == abs(*i - *j)) {
                conflicts++;
            }

            b++;
        }
        // cout << endl;
        a++;

        // cout << "\tConflicts: " << conflicts << endl;
    }

    cout << "Fitness: " << globalMax - conflicts << endl;

    return globalMax - conflicts;
}

void optimizeChessBoard(int populationSize, int generations) {
    int i, j, a;
    int currentPopulation = populationSize;

    int fitnessIndividual;
    vector<int> individual;

    map<int, vector<int>> allIndividuals;
    map<int, vector<int>> bestFitIndividuals;

    for (i = 0; i < generations; i++) {
        cout << endl << "----- { Generación #" << i + 1 << "} -----";

        for (j = 0; j < currentPopulation; j++) {
            cout << endl << "#" << j + 1 << "\t";
            individual = newIndividual();
            fitnessIndividual = fitness(individual);

            allIndividuals.insert({fitnessIndividual, individual});
        }
        // sort(allIndividuals.begin(), allIndividuals.end(), compare);

        currentPopulation = floor(currentPopulation / 2);

        for (a = 0; a < currentPopulation; a++) {
            bestFitIndividuals.insert(bestFitIndividuals.begin(),
                                      {fitnessIndividual, individual});
        }

        allIndividuals = bestFitIndividuals;
    }

    auto it = allIndividuals.begin();
    vector<int> coordinates = it->second;

    int queensCoordinates[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};

    for (auto x : coordinates) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (j == x) {
                    queensCoordinates[i][j] = 1;
                } else {
                    queensCoordinates[i][j] = 0;
                }
            }
        }
    }

    cout << endl << "Solución final:" << endl;

    printBoard(queensCoordinates);
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
