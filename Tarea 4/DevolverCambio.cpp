#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void DevolverCambio(int p, vector<int>& c, vector<int>& x) {
  int sum = 0;
  int j = c.size() - 1;
  while (sum != p) {
    while (c[j] > (p - sum) && j > 0) {
      j--;
    }
    if (j == -1) {
      cout << "No tiene solución" << endl;
      break;
    }
    x[j] = floor((p - sum) / c[j]);
    sum = sum + c[j] * x[j];
  }
}
int main() {
  vector<int> monedas = {1, 2, 5, 10, 20, 50, 100, 200};
  vector<int> solucion(monedas.size());
  int p = 389;
  DevolverCambio(p, monedas, solucion);

  cout << "El cambio es: " << endl;
  for (int i = 0; i < solucion.size(); i++) {
    cout << solucion[i] << " de " << monedas[i] << endl;
  }
  for (int i = 0; i < solucion.size(); i++) {
    cout << solucion[i] << " ";
  }
}
