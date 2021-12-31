#include <bits/stdc++.h>
using namespace std;

//feb 2020

int n;
int clocks[2501]; //this stores original
int c[2501]; //this one is manipulated every time
vector<int> adj[2501];

int solve(int e, int par){ 
    for(int f : adj[e]){
        if(f != par){
            c[f]++; //go to child and increase it
            c[e] += 12 - solve(f, e); //increase it by the amount needed to get the child to 12; so we dont have to look at the child ever again
            c[e] %= 12;
        }
    }
    c[par]++; //must go back to increase parent
    return c[e];
}

int main(){
    ifstream fin("clocktree.in");
    ofstream fout("clocktree.out");
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> clocks[i];
        clocks[i] %= 12;
    }

    for(int i = 0; i < n-1; i++){
        int a, b;
        fin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        
        copy(clocks, clocks+2501, c);
        solve(i, -1);
        if(c[i] == 1 || c[i] == 0){ //it can be 1 because the dfs forces it to return where it started, but this is not the case in the problem
            ans++;
        }
    }

    fout << ans << endl;
}
