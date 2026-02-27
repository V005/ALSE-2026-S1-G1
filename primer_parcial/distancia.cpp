#include <iostream>
#include <cmath>
using namespace std;
struct Point {
   double x;
   double y;
};
double calcularDistanciaMasCercana(Point puntos[], int n,
    const Point &pUsuario,
    int &indiceMasCercano)
{
   double minDist = sqrt(pow(puntos[0].x - pUsuario.x, 2) +
                         pow(puntos[0].y - pUsuario.y, 2));
   indiceMasCercano = 0;
   for (int i = 1; i < n; i++) {
       double dist = sqrt(pow(puntos[i].x - pUsuario.x, 2) +
                          pow(puntos[i].y - pUsuario.y, 2));
       if (dist < minDist) {
           minDist = dist;
           indiceMasCercano = i;
       }
   }
   return minDist;
}
int main() {
   int n;
   cout << "Ingrese cantidad de puntos: ";
   cin >> n;
   Point puntos[n];
   for (int i = 0; i < n; i++) {
       cout << "Punto " << i << " (x y): ";
       cin >> puntos[i].x >> puntos[i].y;
   }
   Point usuario;
   cout << "Ingrese el punto de referencia (x y): ";
   cin >> usuario.x >> usuario.y;
   int indice;
   double distancia = calcularDistanciaMasCercana(puntos, n, usuario, indice);
   cout << "El punto mas cercano es: " << indice << endl;
   cout << "Distancia minima: " << distancia << endl;
   return 0;
}