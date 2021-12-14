#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n, m;
vector<int> adj[100001][2];

void solve(int e, int g, int seen[]){
    seen[e] = 69420;
    for(int q : adj[e][g]){
        if(seen[q] != 69420){
            solve(q, g, seen);
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a][0].push_back(b);
        adj[b][1].push_back(a);
    }

    int seen[100001];
    solve(1, 0, seen);
    for(int i = 1; i <= n; i++){
        if(seen[i] != 69420){
            cout << "NO" << endl;
			cout << 1 << " " << i << endl;
            return 0;
        }
    }

    fill(seen, seen+100001, 0);

    solve(1, 1, seen);
    for(int i = 1; i <= n; i++){
        if(seen[i] != 69420){
            cout << "NO" << endl;
			cout << i << " " << 1 << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

}