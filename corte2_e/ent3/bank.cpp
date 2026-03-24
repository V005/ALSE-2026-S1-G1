#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

// Variable global para el saldo y un mutex para evitar líos con los hilos
int saldo = 0;
mutex mtx;

// Función para depositar dinero de forma segura
void depositar(int cantidad, int id_hilo) {
    mtx.lock(); // Bloquear para que nadie más toque el saldo
    saldo += cantidad;
    cout << "[Hilo " << id_hilo << "] Se sumaron " << cantidad << ". Saldo actual: " << saldo << endl;
    mtx.unlock(); // Liberar cuando termine
}

int main() {
    vector<thread> hilos;
    cout << "--- Simulación de cuenta bancaria ---" << endl;

    // Crear 10 hilos que depositan 100 cada uno
    for (int i = 0; i < 10; ++i) {
        hilos.push_back(thread(depositar, 100, i + 1));
    }

    // Esperar a que todos los hilos terminen
    for (auto& t : hilos) {
        t.join();
    }

    cout << "Saldo final en la cuenta: " << saldo << endl;
    return 0;
}