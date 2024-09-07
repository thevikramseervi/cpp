#include <iostream>
using namespace std;

void bubbleSort(int *a, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
}

int main() {
  int a[20], n;

  cout << "Enter N: ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  bubbleSort(a, n);

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }

  cout << endl;

  return 0;
}