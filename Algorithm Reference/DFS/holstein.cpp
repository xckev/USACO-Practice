/*
ID: xckevin1
LANG: C++
TASK: holstein
*/

// Depth first search all the combinations

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int v, g;
int r[1005];
int s[20][1005];
vector<int> used;
int res = 20;
vector<int> answer;

void search(int i){
    if(i == g+1){
        for(int j = 1; j <= v; j++){
            int sum = 0;
            for(int k : used){
                sum += s[k][j];
            }
            if(sum < r[j]){
                return;
            }
        }
        if(used.size() < res){
            res = used.size();
            answer = used;
        }

        return;
    }
    
    used.push_back(i);
    search(i+1);
    used.pop_back();
    search(i+1);
}

int main(){
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");

    fin >> v;
    for(int i = 1; i <= v; i++){
        fin >> r[i];
    }
    fin >> g;

    for(int i = 1; i <= g; i++){
        for(int j = 1; j <= v; j++){
            fin >> s[i][j];
        }
    }

    search(1);
    
    fout << res << " ";
    for(int i = 0; i < answer.size()-1; i++){
        fout << answer[i] << " ";
    }
    fout << answer[answer.size()-1] << endl;
}