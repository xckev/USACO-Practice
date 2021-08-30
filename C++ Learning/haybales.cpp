#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n, q, t1, t2;
int numbers[100000];
int main() {
  cin >> n >> q;
  for(int i = 0; i < n; i++){
    cin >> numbers[i];
  }
  sort(numbers, numbers+n);
  for(int i = 0; i < q; i++){
    cin >> t1 >> t2;
    int result = upper_bound(numbers, numbers+n, t2) - lower_bound(numbers, numbers+n, t1);
    //cout << upper_bound(numbers, numbers+n, t2) << ", " << lower_bound(numbers, numbers+n, t1) << endl;
    cout << result << endl;
  }
}