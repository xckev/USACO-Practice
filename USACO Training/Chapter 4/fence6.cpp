/*
ID: xckevin1
LANG: C++
TASK: fence6
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int id[105][2]; //giving ID to nodes with id[segmentnumber][one of two endpoints]
int segmap[105][105]; //for accessing which end two segments are connected from
vector<pair<int, int>> adj[210]; //linking NODES with {other node, weight}

bool seen[210];
int ans;

void connect(int i, int j, int w){
    adj[i].push_back({j, w});
    adj[j].push_back({i, w});
}

void solve(int i, int start, int last, int dist){
    if(dist > ans){
        return;
    }
    if(seen[i] && dist > 0 && i == start){
        ans = min(ans, dist);
        return;
    }
    for(pair<int, int> p : adj[i]){
        if(p.first != last && !seen[p.first]){
            seen[p.first] = true;
            solve(p.first, start, i, dist + p.second);
            seen[p.first] = false;
        }
    }
}

int main(){
    ofstream fout ("fence6.out");
    ifstream fin ("fence6.in");
    fin >> n;

    for(int i = 1; i <= n; i++){
        id[i][0] = 2*i - 1;
        id[i][1] = 2*i;
    }

    memset(segmap, -1, sizeof(segmap));
    for(int i = 1; i <= n; i++){
        int seg, w, l, r;
        fin >> seg >> w >> l >> r;
        connect(id[seg][0], id[seg][1], w); //forming segments themselves by connecting their two nodes

        //connections on first end of segment 
        for(int j = 1; j <= l; j++){
            int k;
            fin >> k;
            if(segmap[seg][k] == -1){ //marking which end (0 or 1) to connect segments a and b
                segmap[seg][k] = 0;
                segmap[k][seg] = 0;
            }
            else{
                connect(id[seg][0], id[k][segmap[seg][k]], 0); //the second time around we see a and b get connected, they will ACTUALLY be connected
            }
        }

        //connections on second end of segment 
        for(int j = 1; j <= r; j++){
            int k;
            fin >> k;
            if(segmap[seg][k] == -1){
                segmap[seg][k] = 1;
                segmap[k][seg] = 1;
            }
            else{
                connect(id[seg][1], id[k][segmap[seg][k]], 0);
            }
        }
    }

    ans = 99999999;
    for(int i = 1; i <= 2*n; i++){
        fill(seen, seen+210, false);
        solve(i, i, 0, 0);
    }
    fout << ans << endl;
}