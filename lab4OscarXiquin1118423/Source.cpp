#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

// Funci�n para generar un n�mero aleatorio entre 1 y 10
int generarNumeroAleatorio() {
    return rand() % 10;
}

// Funci�n para imprimir la carrera en una l�nea de 70 posiciones
void imprimirCarrera(const vector<int>& posicionestortuga, const vector<int>& pocisionesliebre) {
    for (int i = 1; i <= 70; i++) {
        bool tortugaPresente = false;
        bool liebrePresente = false;
        if (posicionestortuga[0] == i && pocisionesliebre[0] == i) {
            cout << "OUCH";
            tortugaPresente == true;
            liebrePresente == true;
        }
        else if (posicionestortuga[0] == i) {
            cout << "T";
            tortugaPresente = true;
        }
        else if (pocisionesliebre[0] == i) {
            cout << "H";
            liebrePresente = true;
        }


        if (!tortugaPresente && !liebrePresente) {
            cout << ' ';
        }
        
    }
    cout << endl;
}

int main() {
    srand(time(0));  // Inicializar la semilla del generador de n�meros aleatorios

    vector<int> posicionTortuga(1, 1);  // Inicialmente, la tortuga est� en la posici�n 1
    vector<int> posicionLiebre(1, 1);   // Inicialmente, la liebre est� en la posici�n 1

    cout << "�BANG!" << endl;
    cout << "�Y ARRANCAN!" << endl;

    while (true) {
        int pasoTortuga = generarNumeroAleatorio();
        int pasoLiebre = generarNumeroAleatorio();

        // Movimiento de la tortuga
        if (pasoTortuga >= 1 && pasoTortuga <= 5) {
            posicionTortuga[0] += 3;  // Paso veloz
        }
        else if (pasoTortuga >= 6 && pasoTortuga <= 7) {
            posicionTortuga[0] -= 6;  // Resbal�n
        }
        else {
            posicionTortuga[0] += 1;  // Paso lento
        }

        // Movimiento de la liebre
        if (pasoLiebre >= 1 && pasoLiebre <= 2) {
            posicionLiebre[0] += 0;  // Duerme (no se mueve)
        }
        else if (pasoLiebre >= 3 && pasoLiebre <= 4) {
            posicionLiebre[0] += 9;  // Salto grande
        }
        else if (pasoLiebre == 5) {
            posicionLiebre[0] -= 12;  // Resbal�n grande
        }
        else {
            posicionLiebre[0] += 1;  // Salto peque�o
        }

        // Asegurar que las posiciones no sean menores que 1
        if (posicionTortuga[0] < 1) {
            posicionTortuga[0] = 1;
        }
        if (posicionLiebre[0] < 1) {
            posicionLiebre[0] = 1;
        }

        imprimirCarrera(posicionTortuga, posicionLiebre);


        if (posicionTortuga[0] >= 70) {
            cout << "�LA TORTUGA GANA! �BRAVO!" << endl;
            break;
        }
        else if (posicionLiebre[0] >= 70) {
            cout << "La liebre gana. Ni hablar." << endl;
            break;
        }
        else if (posicionTortuga[0] >= 70 && posicionLiebre[0] >= 70) {
            cout << "Es un empate" << endl;
            break;
        }

    }

    return 0;
}