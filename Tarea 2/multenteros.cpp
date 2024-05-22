#include <cmath>
#include <iostream>
using namespace std;
long long fastMultiplication(long long x, long long y, int n, int base) {
  if (n == base) {
    return x * y;
  } else {
    long long m = n / 2;
    long long a = x / pow(10, m);
    long long b = x % (long long)pow(10, m);
    long long c = y / pow(10, m);
    long long d = y % (long long)pow(10, m);
    long long ac = fastMultiplication(a, c, m, base);
    long long bd = fastMultiplication(b, d, m, base);
    long long abcd = fastMultiplication(a + b, c + d, m, base) - ac - bd;
    return ac * pow(10, 2 * m) + abcd * pow(10, m) + bd;
  }
}
int main() {
  cout << fastMultiplication(1234, 5678, 4, 2) << endl;
  return 0;
}