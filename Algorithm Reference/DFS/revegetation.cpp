#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n, m;
int type[100001];
bool impossible;
vector<int> same[100001];
vector<int> diff[100001];

void check(int pasture, int color){
    type[pasture] = color;

    for(int e : same[pasture]){
        if(type[e] == 3 - color){
            impossible = true;
        }
        if(type[e] == 0){
            check(e, color);
        }
    }

    for(int e : diff[pasture]){
        if(type[e] == color){
            impossible = true;
        }
        if(type[e] == 0){
            check(e, 3-color);
        }
    }
}

int main(){
    ofstream fout ("revegetate.out");
    ifstream fin ("revegetate.in");
    fin >> n >> m;
    impossible = false;

    for(int i = 0; i < m; i++){
        char c;
        int a, b;
        fin >> c >> a >> b;
        
        if(c == 'S'){
            same[a].push_back(b);
            same[b].push_back(a);
        }
        else{
            diff[a].push_back(b);
            diff[b].push_back(a);
        }

    }

    int components = 0;
    for(int i = 1; i <= n; i++){
        if(type[i] == 0){
            check(i, 1);
            components++;
        }
    }

    if(impossible){
        fout << 0 << endl;
    }
    else{
        fout << 1;
        for(int i = 0; i < components; i++){
            fout << 0;
        }
        fout << endl;
    }
}