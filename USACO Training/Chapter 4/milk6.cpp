/*
ID: xckevin1
LANG: C++
TASK: milk6
*/

#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, c, x; //edge goes from u to v with cost x and index x
};

int cap[35][35], rescap[35][35];
int n, m;
int p[35];
int dist[35];
bool vis[35];
Edge edge[1005];

int getMaxDist() { //maximum distance edge that has not been visited yet
    int mx = -1, ind = -1;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > mx && !vis[i]) {
            mx = dist[i];
            ind = i;
        }
    }
    return ind;
}

bool dijkstra() { //use dijkstra to get path with maximum flow
    memset(p, -1, sizeof(p));
    memset(dist, -1, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[1] = INT_MAX;
    while (1) {
        int u = getMaxDist();
        if (u == -1){
            break;
        }
        vis[u] = 1;
        for (int v = 1; v <= n; v++) {
            if (cap[u][v] && !vis[v] && dist[v] < cap[u][v]) {
                dist[v] = cap[u][v]; //getting best route
                p[v] = u; //storing parents
            }
        }
    }
    
    if (p[n] == -1){
        return 0; 
    }
    return 1;
}

int getMaxFlow() { //ford fulkerson max flow algorithm
    int flow = 0;
    while (dijkstra()) { //keep running until no more paths to final node
        int v = n;
        int mn = INT_MAX;
        while (p[v] != -1) {
            int u = p[v];
            mn = min(mn, cap[u][v]);
            v = u;
        }
        
        v = n;
        while (p[v] != -1) {
            int u = p[v];
            cap[u][v] -= mn;
            cap[v][u] += mn;
            v = u;
        }
        
        flow += mn;
    }
    
    return flow;
}

void restoreCap() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cap[i][j] = rescap[i][j];
        }
    }
}

bool comp(Edge a, Edge b) {
    return a.c > b.c;
}

int main() {
    ofstream cout("milk6.out");
    ifstream cin("milk6.in");
    
    memset(cap, 0, sizeof(cap));
    cin >> n >> m;
    long long flow = 0;
    for (int i = 0;  i < m; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].c; //read in input of edges
        edge[i].x = i+1;
        rescap[edge[i].u][edge[i].v] += edge[i].c; //building array that records capacity
    }
    
    sort(edge, edge+m, comp); //sort edges by cost
    restoreCap();
    int oflow = getMaxFlow(); //original max flow
    
    vector<int> ans;
    int s = 0;
    for (int i = 0; i < m; i++) { //for each edge, see what happens if it is removed
        restoreCap(); //restores capacity to original
        cap[edge[i].u][edge[i].v] -= edge[i].c; //removing edge (reducing capacity)
        int tmp = getMaxFlow(); //find maxflow after removal
        if (oflow - edge[i].c == tmp) { //if it was important edge
            ans.push_back(edge[i].x);
            s += edge[i].c;
            if (s == oflow){
                break;
            }
        }
    }
    
    sort(ans.begin(), ans.end()); //sort answer
    cout << oflow << " " << ans.size() << "\n";
    for (auto i : ans) {
        cout << i << "\n";
    }
}