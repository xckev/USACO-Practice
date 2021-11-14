#include <bits/stdc++.h>
using namespace std;

//PRIM'S ALGORITHM - RESEMBLES DIJKSTRA

int n, m;
vector<pair<int, int>> adj[100005];

pair<long long, int> prims(){
    long long total = 0;
    int vertexcount = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    vector<bool> added(n+1, false);
    
    while(!pq.empty()){
        int a, c;
        a = pq.top().second;
        c = pq.top().first;
        pq.pop();

        if(added[a] == true){
            continue;
        }

        added[a] = true;
        vertexcount++;
        total += -c;

        for(auto p : adj[a]){
            int b = p.second;
            int d = p.first;

            if(!added[b]){
                pq.push({-d, b});
            }
        }
    }
    return {total, vertexcount};
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    pair<long long, int> p = prims();
    long long result = p.first;
    int vertexcount = p.second;

    if(vertexcount != n){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << result << endl;
    }


}