#include <bits/stdc++.h>
using namespace std;

int N;

/*
int main(){
    cin >> N;
    vector<long long> sums(N+1);

    sums[0] = 0;
    for(int i = 0; i < N; i++){
        int e;
        cin >> e;
        sums[i+1] = sums[i] + e;
    }

    int ans = 0;
    for(int len = 1; len <= N; len++){
        for(int start = 1; start + len - 1 <= N; start++){
            long long s = sums[start+len-1] - sums[start-1];

            if(s % N == 0){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
*/
int main() {

	int N;
	cin >> N;

	vector<long long> M(N);
	long long psums = 0;
	M[psums] = 1;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		psums += a;
		// Remember to account for negative sums
		M[(psums % N + N) % N]++;
	}

	long long ans = 0;
	for (long long x : M) {
		/*
		Calculating the # of pairs.
		This calculates the pairs without
		duplicates and reverse groups.
		 */
		ans += x * (x - 1) / 2;
	}
	cout << ans << endl;
}