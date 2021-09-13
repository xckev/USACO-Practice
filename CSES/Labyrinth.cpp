#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

//BFS

int n, m;
int grid[1001][1001];
bool visited[1001][1001];
queue<pair<int, int>> q;
pair<int, int> parent[1001][1001];
vector<string> res;

bool good(int i, int j) {
    if (i < 0 || j < 0 ){
        return false;
    }
    if(i >= n || j >= m){
        return false;
    }
    if(grid[i][j] == 0){
        return false;
    }
    return true;
}

void steps(int i, int j){
    if(parent[i][j].first == -1 && parent[i][j].second == -1){
        return;
    }
    else{
        pair<int, int> p = parent[i][j];
        if(p.first == i-1){
            res.push_back("D");
        }
        else if(p.first == i+1){
            res.push_back("U");
        }
        else if(p.second == j-1){
            res.push_back("R");
        }
        else if(p.second == j+1){
            res.push_back("L");
        }
        steps(p.first, p.second);
    }
}

int main(){
    cin >> n >> m;

    
    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        for(int j = 0; j < m; j++){
            char c = line[j];
            if(c == '.'){
                grid[i][j] = 1;
            }
            if(c == 'A'){
                q.push({i, j});
                visited[i][j] = true;
                grid[i][j] = 2;
                parent[i][j] = {-1, -1};
            }
            if(c == 'B'){
                grid[i][j] = 3;
            }
        }
    }

    bool result = false;
    
    while(!q.empty()){
        pair<int, int> p;
        p = q.front();
        q.pop();
        int i = p.first;
        int j = p.second;
        if(grid[i][j] == 3){
            result = true;
            steps(i, j);
            break;
        }
        if(good(i+1, j)){
            if(!visited[i+1][j]){
                visited[i+1][j] = true;
                q.push({i+1, j});
                parent[i+1][j] = {i,j};
            }
        }
        if(good(i-1, j)){
            if(!visited[i-1][j]){
                visited[i-1][j] = true;
                q.push({i-1, j});
                parent[i-1][j] = {i,j};
            }

        }
        if(good(i, j+1)){
            if(!visited[i][j+1]){
                visited[i][j+1] = true;
                q.push({i, j+1});
                parent[i][j+1] = {i,j};
            }
        }
        if(good(i, j-1)){
            if(!visited[i][j-1]){
                visited[i][j-1] = true;
                q.push({i, j-1});
                parent[i][j-1] = {i,j};
            }
        }
    }


    if(result){
        cout << "YES" << endl;
        cout << res.size() << endl;
        for(int i = res.size()-1; i >= 0; i--){
            cout << res[i];
        }
        cout << endl;
    }
    else{
        cout << "NO" << endl;
    }

    
}