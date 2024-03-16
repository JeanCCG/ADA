#include <iostream>
using namespace std;
/*
void Insert(int);
void Resize();
void Insert(int *& rpVect, int& rnCount, int& rnMax, int elem)
{
  if( rnCount == rnMax ) // Verify the overflow
    Resize(rpVect, rnMax); // Resize the vector before inserting elem
  rpVect[rnCount++] = elem; // Insert the element at the end of the sequence
}
void Resize(int *& rpVect, int& rnMax)
{
  const int delta = 10; // Used to increase the vector size
  int *pTemp, i;
  pTemp = new int[rnMax + delta];  // Alloc a new vector
  for (i = 0; i < rnMax; i++)      // Transfer the elements
    pTemp[i] = rpVect[i];          // we can also use the function memcpy
  delete[] rpVect;                 // delete the old vector
  rpVect = pTemp;                  // Update the pointer
  rnMax += delta; // The Max has to be increased by delta
}*/
struct Vector {
  int *m_pVect = NULL,  // Pointer to the buffer
      m_nCount = 0,     // Control how many elements are actually used
      m_nMax = 0,       // Control how many are allocated as maximum
      m_nDelta = 10;    // To control the growing
};
void Insert(Vector *, int);
void Resize(Vector *);

void Insert(Vector *pThis, int elem) {
  if (pThis->m_nCount == pThis->m_nMax)  // Verify the overflow
    Resize(pThis);  // Resize the vector before inserting elem
  // Insert the element at the end of the sequence
  pThis->m_pVect[pThis->m_nCount++] = elem;
}
void Resize(Vector *pThis) {
  pThis->m_pVect = (int *)realloc(
      pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));
  // The Max has to be increased by delta
  pThis->m_nMax += pThis->m_nDelta;
}
void print(Vector *pThis) {
  cout << "Vector: " << endl;
  for (int *i = pThis->m_pVect; i < pThis->m_pVect + pThis->m_nCount; i++)
    cout << *i << " ";
  cout << "Conteo: " << pThis->m_nCount << " , Max: " << pThis->m_nMax << endl;
}
int main() {
  Vector v;
  for (int i = 0; i < 12; i++) {
    Insert(&v, i);
    print(&v);
  }
}