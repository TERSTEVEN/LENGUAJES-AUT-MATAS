#include <iostream>
#include <string>

using namespace std;

// Funci�n que procesa la palabra seg�n el aut�mata
bool procesar_palabra(const string& palabra) {
    // Estado inicial
    string estado = "q0";  // Usamos una cadena para identificar los estados

    // Iteramos sobre cada car�cter de la palabra ingresada
    for (char c : palabra) {
        c = tolower(c);  // Convertimos el car�cter a min�scula

        // Control de transiciones seg�n el estado actual
        if (estado == "q0") {
            if (c == 'a') {
                estado = "q1";  // Transici�n a q1 con 'a'
            } else if (c == 'b') {
                estado = "q2";  // Transici�n a q2 con 'b'
            } else {
                return false;  // Car�cter inv�lido
            }
        } else if (estado == "q1") {
            if (c == 'a' || c == 'b') {
                estado = "q1";  // Permanece en q1 con 'a' o 'b'
            } else {
                return false;  // Car�cter inv�lido
            }
        } else if (estado == "q2") {
            if (c == 'b') {
                estado = "q2";  // Permanece en q2 con 'b'
            } else if (c == 'a') {
                estado = "q0";  // Regresa a q0 con 'a'
            } else {
                return false;  // Car�cter inv�lido
            }
        }
    }

    // El aut�mata acepta la palabra si termina en el estado q1
    return estado == "q1";
}

int main() {
    string palabra;

    // Lectura de la palabra desde el usuario
    cout << "Ingrese una palabra: ";
    cin >> palabra;

    // Procesar la palabra
    if (procesar_palabra(palabra)) {
        cout << "La palabra es aceptada por el automata." << endl;
    } else {
        cout << "La palabra no es aceptada por el automata." << endl;
    }

    return 0;
}

