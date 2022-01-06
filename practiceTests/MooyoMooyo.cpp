#include <bits/stdc++.h>
using namespace std;

// dec 2018

int n, k;
int grid[100][10];
vector<int> adj[1000];
bool seen[1000];
int components[1000];

int counter;

int getID(int row, int col){
    return row*10 + col;
}

//creates adj list
void formConnections(){
    for(int row = 0; row < n; row++){
        for(int col = 0; col < 10; col++){
            int me = grid[row][col];
            if(me != 0){
                int myID = getID(row, col);
                //up
                if(row > 0 && grid[row-1][col] == me){
                    int theirID = getID(row-1, col);
                    adj[myID].push_back(theirID);
                    //adj[theirID].push_back(myID);
                }
                //down
                if(row < n-1 && grid[row+1][col] == me){
                    int theirID = getID(row+1, col);
                    adj[myID].push_back(theirID);
                    //adj[theirID].push_back(myID);
                }
                //left
                if(col > 0 && grid[row][col-1] == me){
                    int theirID = getID(row, col-1);
                    adj[myID].push_back(theirID);
                    //adj[theirID].push_back(myID);
                }
                //right
                if(col < 10-1 && grid[row][col+1] == me){
                    int theirID = getID(row, col+1);
                    adj[myID].push_back(theirID);
                    //adj[theirID].push_back(myID);
                }
            }
        }
    }
}

//dfs to find nodes in component
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

//delete a component from 2D grid
void deleteComp(int compnum){
    for(int i = 0; i < n*10; i++){
        if(components[i] == compnum){
            int row = i / 10;
            int col = i % 10;
            grid[row][col] = 0;
        }
    }
}

//gravity effect
void dropdown(){
    for(int row = n-2; row >= 0; row--){
        for(int col = 0; col < 10; col++){
            int me = grid[row][col];
            if(me != 0){
                int newrow = row+1;
                while(grid[newrow][col] == 0){
                    newrow++;
                    if(newrow >= n){
                        break;
                    }
                }

                if(newrow >= n){
                    grid[row][col] = 0;
                    grid[n-1][col] = me;
                }
                else{
                    grid[row][col] = 0;
                    grid[newrow-1][col] = me;
                }
                
            }
            
        }
    }
}

int main(){
    ifstream fin("mooyomooyo.in");
    ofstream fout("mooyomooyo.out");
    fin >> n >> k;

    for(int i = 0; i < n; i++){
        string s;
        fin >> s;
        for(int j = 0; j < 10; j++){
            string digit = s.substr(j, 1);
            grid[i][j] = stoi(digit);
        }
    }

    


    bool changesmade = true;
    while(changesmade){
        for (auto& v : adj) { //if u do not do & it will not actually clear
            v.clear();
        }
        formConnections();
        memset(seen, false, sizeof(seen));
        memset(components, 0, sizeof(components));

        int compnum = 1;
        int changes = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < 10; col++){
                if(grid[row][col] != 0){
                    int myID = getID(row, col);
                    if(!seen[myID]){
                        counter = 0;
                        findComp(myID, compnum);
                        if(counter >= k){
                            deleteComp(compnum);
                            changes++;
                        }
                        compnum++;
                    }
                }
            }
        }

        if(changes > 0){
            dropdown();
        }
        else{
            changesmade = false;
        }
    }
    
    for(int row = 0; row < n; row++){
        for(int col = 0; col < 10; col++){
            fout << grid[row][col];
        }
        fout << endl;
    }

}