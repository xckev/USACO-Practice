#include <bits/stdc++.h>
using namespace std;
 
int N;
bool ok[1000][1000];
 
long long solve() {
	long long ans = 0;
	for (int i = 0; i < N; i++) { //upper row i
		bool all_ones[N];
        fill(all_ones, all_ones+N, true);
		for (int j = i; j < N; j++) { //lower row j
			int run = 0;
			for (int k = 0; k < N; k++) {
				all_ones[k] = (all_ones[k] && ok[j][k]);
				if (all_ones[k] > 0){
                    run++;
                    ans += run;
                }
				else{
                    run = 0;
                }
			}
		}
	}
	return ans;
}
 
int main() {
	cin >> N;
	int pasture[N][N];
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
            cin >> pasture[i][j];
        }
    }

    //at least 100
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
            if(pasture[i][j] >= 100){
                ok[i][j] = true;
            }
            else{
                ok[i][j] = false;
            }
        }
    }

	long long ans = solve();

    //above 100
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if(pasture[i][j] > 100){
                ok[i][j] = true;
            }
            else{
                ok[i][j] = false;
            }
        }
    }
	ans -= solve();
 
	cout << ans << endl;
}