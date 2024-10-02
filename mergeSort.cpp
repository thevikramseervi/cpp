#include <iostream>

using namespace std;

void merge(int a[], int left, int mid, int right) {
  int i, j, k;
  int n1 = mid + 1 - left;
  int n2 = right - mid;

  int L[n1], R[n2];
  for (i = 0; i < n1; i++) {
    L[i] = a[left + i];
  }

  for (j = 0; j < n2; j++) {
    R[j] = a[mid + 1 + j];
  }

  i = 0, j = 0, k = left;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      a[k] = L[i];
      i++;
    } else {
      a[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    a[k] = R[j];
    j++;
    k++;
  }
}

void mergesort(int a[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    // Sort the left half
    mergesort(a, left, mid);

    // Sort the right half
    mergesort(a, mid + 1, right);

    // Merge the two sorted halves
    merge(a, left, mid, right);
  }
}

int main() {
  int n;
  cout << "Enter the no of elements: ";
  cin >> n;

  int a[n];
  cout << "Enter the array elements: ";
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  mergesort(a, 0, n - 1);

  cout << "Array after merge sort: ";
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }

  cout << "\n";
  return 0;
}