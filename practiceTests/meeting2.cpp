#include <bits/stdc++.h>
using namespace std;

// jan 2015

int n, m;
int bessieGrid[101][101];
int elsieGrid[101][101];

vector<bool> solve(int dist[][101]){
    vector<bool> dp[101]; //dp[field][time]
    for (int i = 0; i < 101; i++){
        dp[i].resize(100 * n + 1);
    }
    dp[0][0] = true;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < dp[i].size(); j++){
            if (!dp[i][j])
                continue;
            for (int k = i + 1; k < n; k++){
                if (dist[i][k] > 0){
                    dp[k][j + dist[i][k]] = true;
                }
            }
        }
    }
    return dp[n-1];
}

int main(){
    ifstream fin("meeting.in");
    ofstream fout("meeting.out");
    fin >> n >> m;

    for (int i = 0; i < m; i++){
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        a--; b--;
        bessieGrid[a][b] = c;
        elsieGrid[a][b] = d;
    }

    vector<bool> bessieCan = solve(bessieGrid);
    vector<bool> elsieCan = solve(elsieGrid);

    int best = 99999999;
    for (int i = 0; i < bessieCan.size(); i++){
        if (bessieCan[i] && elsieCan[i]){
            best = i;
            break;
        }
    }
    if (best == 99999999){
        fout << "IMPOSSIBLE" << endl;
    }
    else{
        fout << best << endl;
    }
}