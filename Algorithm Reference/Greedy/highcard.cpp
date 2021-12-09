#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

//2015 dec

int n;
vector<int> elsie;
set<int> elsieord;
set<int> bessie;

int main(){
    ofstream fout ("highcard.out");
    ifstream fin ("highcard.in");
    fin >> n;

    int e;
    for(int i = 0; i < n; i++){
        fin >> e;
        elsie.push_back(e);
        elsieord.insert(e);
    }

    for(int i = 1; i <= 2*n; i++){
        if(!elsieord.empty()){
            auto it = elsieord.begin();
            if(*it == i){
                elsieord.erase(it);
            }
            else{
                bessie.insert(i);
            }
        }
        else{
            bessie.insert(i);
        }
    }

    int wins = 0;
    for(int i = 0; i < n; i++){
        int els = elsie[i];
        auto higher = bessie.upper_bound(els);
        if(higher == bessie.end()){
            bessie.erase(bessie.begin());
        }
        else{
            bessie.erase(higher);
            wins++;
        }
    }

    fout << wins << endl;

}