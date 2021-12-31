#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

//jan 2019

int n;
char grid[1001][1001];
vector<int> adj[1000000];

int area, perim;
bool seen[1000000];

//calculate perimeter added
int perimchange(int cellnum){
    int result = 4;

    for(int e : adj[cellnum]){
        if(seen[e]){
            result--;
        }
    }

    return result;
}

//floodfill dfs
void solve(int cellnum){
    seen[cellnum] = true;
    area++;
    perim += perimchange(cellnum);

    for(int e : adj[cellnum]){
        if(!seen[e]){
            solve(e);
        }
    }
}

int main(){
    ofstream fout ("perimeter.out");
    ifstream fin ("perimeter.in");
    fin >> n;

    //read input into grid
    for(int i = 0; i < n; i++){
        string line;
        fin >> line;
        for(int j = 0; j < n; j++){
            grid[i][j] = line[j];
        }
    }

    //put grid data into graph
    int cellnum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '#'){
                //north
                if(i > 0 && grid[i-1][j] == '#'){
                    int connectednum = cellnum - n;
                    adj[cellnum].push_back(connectednum);
                    adj[connectednum].push_back(cellnum);
                }
                //south
                if(i < n-1 && grid[i+1][j] == '#'){
                    int connectednum = cellnum + n;
                    adj[cellnum].push_back(connectednum);
                    adj[connectednum].push_back(cellnum);
                }
                //east
                if(j < n-1 && grid[i][j+1] == '#'){
                    int connectednum = cellnum + 1;
                    adj[cellnum].push_back(connectednum);
                    adj[connectednum].push_back(cellnum);
                }
                //west
                if(j > 0 && grid[i][j-1] == '#'){
                    int connectednum = cellnum - 1;
                    adj[cellnum].push_back(connectednum);
                    adj[connectednum].push_back(cellnum);
                }
            }
            cellnum++;
        }
    }

    fill(seen, seen+1000000, false);

    int besta = 0;
    int bestp = 99999999;

    for(int i = 0; i < (n*n); i++){
        if(!seen[i]){
            area = 0;
            perim = 0;
            solve(i);

            if(area > besta){
                besta = area;
                bestp = perim;
            }
            else if(area == besta && perim < bestp){
                bestp = perim;
            }
        }
    }

    fout << besta << " " << bestp << endl;
    
}