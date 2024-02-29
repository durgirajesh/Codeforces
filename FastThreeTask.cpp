#include <iostream>

using namespace std;

int minMoves(int arr[], int n) {
  int sum = 0, count1 = 0, count2 = 0;

  for (int i = 0; i < n; ++i) {
    sum += arr[i];
    switch (arr[i] % 3) {
      case 1:
        count1++;
        break;
      case 2:
        count2++;
        break;
    }
  }

  int remainder = sum % 3;
  if (remainder == 0) {
    return 0; 
  } else if (remainder == 1) {
    if (count1 > 0) {
      return 1; 
    } else {
      return 2; 
    }
  } else {
    if (count2 > 0) {
      return 1; 
    } else {
      return 1; 
    }
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    cout << minMoves(arr, n) << endl;
  }

  return 0;
}

