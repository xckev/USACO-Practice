#include <bits/stdc++.h>
using namespace std;

//prims

int n, m;
vector<pair<long long, int>> adj[100005];

long long prims(){
    long long total = 0;
    vector<long long> min(n+1, LLONG_MAX); //keeps track of minimum edge weight connected to a vertex
    min[1] = 0;
    set<pair<long long, int>> q; //cannot use real queue because must modify contents
    q.insert({0, 1});
    vector<bool> visited(n+1, false);

    for(int i = 0; i < n; i++){
        if(q.empty()){
            return -1;
        }

        int v = q.begin() -> second;
        visited[v] = true;
        total += q.begin() -> first;
        q.erase(q.begin());

        for(pair<long long, int> e : adj[v]){
            if(!visited[e.second] && e.first < min[e.second]){ 
                //if min[e.second] is not LLONG_MAX, we are replacing old element with new element that has updated smaller edge
                //otherwise, are just visiting e.second for the first time
                q.erase({min[e.second], e.second});
                min[e.second] = e.first;
                q.insert({e.first, e.second});
            }
        }
    }
    return total;
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

    long long result = prims();

    if(result == -1){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << result << endl;
    }


}