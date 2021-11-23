/*
ID: xckevin1
LANG: C++
TASK: butter
*/

//dijkstra

#include <bits/stdc++.h>
using namespace std;

int N, P, C;
vector<int> cowlocations;
vector<pair<int, int>> adj[801]; // get {b, w} from a
int dist[801];
bool seen[801];
priority_queue<pair<int, int>> q; // pair is {dist, vertex}

void dijkstra(int i){
    fill(dist, dist+801, 99999999);
    fill(seen, seen+801, false);
    dist[i] = 0;
    q.push({0, i});

    while(!q.empty()){
        int a = q.top().second;
        q.pop();
        if(!seen[a]){
            seen[a] = true;
            for(pair<int, int> p : adj[a]){
                int b = p.first;
                int w = p.second;
                if(dist[a] + w < dist[b]){
                    dist[b] = dist[a] + w;
                    q.push({-1 * dist[b], b});
                }
            }
        }
    }
}


int main(){
    ofstream fout ("butter.out");
    ifstream fin ("butter.in");
    fin >> N >> P >> C;

    for(int i = 0; i < N; i++){
        int e;
        fin >> e;
        cowlocations.push_back(e);
    }

    for(int i = 0; i < C; i++){
        int a, b, w;
        fin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    int best = 99999999;
    for(int i = 1; i <= P; i++){
        dijkstra(i);
        int total = 0;
        for(int e : cowlocations){
            total += dist[e];
        }
        best = min(best, total);
    }

    fout << best << endl;
}