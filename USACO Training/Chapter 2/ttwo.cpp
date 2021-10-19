/*
ID: xckevin1
LANG: C++
TASK: ttwo
*/

//ad hoc ish

#include <bits/stdc++.h>
using namespace std;

string grid[10];
pair<int, int> farmerpos;
pair<int, int> cowpos;

struct state{
    pair<int, int> fpos, cpos;
    int fdir, cdir;
    /*
    state(int fpx, int fpy, int cpx, int cpy, int fd, int cd){
        fpos.first = fpx;
        fpos.second = fpy;
        cpos.first = cpx;
        cpos.second = cpy;
        fdir = fd;
        cdir = cd;
    }*/
};

bool seen[10][10][10][10][4][4];

bool good(pair<int, int> p){
    if(p.first < 0 || p.first >= 10){
        return false;
    }
    if(p.second < 0 || p.second >= 10){
        return false;
    }
    if(grid[p.first][p.second] == '*'){
        return false;
    }
    return true;
}

int main(){
    ofstream fout ("ttwo.out");
    ifstream fin ("ttwo.in");
    for(int i = 0; i < 10; i++){
        fin >> grid[i];
        for(int j = 0; j < 10; j++){
            if(grid[i][j] == 'F'){
                farmerpos = {i, j};
            }
            else if(grid[i][j] == 'C'){
                cowpos = {i, j};
            }
        }
    }
    state s = {farmerpos, cowpos, 0, 0};

    int time = 0;
    while(s.fpos != s.cpos){
        if(seen[s.fpos.first][s.fpos.second][s.cpos.first][s.cpos.second][s.fdir][s.cdir]){
            break;
        }
        seen[s.fpos.first][s.fpos.second][s.cpos.first][s.cpos.second][s.fdir][s.cdir] = true;

        int newx = s.fpos.first;
        int newy = s.fpos.second;
        if(s.fdir == 0){
            newx -= 1;
        }
        else if(s.fdir == 1){
            newy += 1;
        }
        else if(s.fdir == 2){
            newx += 1;
        }
        else if(s.fdir == 3){
            newy -= 1;
        }

        if(good({newx, newy})){
            s.fpos.first = newx;
            s.fpos.second = newy;
        }
        else{
            s.fdir += 1;
            s.fdir %= 4;
        }

        newx = s.cpos.first;
        newy = s.cpos.second;
        if(s.cdir == 0){
            newx -= 1;
        }
        else if(s.cdir == 1){
            newy += 1;
        }
        else if(s.cdir == 2){
            newx += 1;
        }
        else if(s.cdir == 3){
            newy -= 1;
        }

        if(good({newx, newy})){
            s.cpos.first = newx;
            s.cpos.second = newy;
        }
        else{
            s.cdir += 1;
            s.cdir %= 4;
        }

        time++;
    }

    if(s.fpos != s.cpos){
        fout << "0" << endl;
    }
    else{
        fout << time << endl;
    }
}