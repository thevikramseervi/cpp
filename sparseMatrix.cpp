#include <iostream>

using namespace std;

struct sparse {
  int row;
  int col;
  int val;
} s[10];

void readSparseMatrix() {
  int r, c, ele, pos = 0;
  cout << "Enter r & c: ";
  cin >> r >> c;

  cout << "Enter ele: " << endl;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> ele;
      if (ele != 0) {
        pos++;
        s[pos].row = i;
        s[pos].col = j;
        s[pos].val = ele;
      }
    }
  }
  s[0].row = r;
  s[0].col = c;
  s[0].val = pos;
}

void printSparseMatrix() {
  cout << "\nTriplet Representation" << endl;
  cout << "Row\tCol\tValue\n";
  for (int i = 0; i < s[0].val + 1; i++) {
    cout << s[i].row << "\t" << s[i].col << "\t" << s[i].val << endl;
  }
}

void search() {
  int key, found = 0;
  cout << "\nEnter key: ";
  cin >> key;
  for (int i = 0; i < s[0].val + 1; i++) {
    if (s[i].val == key) {
      cout << s[i].row << "\t" << s[i].col << endl;
      found = 1;
      break;
    }
  }
  if (!found) {
    cout << "The element not found" << endl;
  }
}

void transpose() {
  int n, pos;
  struct sparse trans[10];
  trans[0].row = s[0].col;
  trans[0].col = s[0].row;
  trans[0].val = s[0].val;
  n = trans[0].val;
  if (n > 0) {
    pos = 1;
    for (int i = 0; i < s[0].col; i++) {
      for (int j = 1; j < n + 1; j++) {
        if (s[j].col == i) {
          trans[pos].row = s[j].col;
          trans[pos].col = s[j].row;
          trans[pos].val = s[j].val;
          pos++;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    s[i] = trans[i];
  }
  printSparseMatrix();
}

int main() {
  readSparseMatrix();
  printSparseMatrix();
  search();
  transpose();
  return 0;
}