/*
ID: xckevin1
LANG: C++
TASK: agrinet
*/

// minimal spanning tree

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;
#define inf 99999999;

int n;
int adj[102][102];
int dist[102];
bool seen[102];

int main(){
    ofstream fout ("agrinet.out");
    ifstream fin ("agrinet.in");

    fin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fin >> adj[i][j];
        }
        dist[i] = inf;
        seen[i] = false;
    }

    dist[1] = 0;
    seen[1] = true;
    int current = 1;
    int result = 0;
    for(int i = 1; i <= n-1; i++){
        for(int j = 1; j <= n; j++){
            dist[j] = min(dist[j], adj[current][j]);
        }
        int next = -1;
        for(int j = 1; j <= n; j++){
            if(!seen[j] && (next == -1 || dist[j] < dist[next])){
                next = j;
            }
        }
        current = next;
        result += dist[current];
        seen[next] = true;

    }

    fout << result << endl;


}