#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n, m;

int xcoord[100001];
int ycoord[100001];

vector<int> adj[100001];
int componentnum[100001];

int currstart;
int minx , miny;
int maxx, maxy;


void solve(int c, int seen[]){
    componentnum[c] = currstart;
    seen[c] = 69420;
    minx = min(minx, xcoord[c]);
    maxx = max(maxx, xcoord[c]);
    miny = min(miny, ycoord[c]);
    maxy = max(maxy, ycoord[c]);

    for(int e : adj[c]){
        if(seen[e] != 69420){
            solve(e, seen);
        }
    }

}

int main(){
    ofstream fout ("fenceplan.out");
    ifstream fin ("fenceplan.in");
    fin >> n >> m;

    for(int i = 1; i <= n; i++){
        fin >> xcoord[i] >> ycoord[i];
    }
    for(int i = 0; i < m; i++){
        int a, b;
        fin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fill(componentnum, componentnum+100001, -1);

    long long bestperim = 99999999999;
    for(int i = 1; i <= n; i++){
        currstart = i;
        minx = 99999999, miny = 99999999;
        maxx = 0, maxy = 0;
        if(componentnum[i] == -1){
            int seen[100001];
            solve(i, seen);
            long long perim = 2*(maxx - minx) + 2*(maxy-miny);
            bestperim = min(bestperim, perim);
        }
    }

    fout << bestperim << endl;

}