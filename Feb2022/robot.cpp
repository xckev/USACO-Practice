#include <bits/stdc++.h>
//#include <chrono>
using namespace std;
using namespace std::chrono;

int N;
vector<pair<int, int>> moves;
bool seen[40];
long long xg, yg;

set<set<int>> ans;

void DFS(int curr, long long x, long long y, int depth, set<int> s){
    if(depth >= N){
        return;
    }
    if(x == xg && y == yg){
        ans.insert(s);
    }
    seen[curr] = true;
    s.insert(curr);
    pair<int, int> p = moves[curr];
    for(int i = 0; i < N; i++){
        if(!seen[i]){
            DFS(i, x+p.first, y+p.second, depth+1, s);
        }
    }
    seen[curr] = false;
}

int main(){
    
    cin >> N;
    cin >> xg >> yg;

    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;

        moves.push_back({x, y});
    }
    //auto start = high_resolution_clock::now();
    for(int i = 0; i < N; i++){
        memset(seen, false, sizeof(seen));
        set<int> s;
        DFS(i, 0, 0, 0, s);
    }

    int results[N+1];
    memset(results, 0, sizeof(results));
    for(auto s : ans){
        results[s.size()]++;
    }
    //auto stop = high_resolution_clock::now();
    for(int i = 1; i <= N; i++){
        cout << results[i] << endl;
    }
    
    //auto duration = duration_cast<microseconds>(stop - start);
    //cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
}