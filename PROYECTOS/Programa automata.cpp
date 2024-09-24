#include <iostream>
#include <string>

using namespace std;

// Función que procesa la palabra según el autómata
bool procesar_palabra(const string& palabra) {
    // Estado inicial
    string estado = "q0";  // Usamos una cadena para identificar los estados

    // Iteramos sobre cada carácter de la palabra ingresada
    for (char c : palabra) {
        c = tolower(c);  // Convertimos el carácter a minúscula

        // Control de transiciones según el estado actual
        if (estado == "q0") {
            if (c == 'a') {
                estado = "q1";  // Transición a q1 con 'a'
            } else if (c == 'b') {
                estado = "q2";  // Transición a q2 con 'b'
            } else {
                return false;  // Carácter inválido
            }
        } else if (estado == "q1") {
            if (c == 'a' || c == 'b') {
                estado = "q1";  // Permanece en q1 con 'a' o 'b'
            } else {
                return false;  // Carácter inválido
            }
        } else if (estado == "q2") {
            if (c == 'b') {
                estado = "q2";  // Permanece en q2 con 'b'
            } else if (c == 'a') {
                estado = "q0";  // Regresa a q0 con 'a'
            } else {
                return false;  // Carácter inválido
            }
        }
    }

    // El autómata acepta la palabra si termina en el estado q1
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

