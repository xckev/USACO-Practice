#include <bits/stdc++.h>
using namespace std;

//feb 2017

int N, K, B;
int arr[100001];


int main(){
    ofstream fout ("maxcross.out");
    ifstream fin ("maxcross.in");
    fin >> N >> K >> B;

    for(int i = 0; i < B; i++){
        int e;
        fin >> e;
        arr[e] = 1;
    }

    int psum[100001];
    psum[0] = 0;
    for(int i = 0; i < N; i++){
        psum[i+1] = psum[i] + arr[i+1];
    }

    int best = 99999999;
    for(int i = 1; i+K-1 <= N; i++){
        int s = psum[i+K-1] - psum[i-1];
        best = min(best, s);
    }

    fout << best << endl;
}