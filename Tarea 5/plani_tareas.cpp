#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void PlanTareas(vector<pair<float, float>> p_b, vector<float>& x) {
  int instante = 0;
  int i = 0;
  while (instante < x.size()) {
    if (p_b[i].second >= instante + 1) {
      x[instante] = i;
      instante++;
    }
    i++;
  }
}
bool better(const pair<float, float>& x, const pair<float, float>& y) {
  if (x.second < y.second)
    return true;
  else if (x.second == y.second)
    return x.first > y.first;
  else
    return false;
};
int main() {
  /*
  Ejemplo:
  n = 6
  b = {20, 15, 10, 7, 5, 3}
  d = {3, 1, 1, 3, 1, 3}
  */
  vector<pair<float, float>> beneficio_plazo = {{20, 3}, {15, 1}, {10, 1}, {7, 3}, {5, 1}, {3, 3}};
  sort(beneficio_plazo.begin(), beneficio_plazo.end(), &better);
  vector<float> solucion(beneficio_plazo.back().second);

  cout << "Plazo - Beneficio " << endl;
  for (int i = 0; i < beneficio_plazo.size(); i++) {
    cout << beneficio_plazo[i].second << " - " << beneficio_plazo[i].first << endl;
  }
  PlanTareas(beneficio_plazo, solucion);

  cout << "\nLa solución es: " << endl;
  int ben_total = 0;
  for (int i = 0; i < solucion.size(); i++) {
    cout << beneficio_plazo[solucion[i]].second << " - " << beneficio_plazo[solucion[i]].first
         << endl;
    ben_total += beneficio_plazo[solucion[i]].first;
  }
  cout << "Beneficio total: " << ben_total << endl;
}
