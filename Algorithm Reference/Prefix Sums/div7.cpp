#include <bits/stdc++.h>
using namespace std;

//jan 2016

int N;
long long sums[50001];

int main(){
    ofstream fout ("div7.out");
    ifstream fin ("div7.in");
    fin >> N;

    for(int i = 1; i <= N; i++){
        int e;
        fin >> e;

        sums[i] = sums[i-1] + e;
    }

    bool done = false;
    for(int len = N; len >= 1; len--){
        for(int start = 1; start + len - 1 <= N; start++){
            long long sum = sums[start + len - 1] - sums[start-1];
            //cout << sums[start + len - 1] << " - " << sums[start-1] << endl;
            if(sum % 7 == 0){
                fout << len << endl;
                done = true;
                break;
            }
        }
        if(done){
            break;
        }
    }
}