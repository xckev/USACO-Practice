#include <bits/stdc++.h>
using namespace std;

// 2018 open

int N;
int counter;
int grid[250][250];
vector<int> adj[62500];
set<int> adj2[62500];
map<int, set<int>> connectedplayers;
int compToPlayer[62500];
bool seen[62500];
bool seen2[62500];
int components[62500];
int compsizes[62500];

int getID(int row, int col){
    return row*N + col;
}

void formConnections(){
    for(int row = 0; row < N; row++){
        for(int col = 0; col < N; col++){
            int me = grid[row][col];
            
            int myID = getID(row, col);
            //up
            if(row > 0 && grid[row-1][col] == me){
                int theirID = getID(row-1, col);
                adj[myID].push_back(theirID);
            }
            //down
            if(row < N-1 && grid[row+1][col] == me){
                int theirID = getID(row+1, col);
                adj[myID].push_back(theirID);
            }
            //left
            if(col > 0 && grid[row][col-1] == me){
                int theirID = getID(row, col-1);
                adj[myID].push_back(theirID);
            }
            //right
            if(col < N-1 && grid[row][col+1] == me){
                int theirID = getID(row, col+1);
                adj[myID].push_back(theirID);
            }
        }
    }
}

void findComp(int cellnum, int compnum){
    seen[cellnum] = true;
    components[cellnum] = compnum;
    counter++;
    for(int e : adj[cellnum]){
        if(!seen[e]){
            findComp(e, compnum);
        }
    }
}

void findComp2(int compnum, int p1, int p2){
    //cout << "on component " << compnum << endl;
    seen2[compnum] = true;
    counter += compsizes[compnum];
    for(int e : adj2[compnum]){
        //cout << "i will make it in: " << (compToPlayer[e] == p1 || compToPlayer[e] == p2) << endl;
        if(!seen2[e] && (compToPlayer[e] == p1 || compToPlayer[e] == p2)){
            //cout << "going to component " << e << " because it is either player " << p1 << " or " << p2 << endl;
            //cout << "it is player " << compToPlayer[e] << endl;
            findComp2(e, p1, p2);
        }
            //cout << "AVOIDING component " << e << " because it is NOT either player " << p1 << " or " << p2 << endl;
            //cout << "it is player " << compToPlayer[e] << endl;
    }
}

int main(){
    ifstream fin("multimoo.in");
    ofstream fout("multimoo.out");
    fin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int e;
            fin >> e;
            grid[i][j] = e;
            //players.insert(e);
        }
    }
    formConnections();
    //memset(seen, false, sizeof(seen));
    //memset(components, 0, sizeof(components));

    int compnum = 0;
    int bestregion = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int player = grid[i][j];
            int myID = getID(i, j);
            if(!seen[myID]){
                counter = 0;
                findComp(myID, compnum);
                compsizes[compnum] = counter;
                bestregion = max(bestregion, counter);
                compToPlayer[compnum] = player;
                compnum++;
            }
        }
    }
    fout << bestregion << endl;

    for(int row = 0; row < N; row++){
        for(int col = 0; col < N; col++){
            //cout << "here at " << row << ", " << col << endl;
            int myID = getID(row, col);
            int me = grid[row][col];
            int mycomp = components[myID];
            //cout << "component " << mycomp << " is adjacent to ";
            if(row > 0 && mycomp != components[getID(row-1, col)]){
                int theirID = getID(row-1, col);
                int theircomp = components[theirID];
                adj2[mycomp].insert(theircomp);
                int them = grid[row-1][col];
                connectedplayers[me].insert(them);
                //cout << "component " << theircomp << " ";
            }
            //down
            if(row < N-1 && mycomp != components[getID(row+1, col)]){
                
                int theirID = getID(row+1, col);
                int theircomp = components[theirID];
                adj2[mycomp].insert(theircomp);
                int them = grid[row+1][col];
                connectedplayers[me].insert(them);
                //cout << "component " << theircomp << " ";
            }
            //left
            if(col > 0 && mycomp != components[getID(row, col-1)]){
                int theirID = getID(row, col-1);
                int theircomp = components[theirID];
                adj2[mycomp].insert(theircomp);
                int them = grid[row][col-1];
                connectedplayers[me].insert(them);
                //cout << "component " << theircomp << " ";
            }
            //right
            if(col < N-1 && mycomp != components[getID(row, col+1)]){
                int theirID = getID(row, col+1);
                int theircomp = components[theirID];
                adj2[mycomp].insert(theircomp);
                int them = grid[row][col+1];
                connectedplayers[me].insert(them);
                //cout << "component " << theircomp << " ";
            }
            //cout << endl;
        }
    }

    int ans = 0;
    for(int c = 0; c < compnum; c++){
        int p1 = compToPlayer[c];
        for(int p2 : connectedplayers[p1]){
            if(p1 != p2){
                counter = 0;
                memset(seen2, false, sizeof(seen2));
                findComp2(c, p1, p2);
                //cout << "size was " << counter << endl;
                //cout << "-----" << endl;
                ans = max(ans, counter);
            }
        }
    }
    fout << ans << endl;
    



}