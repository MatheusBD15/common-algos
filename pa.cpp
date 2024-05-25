#include <bits/stdc++.h>

using namespace std;

// Sum of arithmetic series
//            = ((n / 2) * (2 * a + (n - 1) * d))
//            Where
//                a - First term
//                d - Common difference
//                n - No of terms
// o(1)
double sumOfAP(double a,
               double d,
               double n)
{
  double sum = (n / 2) *
               (2 * a +
                (n - 1) * d);
  return sum;
}

// o(1)
int Nth_of_AP(int a, int d, int N)
{
  // using formula to find the
  // Nth term t(n) = a(1) + (n-1)*d
  return (a + (N - 1) * d);
}

// o(n)
bool checkIsAP(int arr[], int n)
{
  unordered_set<int> st;
  int maxi = INT_MIN;
  int mini = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    maxi = max(arr[i], maxi);
    mini = min(arr[i], mini);
    st.insert(arr[i]);
  }
  // FINDING THE COMMON DIFFERENCE
  int diff = (maxi - mini) / (n - 1);
  int count = 0;

  // CHECK IF PRESENT IN THE HASHSET OR NOT
  while (st.find(maxi) != st.end())
  {
    count++;
    maxi = maxi - diff;
  }
  if (count == n)
    return true;

  return false;
}