#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

//BFS Search nearest answer

int n, m;
vector<int> graph[100001];
bool visited[100001];
queue<int> q;
int parent[100001];
vector<int> res;

void steps(int i){
    if(parent[i] == -1){
        res.push_back(i);
        return;
    }
    else{
        res.push_back(i);
        int p = parent[i];
        steps(p);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    bool result = false;
    //vector<int> res;
    q.push(1);
    visited[1] = true;
    parent[1] = -1;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        
        if(p == n){
            result = true;
            steps(p);
            break;
        }

        else{
            for(int x : graph[p]){
                if(!visited[x]){
                    visited[x] = true;
                    parent[x] = p;
                    q.push(x);
                }
            }
        }

    }

    if(result){
        cout << res.size() << endl;
        for(int i = res.size()-1; i >= 1; i--){
            cout << res[i] << " ";
        }
        cout << res[0] << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }

}