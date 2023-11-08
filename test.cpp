
#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> A = {1, 2, 3, 4, 5};
  int B[5] = {1, 2, 3, 4, 5};

  for (int i = 0; i < A.size(); i++) {
    cout << A[i] << " ";
  }

  for (const int& i : A) {
    cout << i << " ";
  }

  for (const int& i : B) {
    cout << i << " ";
  }

  return 0;
}