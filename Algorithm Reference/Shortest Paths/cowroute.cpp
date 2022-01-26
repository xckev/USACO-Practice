#include <bits/stdc++.h>
using namespace std;

// jan 2015

int A, B, N;
long long routecosts[1000];
long long cost[1001];
bool seen[1001];
int flightsneeded[1001];
vector<pair<int, int>> adj[1001]; //pair is city, route
priority_queue<pair<long long, int>> q; // pair is {dist, node}

int main(){
    ifstream fin("cowroute.in");
    ofstream fout("cowroute.out");
    fin >> A >> B >> N;

    for(int i = 0; i < N; i++){ //i is route num
        long long cost;
        int num;
        fin >> cost >> num;
        routecosts[i] = cost;
        int prev;
        for(int j = 0; j < num; j++){
            int city;
            fin >> city;
            if(j != 0){
                adj[prev].push_back({city, i});
            }
            prev = city;
        }
    }

    fill(cost, cost+1001, 9999999999999999);
    memset(seen, false, sizeof(seen));
    memset(flightsneeded, 0, sizeof(flightsneeded));
    cost[A] = 0;
    q.push({0, A});

    int currroute = -1;
    while(!q.empty()){
        int city = q.top().second;
        q.pop();
        if(!seen[city]){
            seen[city] = true;
            
            for(pair<int, int> p : adj[city]){
                int dest = p.first;
                int route = p.second;
                long long c;
                if(route == currroute){
                    c = 0;
                }
                else{
                    c = routecosts[route];
                    currroute = route;
                }

                if(cost[city] + c < cost[dest]){
                    cost[dest] = cost[city] + c;
                    q.push({-1 * cost[dest], dest});
                    flightsneeded[dest] = flightsneeded[city]+1;
                }
            }
        }
    }

    if(cost[B] == 9999999999999999){
        fout << -1 << " " << -1 << endl;
    }
    else{
        fout << cost[B] << " " << flightsneeded[B] << endl;
    }
    
}