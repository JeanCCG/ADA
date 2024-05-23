#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
  double x, y;
};

double dist(Point p1, Point p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool compareX(Point p1, Point p2) { return p1.x < p2.x; }

bool compareY(Point p1, Point p2) { return p1.y < p2.y; }

void parMasCercano(vector<Point>& p, int c, int f, double& d, int& p1, int& p2) {
  if (f - c <= 2) {
    for (int i = c; i <= f; i++) {
      for (int j = i + 1; j <= f; j++) {
        double distancia = dist(p[i], p[j]);
        if (distancia < d) {
          d = distancia;
          p1 = i;
          p2 = j;
        }
      }
    }
    return;
  }

  int mid = (c + f) / 2;
  Point midPoint = p[mid];

  parMasCercano(p, c, mid, d, p1, p2);
  parMasCercano(p, mid + 1, f, d, p1, p2);

  vector<Point> midpoints;
  for (int i = c; i <= f; i++) {
    if (abs(p[i].x - midPoint.x) < d) {
      midpoints.push_back(p[i]);
    }
  }

  sort(midpoints.begin(), midpoints.end(), compareY);

  for (int i = 0; i < midpoints.size(); i++) {
    for (int j = i + 1; j < midpoints.size() && (midpoints[j].y - midpoints[i].y) < d; j++) {
      double distancia = dist(midpoints[i], midpoints[j]);
      if (distancia < d) {
        d = distancia;
        for (int k = c; k <= f; k++) {
          if (p[k].x == midpoints[i].x && p[k].y == midpoints[i].y) {
            p1 = k;
          }
          if (p[k].x == midpoints[j].x && p[k].y == midpoints[j].y) {
            p2 = k;
          }
        }
      }
    }
  }
}

int main() {
  vector<Point> points = {{0.5, 0.5}, {0, 3}, {0, 0}, {0, 0.25}, {1, 1}, {1.25, 1.25}, {2, 2}};
  sort(points.begin(), points.end(), compareX);
  int n = points.size();
  double d = 100000;
  int p1, p2;
  parMasCercano(points, 0, n - 1, d, p1, p2);

  cout << "Los puntos más cercanos son: (" << points[p1].x << ", " << points[p1].y << ") y ("
       << points[p2].x << ", " << points[p2].y << ")" << endl;
  cout << "La distancia entre ellos es: " << d << endl;

  return 0;
}