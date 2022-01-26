#include <bits/stdc++.h>
using namespace std;

// dec 2015

int n, m;
bool grid[101][101];
vector<pair<int, int>> switches[101][101];
bool seen[101][101];
bool visited[101][101];
vector<pair<int, int>> mycomponent;
int best;
int counter;

void floodfill(int x, int y){
    visited[x][y] = true;
    mycomponent.push_back({x, y});
    if(x > 1 && grid[x-1][y] && !visited[x-1][y]){
        floodfill(x-1, y);
    }
    if(x < n && grid[x+1][y] && !visited[x+1][y]){
        floodfill(x+1, y);
    }
    if(y > 1 && grid[x][y-1] && !visited[x][y-1]){
        floodfill(x, y-1);
    }
    if(y < n && grid[x][y+1] && !visited[x][y+1]){
        floodfill(x, y+1);
    }
}

void solve(int x, int y){
    seen[x][y] = true;
    if(switches[x][y].empty()){
        return;
    }
    for(pair<int, int> p : switches[x][y]){
        if(grid[p.first][p.second] == false){
            grid[p.first][p.second] = true;
            counter++;
            best = max(best, counter);
        }
    }
    mycomponent.clear();
    memset(visited, false, sizeof(visited));
    floodfill(1, 1);
    
    for(pair<int, int> p : mycomponent){
        int a = p.first;
        int b = p.second;
        if(a >= 1 && a <= n && b >= 1 && b <= n){
            if(a > 1 && grid[a-1][b] && !seen[a-1][b]){
                solve(a-1, b);
            }
            if(a < n && grid[a+1][b] && !seen[a+1][b]){
                solve(a+1, b);
            }
            if(b > 1 && grid[a][b-1] && !seen[a][b-1]){
                solve(a, b-1);
            }
            if(b < n && grid[a][b+1] && !seen[a][b+1]){
                solve(a, b+1);
            }
        }
    }
    
   
}

int main(){
    ifstream fin("lightson.in");
    ofstream fout("lightson.out");
    fin >> n >> m;

    memset(grid, false, sizeof(grid));

    for(int i = 0; i < m; i++){
        int x, y, a, b;
        fin >> x >> y >> a >> b;
        switches[x][y].push_back({a, b});
    }

    best = 0;
    counter = 1;
    grid[1][1] = true;
    memset(seen, false, sizeof(seen));
    solve(1, 1);
    cout << "got out" << endl;
    fout << best << endl;

}