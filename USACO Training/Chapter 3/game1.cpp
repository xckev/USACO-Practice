/*
ID: xckevin1
LANG: C++
TASK: game1
*/

//dynamic prog

#include <bits/stdc++.h>
using namespace std;

int N;
int a[105];
int sum = 0;
int dp[105][105]; //dp[i][j] stores best score_1 - score_2 for the board indexes between i and j

int main(){
    ofstream fout ("game1.out");
    ifstream fin ("game1.in");
    fin >> N;

    for(int i = 1; i <= N; i++){
        int e;
        fin >> e;
        a[i] = e;
        sum += e;
        dp[i][i] = e;
    }

    for(int i = N; i >= 1; i--){
        for(int j = i+1; j <= N; j++){
            dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
        }
    }

    int score1 = (dp[1][N] + sum) / 2;
    int score2 = sum - score1;
    fout << score1 << " " << score2 << endl;

}