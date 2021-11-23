/*
ID: xckevin1
LANG: C++
TASK: kimbits
*/

#include <bits/stdc++.h>
using namespace std;

int N, L;
long long I;

long long arr[32][32]; //how many strings can be made with length N and L 1's
long long num[32][32]; //size of subset with strings of length N and at most L 1's

int main(){
    ofstream fout ("kimbits.out");
    ifstream fin ("kimbits.in");
    fin >> N >> L >> I;

    arr[0][0] = 1;
    for(int i = 0; i < 32; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0){
                arr[i][j] = 1;
            }
            else{
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
    }

    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 32; j++){
            for(int k = 0; k <= j; k++){
                num[i][j] += arr[i][k];
            }
        }
    }
    for(int i = N; i>= 1; i--){
        long long x = num[i-1][L];
        if(I > x){
            fout << "1";
            I -= x;
            L--;
        }
        else{
            fout << "0";
        }
    }
    fout << endl;
}