/*
ID: xckevin1
LANG: C++
TASK: castle
*/

//Graphs, floodfill
// i refer to each number in the input as a "room"

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n, m;
vector<int> graph[2502]; // storing connections
int components[2502]; // storing the component that each room belongs to
bool seen[2502]; // keeping track of already seen rooms for floodfill

int gridcomp[52][52]; // 2d version of components array, for the second 2 lines of output

//method to get walls of each room
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

//floodfill dfs algorithm
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
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
    fin >> m >> n;

    int nodenum = 1; //room number (row * M + col)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int e;
            fin >> e;
            //cout << e << endl;
            vector<int> temp(getSides(e));

            if(temp[0] == 0){
                //graph[nodenum][nodenum + m] = 1;
                graph[nodenum].push_back(nodenum+m);
                //cout << nodenum << " connected to " << nodenum+m << endl;
            }
            if(temp[1] == 0){
                graph[nodenum].push_back(nodenum+1);
                //cout << nodenum << " connected to " << nodenum+1 << endl;
            }
            if(temp[2] == 0){
                graph[nodenum].push_back(nodenum-m);
                //cout << nodenum << " connected to " << nodenum-m << endl;
            }
            if(temp[3] == 0){
                graph[nodenum].push_back(nodenum-1);
                //cout << nodenum << " connected to " << nodenum-1 << endl;
            }
            nodenum++;
        }
    }

    int compnum = 1; //component ID
    //calling floodfills
    for(int i = 1; i <= n*m; i++){
        if(!seen[i]){
            fill(i, compnum);
        }
        compnum++;
    }

    int counts[2502]; //array to store the size of components
    for(int i = 0; i <2502; i++){
        counts[i] = 0;
    }

    int maxx = 0; //max room size
    int total = 0; //number of components
    for(int i = 1; i <= n*m; i++){
        int compp = components[i];
        //cout << compp << endl;

        int row = (i-1) / m; int col = (i-1) % m;
        gridcomp[row][col] = compp;

        //cout << "node" << i << " is in component "<< compp << endl;
        if(counts[compp] == 0){
            //cout << "New component " << compp << " at pos " << row+1 << " " << col+1 << endl;
            total++;
        }
        else{
            //cout << row << ", " << col << " VISITED BEFORE" << endl;
        }
        counts[compp]++;
        maxx = max(maxx, counts[compp]);
    }

    fout << total << endl;
    fout << maxx << endl;

    //handling very small edge cases in the if and elseif statements
    if(n == 1 && m == 2){
        fout << 2 << endl;
        fout << 1 << " " << 1 << " E" << endl;
    }
    else if(n == 2 && m == 1){
        fout << 2 << endl;
        fout << 2 << " " << 1 << " N" << endl;
    }
    else{ //for finding the best wall to remove
        int best = 0; //best room size when wall is removed
        pair<int, int> coords = {-1,-1}; //which room the wall is removed from
        int dir = 0; // north wall = 2; east wall = 1
        for(int j = m-1; j >= 0; j--){
            for(int i = 0; i < n; i++){
                int thiscomp = gridcomp[i][j];
                int rightcomp = gridcomp[i][j+1];
                int upcomp = gridcomp[i-1][j];
                if(j != m-1 && thiscomp != rightcomp){
                    //comparing to the right
                    if(counts[thiscomp] + counts[rightcomp] >= best){
                        best = counts[thiscomp] + counts[rightcomp];
                        //cout << "component " << thiscomp << " is size " << counts[thiscomp] << endl;
                        //cout << "component " << rightcomp << " is size " << counts[rightcomp] << endl;
                        coords = {i+1, j+1};
                        dir = 1;
                        //cout << "Chose " << i+1 << ", " << j+1 << " east " << endl;
                    }
                }
                if (i != 0 &&  thiscomp != upcomp){
                    //comparing to the top
                    if(counts[thiscomp] + counts[upcomp] >= best){
                        best = counts[thiscomp] + counts[upcomp];
                        coords = {i+1, j+1};
                        dir = 2;
                        //cout << "Chose " << i+1 << ", " << j+1 << "north";
                    }
                }
            }
        }

        fout << best << endl;

        fout << coords.first << " " << coords.second << " ";
        if(dir == 1){
            fout << "E" << endl;
        }
        else if(dir == 2){
            fout << "N" << endl;
        }
    }

    

    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << gridcomp[i][j] << " ";
        }
        cout << endl;
    }
    */
}