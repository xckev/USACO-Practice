#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <set>
#include <fstream>
using namespace std;

int n, m;
int grid[1001][1001];
bool visited[1001][1001];

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

void search(int i, int j){
    //cout << i << ", " << j << endl;
    visited[i][j] = true;

    if(good(i+1, j)){
        if(!visited[i+1][j]){
            search(i+1, j);
        }
    }
    if(good(i-1, j)){
        if(!visited[i-1][j]){
            search(i-1, j);
        }

    }
    if(good(i, j+1)){
        if(!visited[i][j+1]){
            search(i, j+1);
        }
    }
    if(good(i, j-1)){
        if(!visited[i][j-1]){
            search(i, j-1);
        }
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
                //cout << "Square " << i << ", " << j << " is type: " << grid[i][j] << endl;
                visited[i][j] = false;
                //cout << "in" << endl;
            }
        }
    }

    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(grid[i][j] == 1 && !visited[i][j]){
                search(i, j);
                result++;
            }
        }
    }

    cout << result << endl;
}