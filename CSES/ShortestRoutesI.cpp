#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n, m;
vector<pair<int, int>> adj[100002];
long long dist[100002];
bool seen[100002];
priority_queue<pair<long long, int>> q;

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    for(int i = 1; i <= n; i++){
        dist[i] = 9223372036854775807;
    }
    dist[1] = 0;
    q.push({0, 1});

    while(!q.empty()){
        int a = q.top().second;
        q.pop();
        if(!seen[a]){
            seen[a] = true;
            for(pair<long long, int> p : adj[a]){
                int b = p.first;
                long long w = p.second;
                if(dist[a] + w < dist[b]){
                    dist[b] = dist[a] + w;
                    q.push({-1 * dist[b], b});
                }
            }
        }
    }

    cout << dist[1];
    for(int i = 2; i <= n; i++){
        cout << " " << dist[i];
    }
    cout << endl;

}