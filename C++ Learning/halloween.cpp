#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
  int n, s;
  cin >> n >> s;
  int v[n];
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  sort(v, v+n);

  int total = 0;
  for(int i = 0; i <= n-2; i++){
    int r = s-v[i];
    total += upper_bound(v+i+1, v+n, r) - lower_bound(v+i+1, v+n, v[i]);
  }
  cout << total << endl;
 
}