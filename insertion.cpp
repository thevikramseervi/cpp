#include <iostream>
using namespace std;

int main() {
  int a[100], n, ele, pos;

  cout << "Enter the size of array: ";
  cin >> n;

  cout << "Enter the array elements" << endl;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  cout << "Enter the element to insert: ";
  cin >> ele;

  cout << "Enter the position to insert the element: ";
  cin >> pos;

  for (int i = n; i > pos; i--) {
    a[i] = a[i - 1];
  }

  a[pos] = ele;
  n++;

  cout << "The array after inserting element is" << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }

  cout << endl;
  return 0;
}