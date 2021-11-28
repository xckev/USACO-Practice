#include <bits/stdc++.h>
using namespace std;

// open 2016

int main(){
    ofstream fout ("diamond.out");
    ifstream fin ("diamond.in");

	int n, k; 
    fin >> n >> k;
	int A[n];
	for (int i = 0; i < n; i++){
        cin >> A[i];
    }
	sort(A, A+n);

	int canTakeLeft[n];
	int l = 0;
    int r = 0;
	for (; l < n; l++) {
		while (r < n && A[r] - A[l] <= k){
            r++;
            
        }
		canTakeLeft[l] = r - l;
	}

	int maxValAfterI[n+1];
	maxValAfterI[n] = 0;
	for (int i = n-1; i >= 0; i--) {
		maxValAfterI[i] = max(maxValAfterI[i+1], canTakeLeft[i]);
	}

	int ans = 0;
	for (int l = 0; l < n; l++) {
		ans = max(ans, canTakeLeft[l] + maxValAfterI[l + canTakeLeft[l]]);
	}

	fout << ans << endl;
}