#include <bits/stdc++.h>
using namespace std;

//dec 2019

int n, m;
char type[100002];
vector<int> adj[100002];
int component[100002];
int compnum;

void solve(int e){
    if(component[e] != 0){
        return;
    }
    else{
        component[e] = compnum;
        for(int f : adj[e]){
            if(type[f] == type[e]){
                solve(f);
            }
        }
    }
}

int main(){
    ifstream fin("milkvisits.in");
    ofstream fout("milkvisits.out");
    fill(component, component+100001, 0);

    fin >> n >> m;

    string s;
    fin >> s;
    for(int i = 1; i <= n; i++){
        type[i] = s[i-1];
    }

    for(int i = 0; i < n-1; i++){
        int a, b;
        fin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    compnum = 0;
    for(int i = 1; i <= n; i++){
        if(component[i] == 0){
            compnum++;
            solve(i);            
        }
    }

    string ans = "";
    for(int i = 1; i <= m; i++){
        int a, b;
        char c;
        fin >> a >> b >> c;
        if(type[a] == c || component[a] != component[b]){
            ans += "1";
        }
        else{
            ans += "0";
        }
    }
    fout << ans << endl;
}