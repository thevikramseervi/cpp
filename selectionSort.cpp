#include <iostream>
using namespace std;

void selectionSort(int *a, int n) {
  for (int i = 0; i < n - 1; i++) {
    int pos = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[pos]) {
        pos = j;
      }
    }
    if (i != pos) {
      int temp = a[i];
      a[i] = a[pos];
      a[pos] = temp;
    }
  }
}

int main() {
  int a[20], n;

  cout << "Enter the number of elements: ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  selectionSort(a, n);

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }

  return 0;
}