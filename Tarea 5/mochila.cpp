#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void Mochila(int M, vector<pair<float, float>> p_b, vector<float>& x) {
  int pesoAct = 0;
  int i = p_b.size() - 1;
  while (pesoAct < M) {
    if (pesoAct + p_b[i].first <= M) {
      x[i] = 1;
      pesoAct += p_b[i].first;
    } else {
      x[i] = (M - pesoAct) / p_b[i].first;
      pesoAct = M;
    }
    i--;
  }
}
bool better(const pair<float, float>& x, const pair<float, float>& y) {
  return x.first / x.second > y.first / y.second;
};
int main() {
  // Ejemplo 1
  vector<pair<float, float>> pesos_ben = {{10, 10}, {3, 9}, {3, 9}, {4, 9}};
  // Ejemplo 2
  //  vector<pair<float, float>> pesos_ben = {{10, 10}, {3, 1}, {3, 1}, {4, 1}};
  vector<float> solucion(pesos_ben.size());
  int m = 10;
  sort(pesos_ben.begin(), pesos_ben.end(), &better);
  Mochila(m, pesos_ben, solucion);
  // imprimir solucion
  cout << "La solución es: " << endl;
  int ben_total = 0;
  for (int i = 0; i < solucion.size(); i++) {
    cout << solucion[i] << " de " << pesos_ben[i].first << "-" << pesos_ben[i].second << endl;
    ben_total += solucion[i] * pesos_ben[i].second;
  }
  cout << "Beneficio total: " << ben_total << endl;
}
