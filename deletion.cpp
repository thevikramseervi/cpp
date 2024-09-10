#include <iostream>
using namespace std;

int main() {
  int a[100], n, pos, ele;

  cout << "Enter the no of elements: ";
  cin >> n;

  cout << "Enter the array elements\n";
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  cout << "Enter the position to delete the element: ";
  cin >> pos;

  ele = a[pos];

  for (int i = pos; i < n - 1; i++) {
    a[i] = a[i + 1];
  }

  n--;

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  cout << "The deleterd element is: " << ele;

  cout << endl;
  return 0;
}