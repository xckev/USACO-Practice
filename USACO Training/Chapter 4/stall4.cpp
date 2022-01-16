/*
ID: xckevin1
LANG: C++
TASK: stall4
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
int adj[510][510]; //bipartite graph
int previous[510];
bool reachable[510];

bool bfs(int start, int end){
    memset(reachable, false, sizeof(reachable)); //memset is faster than fill !
    reachable[start] =true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int y = 1; y <= n+m+2; y++){
            if(adj[x][y] > 0 && !reachable[y]){
                reachable[y] = true;
                previous[y] = x;
                q.push(y);
            }
        }
    }
    return reachable[end];
}

int maxflow(int start, int end){
    int totalflow = 0;
    while(bfs(start, end)){
        int flow = 1;
        for(int x = end; x != start; x = previous[x]){
            adj[previous[x]][x]--;
            adj[x][previous[x]]++;
        }
        totalflow++;
    }
    return totalflow;
}

int main(){
    ifstream fin("stall4.in");
    ofstream fout("stall4.out");
    fin >> n >> m;

    for(int i = 1; i <= n; i++){
        int c;
        fin >> c;
        for(int j = 0; j < c; j++){
            int x;
            fin >> x;
            adj[1+i][1+n+x]++; //1 is source, 1+i is cow node, 1+n+x is stall node
        }
    }

    for(int i = 1; i <= n; i++){
        adj[1][1+i]++; //building edge from source to cows
    }
    for(int i = 1; i <= n; i++){
        adj[1+n+i][n+m+2]++; //building edge from stalls to sink
    }

    int ans = maxflow(1, n+m+2);
    fout << ans << endl;
}