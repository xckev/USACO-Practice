/*
ID: xckevin1
LANG: C++
TASK: cowtour
*/

//shortest paths - floyd warshall

#include <bits/stdc++.h>
using namespace std;

int n;
int xcoord[151];
int ycoord[151];
long double adj[151][151];
long double furthest[151];

long double distance(int a, int b){
    long double horiz = xcoord[a] - xcoord[b];
    long double vert = ycoord[a] - ycoord[b];
    return sqrt(horiz * horiz + vert * vert);
}

int main(){
    ofstream fout ("cowtour.out");
    ifstream fin ("cowtour.in");
    fin >> n;

    for(int i = 0; i < n; i++){
        fin >> xcoord[i] >> ycoord[i];
    }

    //setting up adj matrix
    for(int i = 0; i < n; i++){
        string s;
        fin >> s;
        for(int j = 0; j < n; j++){
            if(i == j){
                adj[i][j] = 0;
            }
            else if(s[j] == '1'){
                adj[i][j] = distance(i, j);
            }
            else{
                adj[i][j] = 99999999;
            }
        }
    }

    //finding floyd-warshal shortest paths before connecting two fields
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    long double result = 99999999;
    for(int i = 0; i < n; i++){
        furthest[i] = -1;
        for(int j = 0; j < n; j++){
            // finding furthest paths within both components
            if(adj[i][j] != 99999999){
                furthest[i] = max(furthest[i], adj[i][j]);
            }
        }
        //finding max path by adding hypothetical paths between two components with furthest path of each component
        for(int j = 0; j < i; j++){
            if(adj[i][j] == 99999999){
                result = min(result, furthest[i] + distance(i, j) + furthest[j]);
            }
        }
    }
    //if the furthest path exists without connecting the two components
    for(int i = 0; i < n; i++){
        if(result < furthest[i]){
            result = furthest[i];
        }
    }

    fout << fixed << setprecision(6) << result << endl;
}