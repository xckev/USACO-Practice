#include <bits/stdc++.h>
using namespace std;

//feb 2018

int n, b;
int f[251];
int s[251];
int d[251];
bool seen[251][251]; //seen pos, shoe combo before

int ans = 99999999;

void solve(int pos, int shoe){
    if(seen[pos][shoe]){
        return;
    }
    else{
        seen[pos][shoe] = true;
    }

    if(pos == n){
        ans = min(ans, shoe-1);
        return;
    }

    for(int newpos = pos+1; newpos <= n && newpos - pos <= d[shoe]; newpos++){
        if(f[newpos] <= s[shoe]){
            solve(newpos, shoe);
        }
    }
    for(int newshoe = shoe+1; newshoe <= b; newshoe++){
        if(f[pos] <= s[newshoe]){
            solve(pos, newshoe);
        }
    }
}

int main(){
    ofstream fout ("snowboots.out");
    ifstream fin ("snowboots.in");
    fin >> n >> b;

    for(int i = 1; i <= n; i++){
        fin >> f[i];
    }

    for(int i = 1; i <= b; i++){
        fin >> s[i] >> d[i];
    }

    solve(1, 1);
    fout << ans << endl;

}