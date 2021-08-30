/*
ID: xckevin1
LANG: C++
TASK: transform
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

#define MAXN 10
int n;

//typedef struct board board;
struct board{
    char contents[MAXN][MAXN];
};

board rotate(board b){
    board newb;
    
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            newb.contents[c][n-1-r] = b.contents[r][c];
        }
    }

    return newb;
}

board reflect(board b){
    board newb;
    
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            newb.contents[r][n-1-c] = b.contents[r][c];
        }
    }

    return newb;
}

bool equalsboard(board b1, board b2){    
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            if(b1.contents[r][c] != b2.contents[r][c]){
                return false;
            }
        }
    }

    return true;
}

int main(){
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");

    fin >> n;

    board b1;
    for(int i = 0; i < n; i++){
        string line;
        fin >> line;
        for(int j = 0; j < n; j++){
            char c = line[j];
            b1.contents[i][j] = c;
        }
    }

    board b2;
    for(int i = 0; i < n; i++){
        string line;
        fin >> line;
        for(int j = 0; j < n; j++){
            char c = line[j];
            b2.contents[i][j] = c;
        }
    }

    int result;
    board rot1, rot2, rot3, refl;
    rot1 = rotate(b1);
    rot2 = rotate(rot1);
    rot3 = rotate(rot2);
    refl = reflect(b1);
    if(equalsboard(b2, rot1)){
        result = 1;
    }
    else if(equalsboard(b2, rot2)){
        result = 2;
    }
    else if(equalsboard(b2, rot3)){
        result = 3;
    }
    else if(equalsboard(b2, refl)){
        result = 4;
    }
    else if(equalsboard(b2, rotate(refl)) || equalsboard(b2, rotate(rotate(refl))) || equalsboard(b2, rotate(rotate(rotate(refl))))){
        result = 5;
    }
    else if(equalsboard(b1, b2)){
        result = 6;
    }
    else{
        result = 7;
    }
    
    fout << result << endl;
    
}