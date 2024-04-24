#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n) {
  vector<int> countofelement(n, 0);
  for (int i = 0; i < n; i++)
  {
    countofelement[arr[i] - 1] = countofelement[arr[i] - 1] + 1;
  }
  int m = 0;
  int r = 0;
  for (int i = 0; i < n; i++)
  {
    if (countofelement[i] == 2)
    {
      r = i + 1;
    }
    if (countofelement[i] == 0)
    {
      m = i + 1;
    }
  }
  return {m, r};
}