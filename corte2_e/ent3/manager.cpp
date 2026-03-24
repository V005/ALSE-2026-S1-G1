#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> tokens;
    string comando, usuario;
    int tiempo;

    cout << "Sistema de Tokens (Comandos: add, check, exit)" << endl;

    while (cin >> comando && comando != "exit") {
        if (comando == "add") {
            cin >> usuario >> tiempo;
            tokens[usuario] = tiempo;
            cout << "Token creado para " << usuario << endl;
        } else if (comando == "check") {
            cin >> usuario >> tiempo;
            // Validar si el token sigue vigente o ya expiró
            if (tokens.count(usuario) && tokens[usuario] >= tiempo) {
                cout << "Acceso CONCEDIDO" << endl;
            } else {
                cout << "Acceso DENEGADO (Token expirado)" << endl;
            }
        }
    }
    return 0;
}