#include <bits/stdc++.h>
using namespace std;

int n, m;

struct Edge{
    int to;
    int cow;
    int first;
    int second;
};

vector<Edge> adj[100001];
int components[100001];
int compsizes[100001];
int compedgenum[100001];

void floodfill(int e, int id){
    components[e] = id;

    for(Edge p : adj[e]){
        int g = p.to;
        if(components[g] == -1){
            floodfill(g, id);
        }
    }
}

bool cycle(int start, vector<Edge> adjlist[]){

}

void solve(vector<Edge> adjlist[]){
    if(cycle(adjlist)){
        
    }
}

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        int f, s;
        cin >> f >> s;
        Edge e1;
        e1.to = s;
        e1.cow = i;
        e1.first = f;
        e1.second = s;
        adj[f].push_back(e1);
        Edge e2;
        e2.to = f;
        e2.cow = i;
        e2.first = f;
        e2.second = s;
        adj[s].push_back(e2);
    }

    fill(components, components+100001, -1);
    int compnum = 1;
    for(int f = 1; f <= n; f++){
        if(components[f] == -1){
            floodfill(f, compnum);
            compnum++;
        }
    }

    
    for(int j = 1; j <= m; j++){
        compsizes[components[j]]++;
        compedgenum[components[j]] += adj[j].size();
    }
    for(int i = 1; i < compnum; i++){
        compedgenum[i] /= 2;
    }

    int ans = 0;
    for(int i = 1; i < compnum; i++){
        int x = compedgenum[i];
        int y = compsizes[i];
        

        if(x > y){
            ans += (x-y);
        }
    }
    
    cout << ans << endl;
}