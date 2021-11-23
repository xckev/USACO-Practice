#include <bits/stdc++.h>
using namespace std;

//feb 2019

int N, K;
int arr[1001][1001];

int main(){
    ofstream fout ("paintbarn.out");
    ifstream fin ("paintbarn.in");
    fin >> N >> K;
    /*
    for(int i = 0; i < 1001; i++){
        for(int j = 0; j < 1001; j++){
            arr[i][j] = 0;
        }
    }*/

    for(int i = 1; i <= N; i++){
        int r1, c1, r2, c2;
        fin >> r1 >> c1 >> r2 >> c2;
        arr[r1][c1]++;
        arr[r1][c2]--;
        arr[r2][c1]--;
        arr[r2][c2]++;
    }

    int res = 0;
    for(int i = 0; i < 1001; i++){
        for(int j = 0; j < 1001; j++){
            //arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
            if(i) arr[i][j] += arr[i-1][j];
            if(j) arr[i][j] += arr[i][j-1];
            if(i && j) arr[i][j] -= arr[i-1][j-1];
            if(arr[i][j] == K){
                res++;
            }
        }
    }

    fout << res << endl;
}
