/*
ID: xckevin1
LANG: C++
TASK: castle
*/

//Graphs, floodfill

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n, m;
vector<int> graph[2501];
int components[2501];
bool seen[2501];

vector<int> getSides(int num){
    vector<int> v;
    v.push_back(0); v.push_back(0); v.push_back(0); v.push_back(0);
    if (num >= 8){
        v[0] = 1;
        num -= 8;
    }

    if(num >= 4){
        v[1] = 1;
        num -= 4;
    }

    if(num >= 2){
        v[2] = 1;
        num -= 2;
    }

    if(num >= 1){
        v[3] = 1;
        num -= 1;
    }
    return v;
}

void fill(int i, int compnum){
    seen[i] = true;
    components[i] = compnum;
    for(int j = 1; j <= m*n; j++){
        if(find(graph[i].begin(), graph[i].end(), j) != graph[i].end() && !seen[j]){
            fill(j, compnum);
        }
    }
}

int main(){
    cin >> m >> n;

    int nodenum = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int e;
            cin >> e;
            cout << e << endl;
            vector<int> temp(getSides(e));

            if(temp[0] == 0){
                //graph[nodenum][nodenum + m] = 1;
                graph[nodenum].push_back(nodenum+m);
                cout << nodenum << " connected to " << nodenum+m << endl;
            }
            if(temp[1] == 0){
                graph[nodenum].push_back(nodenum+1);
                cout << nodenum << " connected to " << nodenum+1 << endl;
            }
            if(temp[2] == 0){
                graph[nodenum].push_back(nodenum-m);
                cout << nodenum << " connected to " << nodenum-m << endl;
            }
            if(temp[3] == 0){
                graph[nodenum].push_back(nodenum-1);
                cout << nodenum << " connected to " << nodenum-1 << endl;
            }
            nodenum++;
        }
    }

    int compnum = 1;
    for(int i = 1; i <= n*m; i++){
        if(!seen[i]){
            fill(i, compnum);
        }
        compnum++;
    }

    int counts[2501];
    int maxx = 0;
    int total = 0;
    for(int i = 1; i <= n*m; i++){
        int compp = components[i];
        cout << "node" << i << " is in component "<< compp << endl;
        if(counts[compp] == 0){
            
            total++;
        }
        counts[compp]++;
        maxx = max(maxx, counts[compp]);
    }

    cout << total << endl;
    cout << maxx << endl;

}