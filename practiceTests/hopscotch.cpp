#include <bits/stdc++.h>
using namespace std;

// feb 2015

int R, C, K;
int grid[100][100];
int dp[100][100];

int main(){
    ifstream fin("hopscotch.in");
    ofstream fout("hopscotch.out");
    fin >> R >> C >> K;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            fin >> grid[i][j];
        }
    }

    dp[0][0] = 1;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            for(int a = 0; a < i; a++){
                for(int b = 0; b < j; b++){
                    if(grid[i][j] != grid[a][b]){
                        dp[i][j] += dp[a][b];
                        dp[i][j] %= 1000000007;
                    }
                }
            }
        }
    }
    fout << dp[R-1][C-1] << endl;
}