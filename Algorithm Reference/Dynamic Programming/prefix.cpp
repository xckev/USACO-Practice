/*
ID: xckevin1
LANG: C++
TASK: prefix
*/

//dynamic programming :)

#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

vector<string> prims;
string target;
int N;
int best = 0;

int main(){
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");

    string s;
    fin >> s;
    while(s != "."){
        prims.push_back(s);
        fin >> s;
    }

    target = "";
    
    while(fin >> s){
        target += s;
 
    }
    
    target.erase(remove(target.begin(), target.end(), '\n'), target.end());
    N = target.size();
    
    vector<bool> storage(N+1, false);
    storage[0] = true;
    for(int i = 0; i <= N; i++){
        if(storage[i]){
            for(string prim : prims){
                int len = prim.size();
                if(len + i <= N){
                    if(target.substr(i, len) == prim){
                        storage[i+len] = true;
                    }
                }
            }
        }
    }

    for(int i = N; i >= 0; i--){
        if(storage[i]){
            fout << i << endl;
            break;
        }
    }
}