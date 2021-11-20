//jan 2017

#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);

	int N;
	cin >> N;
	
    vector<int> H(N + 1), P(N + 1), S(N + 1);
	for (int i = 0; i < N; i++) {
		H[i + 1] = H[i];
		P[i + 1] = P[i];
		S[i + 1] = S[i];

		char cur;
		cin >> cur;
		if (cur == 'P') P[i + 1]++;
		else if (cur == 'H') H[i + 1]++;
		else S[i + 1]++;
	}

	int maxwins = 0;

	for (int i = 1; i <= N; i++) {
		maxwins = max(maxwins, H[i] + P[N] - P[i]);
        maxwins = max(maxwins, H[i] + S[N] - S[i]);
        maxwins = max(maxwins, P[i] + S[N] - S[i]);
        maxwins = max(maxwins, P[i] + H[N] - H[i]);
        maxwins = max(maxwins, S[i] + H[N] - H[i]);
        maxwins = max(maxwins, S[i] + P[N] - P[i]);
	}

	cout << maxwins << '\n';
}
