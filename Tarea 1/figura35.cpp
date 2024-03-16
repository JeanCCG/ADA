#include <iostream>
#include <list>
#include <vector>
using namespace std;

float Addition(float a, float b) { return a + b; }

float Subtraction(float a, float b) { return a - b; }

float Multiplication(float a, float b) { return a * b; }

float Division(float a, float b) {
  if (b != 0)
    return a / b;
  else {
    cout << "Error: División por cero." << endl;
    return 0.0f;
  }
}

int main() {
  typedef float (*lpfnOperation)(float, float);
  // CVector of pointer to functions
  lpfnOperation vpf[4] = {&::Addition, &::Subtraction, &::Multiplication,
                          &::Division};
  float a, b, c;
  int opt;

  // enter the operands
  cout << "enter the operands" << endl;
  cin >> a >> b;
  // enter the operation 0-Addition, 1-Subtraction, 2-Multiplication, 3-Division
  cout << "enter the operation 0-Addition, 1-Subtraction, 2-Multiplication, "
          "3-Division"
       << endl;
  cin >> opt;
  // The next line replaces the switch and replaces the whole switch
  c = (*vpf[opt])(a, b);
  cout << c;
}