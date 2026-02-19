#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0) return false;

    int original = x;
    long reversed = 0;

    while (x != 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    return original == reversed;
}

int main() {
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;

    if (isPalindrome(numero)) {
        cout << "Es un numero palindromo." << endl;
    } else {
        cout << "No es un numero palindromo." << endl;
    }

    return 0;
}