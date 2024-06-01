#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool better(const float& x, const float& y) { return x < y; }
void AlmacenCintas(vector<float>& ficheros, vector<float>& solucion) {
  sort(ficheros.begin(), ficheros.end(), &better);
  solucion[0] = ficheros[0];
  int i = 1;
  while (i < ficheros.size()) {
    solucion[i] = ficheros[i];
    i++;
  }
}

int main() {
  /*
  Ejemplo:
  n = 3
  (l1,l2,l3) = {5, 10, 3};

  */
  vector<float> cintas = {5, 10, 3};
  vector<float> solucion(cintas.size());
  AlmacenCintas(cintas, solucion);
  cout << "\nLa solución es: " << endl;
  for (int i = 0; i < solucion.size(); i++) {
    cout << solucion[i] << " ";
  }
  int optimo = 0;
  for (int i = 0; i < solucion.size(); i++) {
    optimo += solucion[i] * (solucion.size() - i);
  }

  cout << "\nEl valor más óptimo es: " << optimo << endl;
}
