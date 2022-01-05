#include <bits/stdc++.h>
using namespace std;

int n, m;

int ans[10002];
vector<pair<int, int>> events;
int starts[5001];
int endss[5001];

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        starts[a]++;
        endss[b]++;
    }
    
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= m; j++){
            ans[i+j] += starts[i] * starts[j];
            ans[i+j+1] -= endss[i] * endss[j];
        }
    }

    long total = 0;
    for(int i = 0; i <= 2*m; i++){
        total += ans[i];
        cout << total << endl;
    }
    
    
}