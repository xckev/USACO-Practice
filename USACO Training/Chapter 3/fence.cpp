/*
ID: xckevin1
LANG: C++
TASK: fence
*/

//hierholzer eulerian path

#include <bits/stdc++.h>
using namespace std;

int F;
multiset<int> adj[1025];
int circuitposind;
int circuit[1025];

void find_path(int i){
    if(adj[i].size() == 0){
        circuit[circuitposind] = i;
        circuitposind += 1;
    }
    else{
        while(!adj[i].empty()){
            int neighbor = *adj[i].begin();
            adj[i].erase(find(adj[i].begin(), adj[i].end(), neighbor));
            adj[neighbor].erase(find(adj[neighbor].begin(), adj[neighbor].end(), i));
            find_path(neighbor);
        }
        circuit[circuitposind] = i;
        circuitposind += 1;
    }
}

int main(){
    ofstream fout ("fence.out");
    ifstream fin ("fence.in");
    fin >> F;

    int maxinter = 0;
    for(int i = 0; i < F; i++){
        int a, b;
        fin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);

        maxinter = max(maxinter, max(a, b));
    }

    bool hasodd = false;
    int oddinter;

    for(int i = 1; i <= maxinter; i++){
        if(adj[i].size() % 2 != 0){
            hasodd = true;
            oddinter = i;
            break;
        }
    }

    circuitposind = 0;
    if(hasodd){
        find_path(oddinter);
    }
    else{
        find_path(1);
    }

    for(int i = F; i >= 0; i--){
        fout << circuit[i]  << endl;
    }
}