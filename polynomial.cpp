#include <cmath>
#include <iostream>

using namespace std;

typedef struct polynomial {
  int coeff;
  int expo;
} poly;

void readPolynomial(poly p[], int n) {
  for (int i = 0; i < n; i++) {
    cout << "Enter the coeff and expo of term " << i + 1 << ": ";
    cin >> p[i].coeff >> p[i].expo;
  }
}

void printPolynomial(poly p[], int n) {
  for (int i = 0; i < n - 1; i++) {
    cout << p[i].coeff << " (x^" << p[i].expo << ") + ";
  }
  cout << p[n - 1].coeff << " (x^" << p[n - 1].expo << ")" << endl;
}

int addPolynomial(poly p1[], poly p2[], int n1, int n2, poly p3[]) {
  int i = 0, j = 0, k = 0;

  while (i < n1 && j < n2) {
    if (p1[i].expo == p2[j].expo) {
      p3[k].coeff = p1[i].coeff + p2[j].coeff;
      p3[k].expo = p1[i].expo;
      i++;
      j++;
      k++;
    } else if (p1[i].expo < p2[j].expo) {
      p3[k] = p1[i];
      i++;
      k++;
    } else {
      p3[k] = p2[j];
      j++;
      k++;
    }
  }

  while (i < n1) {
    p3[k] = p1[i];
    i++;
    k++;
  }

  while (j < n2) {
    p3[k] = p2[j];
    j++;
    k++;
  }

  return k;
}

void evaluate(poly p[], int n) {
  int x, sum = 0;

  cout << "\nEnter the value of x: ";
  cin >> x;

  for (int i = 0; i < n; i++) {
    sum += p[i].coeff * pow(x, p[i].expo);
  }

  cout << "The sum of the polynomial is " << sum << endl;
}

int main() {
  poly p1[10], p2[10], p3[20];
  int n1, n2, n3;

  cout << "\nEnter the no of terms in poly p1: ";
  cin >> n1;

  readPolynomial(p1, n1);
  printPolynomial(p1, n1);

  cout << "\nEnter the no of terms in poly p2: ";
  cin >> n2;

  readPolynomial(p2, n2);
  printPolynomial(p2, n2);

  n3 = addPolynomial(p1, p2, n1, n2, p3);

  cout << "\nThe resultant polynomial is" << endl;
  printPolynomial(p3, n3);

  evaluate(p3, n3);

  cout << endl;
  return 0;
}