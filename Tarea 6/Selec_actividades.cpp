#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool better(const pair<float, float>& x, const pair<float, float>& y) {
  return x.second < y.second;
}
void SelectActivities(vector<pair<float, float>>& actividades,
                      vector<pair<float, float>>& solucion) {
  sort(actividades.begin(), actividades.end(), &better);
  solucion.push_back(actividades[0]);
  int i = 1, prev = 0;
  while (i < actividades.size()) {
    pair<float, float> x = actividades[i];
    if (x.first >= solucion[prev].second) {
      solucion.push_back(x);
      prev++;
    }
    i++;
  }
}

int main() {
  /*
  Ejemplo:
  act.ini = { 1, 3, 0, 4, 3, 5, 6, 8 }
  act.fin = { 4, 5, 6, 7, 8, 9, 10, 11}
  */
  vector<pair<float, float>> actividades = {{1, 4}, {3, 5}, {0, 6},  {4, 7},
                                            {3, 8}, {5, 9}, {6, 10}, {8, 11}};
  vector<pair<float, float>> solucion;

  cout << "Ini - Fin " << endl;
  for (int i = 0; i < actividades.size(); i++) {
    cout << actividades[i].first << " - " << actividades[i].second << endl;
  }
  SelectActivities(actividades, solucion);

  cout << "\nLa solución es: " << endl;
  for (int i = 0; i < solucion.size(); i++) {
    cout << solucion[i].first << " - " << solucion[i].second << endl;
  }
}
