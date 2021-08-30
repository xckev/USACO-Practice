/*
ID: xckevin1
LANG: C++
TASK: skidesign
*/

//category: complete search

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n;

int costChange(int goal, int h){
    if(h < goal){
        return pow(goal - h, 2);
    }
    else if(h > goal+17){
        return pow(h - (goal+17), 2);
    }
    else{
        return 0;
    }

}

int main(){
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");

    fin >> n;

    vector<int> hills;
    for(int i = 0; i < n; i++){
        int e;
        fin >> e;
        hills.push_back(e);
    }
    sort(hills.begin(), hills.end());

    int best = INT32_MAX;
    for(int i = hills[0]; i <= hills[n-1]; i++){
        int curr = 0;
        for(int j = 0; j < n; j++){
            int h = hills[j];
            curr += costChange(i, h);
        }

        best = min(best, curr);
    }

    fout << best << endl;
}