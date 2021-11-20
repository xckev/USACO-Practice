#include <bits/stdc++.h>
using namespace std;

//jan 2012

int main () {
	int n, k;
	cin >> n >> k;
	vector<int> diff(n + 1); //difference to prev one
	for (int i = 0; i < k; i++) { 
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		diff[l]++;
		diff[r + 1]--;
	}

	int sol[1000000];
	int tot = 0;
	for (int i = 0; i < n; i++) {
		tot += diff[i];
		sol[i] = tot;
	}
	sort (sol, sol + n);
	cout << sol[n / 2] << '\n';
}