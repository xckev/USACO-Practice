/*
ID: xckevin1
LANG: C++
TASK: race3
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[55];
vector<int> rev[55];
bool visited[55];
bool visited2[55];
int n = 0;
bool p[55][55]; //p[i][j] = true means u can visit j from i

bool bfs1(int mid, int en) {
    memset(visited, 0, sizeof(visited));
    visited[mid] = 1;
    queue<int> Q;
    Q.push(0);
    visited[0] = 1;
    while (!Q.empty()) {
        int u = Q.front(); 
        Q.pop();
        if (u == en){
            return 1;
        }
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                Q.push(v);
            }
        }
    }
    
    return 0;
}

void bfs2(int src) {
    memset(visited, 0, sizeof(visited));
    queue<int> Q;
    Q.push(src);
    visited[src] = 1;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : rev[u]) {
            if (!visited[v]) {
                p[v][src] = 1;
                visited[v] = 1;
                Q.push(v);
            }
        }
    }
}

bool bfs3(int src) {
    memset(visited2, 0, sizeof(visited));
    queue<int> Q;
    Q.push(src);
    visited[src] = 1;
    while (!Q.empty()) {
        int u = Q.front(); 
        Q.pop();
        if (p[u][src]) {
            if (bfs1(src, u)){
                return 0;
            }
        }
        for (int v : adj[u]) {
            if (!visited2[v]) {
                visited2[v] = 1;
                Q.push(v);
            }
        }
    }
    return 1;
}

int main() {
    ofstream fout("race3.out");
    ifstream fin("race3.in");
    
    int x, mx = 0;
    fin >> x;
    while (x != -1) {
        mx = max(x, mx);
        if (x == -2){
            n++;
        }
        else {
            adj[n].push_back(x);
            rev[x].push_back(n);
        }
        fin >> x;
    }
    
    n = max(n, mx+1);
    
    vector<int> a1;
    vector<int> a2;
    for (int i = 1; i < n-1; i++) {
        if (!bfs1(i, n-1)){
            a1.push_back(i); //if we cannot reach end when removing this node
        }
    }
    
    memset(p, 0, sizeof(p));
    
    for (int i : a1) {
        bfs2(i); //all the nodes that can be visited before i
        if (bfs3(i)){ //if this point can be available stop
            a2.push_back(i);
        }
    }
    
    fout << a1.size();
    for (int i : a1){
        fout << " " << i;
    }
    fout << "\n" << a2.size();
    for (int i : a2){
        fout << " " << i;
    }
    fout << "\n";
    
}