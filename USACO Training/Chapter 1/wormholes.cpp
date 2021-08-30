/*
ID: xckevin1
LANG: C++
TASK: wormhole
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n, answer;
int x[15], y[15];
int nxt[15];
int used[15];
int partner[15];

bool check(){
    for(int i = 1; i <= n; i++){
        int curr = i;
        for(int j = 1; j <= n; j++){
            curr = partner[nxt[curr]];
        }
        if(curr){
            return true;
        }
    }
    return false;
}

void solve(){
    int f = 1;
    while(used[f] && f <= n){
        f++;
    }
    if(f == n+1){
        if(check()){
            answer++;
        }
    }

    for(int s = f+1; s <= n; s++){
        if(!used[s]){
            used[f] = used[s] = true;
            partner[s] = f; partner[f] = s;
            solve();
            used[f] = used[s] = false;
            partner[s] = 0; partner[f] = 0;
        }
    }
}

int main(){
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");

    fin >> n;
    answer = 0;
    nxt[0] = 0;
    for(int i = 1; i <= n; i++){
        fin >> x[i] >> y[i];
        nxt[i] = 0;
        used[i] = 0;
        //partner[i] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i != j && y[i] == y[j] && x[i] <= x[j] && (nxt[i] == 0 || x[j] < x[nxt[i]])){
                nxt[i] = j;
            }
        }
    }

    solve();
    fout << answer << endl;
}