#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Enter n: ";
  cin >> n;

  // first line
  for (int i = 0; i < n - 1; i++) {
    cout << " ";
  }
  cout << "*" << endl;

  // line 1 to n
  for (int i = 1; i < n; i++) {
    for (int j = n - i - 1; j > 0; j--) {
      cout << " ";
    }
    cout << "*";
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    for (int j = 0; j < i - 1; j++) {
      cout << " ";
    }
    cout << "*" << endl;
  }

  // line n + 1 to 2n-2
  for (int i = 1; i < n - 1; i++) {
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    cout << "*";
    for (int j = n - 1; j > i; j--) {
      cout << " ";
    }
    for (int j = n - i - 1; j > 1; j--) {
      cout << " ";
    }
    cout << "*" << endl;
  }

  // last line
  for (int i = 0; i < n - 1; i++) {
    cout << " ";
  }
  cout << "*" << endl;

  return 0;
}
