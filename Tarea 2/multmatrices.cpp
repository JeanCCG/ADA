#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> add(const vector<vector<int>>& a, const vector<vector<int>>& b) {
  int n = a.size();
  vector<vector<int>> res(n, std::vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) res[i][j] = a[i][j] + b[i][j];
  return res;
}

vector<vector<int>> subtract(const vector<vector<int>>& a, const vector<vector<int>>& b) {
  int n = a.size();
  vector<vector<int>> res(n, std::vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) res[i][j] = a[i][j] - b[i][j];
  return res;
}

vector<vector<int>> strassen(const vector<vector<int>>& a, const vector<vector<int>>& b) {
  int n = a.size();
  if (n == 1) {
    return {{a[0][0] * b[0][0]}};
  }
  int k = n / 2;
  vector<vector<int>> a11(k, std::vector<int>(k)), a12(k, std::vector<int>(k)),
      a21(k, std::vector<int>(k)), a22(k, std::vector<int>(k));
  vector<vector<int>> b11(k, std::vector<int>(k)), b12(k, std::vector<int>(k)),
      b21(k, std::vector<int>(k)), b22(k, std::vector<int>(k));
  // Fill a11, a12, a21, a22, b11, b12, b21, b22
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      a11[i][j] = a[i][j];
      a12[i][j] = a[i][j + k];
      a21[i][j] = a[i + k][j];
      a22[i][j] = a[i + k][j + k];
      b11[i][j] = b[i][j];
      b12[i][j] = b[i][j + k];
      b21[i][j] = b[i + k][j];
      b22[i][j] = b[i + k][j + k];
    }
  }
  vector<vector<int>> p1 = strassen(a11, subtract(b12, b22));
  vector<vector<int>> p2 = strassen(add(a11, a12), b22);
  vector<vector<int>> p3 = strassen(add(a21, a22), b11);
  vector<vector<int>> p4 = strassen(a22, subtract(b21, b11));
  vector<vector<int>> p5 = strassen(add(a11, a22), add(b11, b22));
  vector<vector<int>> p6 = strassen(subtract(a12, a22), add(b21, b22));
  vector<vector<int>> p7 = strassen(subtract(a11, a21), add(b11, b12));
  vector<vector<int>> c11 = add(subtract(add(p5, p4), p2), p6);
  vector<vector<int>> c12 = add(p1, p2);
  vector<vector<int>> c21 = add(p3, p4);
  vector<vector<int>> c22 = subtract(subtract(add(p5, p1), p3), p7);
  // Combine c11, c12, c21, c22 into result
  vector<vector<int>> res(n, std::vector<int>(n));
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      res[i][j] = c11[i][j];
      res[i][j + k] = c12[i][j];
      res[i + k][j] = c21[i][j];
      res[i + k][j + k] = c22[i][j];
    }
  }
  return res;
}
int main() {
  vector<vector<int>> a = {{1, 2}, {3, 4}};
  vector<vector<int>> b = {{5, 6}, {7, 8}};
  vector<vector<int>> c = strassen(a, b);
  for (int i = 0; i < c.size(); i++) {
    for (int j = 0; j < c.size(); j++) {
      cout << c[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}