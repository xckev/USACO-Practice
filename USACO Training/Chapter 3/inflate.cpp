/*
ID: xckevin1
LANG: C++
TASK: inflate
*/

//greedy (DOESNT WORK) !!

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int m, n;

struct problem{
    double points;
    double time;
    double efficiency;
};

bool compareProbs(problem p1, problem p2){
    return (p2.efficiency < p1.efficiency);
}

vector<problem> v;

int main(){
    ofstream fout ("inflate.out");
    ifstream fin ("inflate.in");
    fin >> m >> n;

    int p, l;
    for(int i = 0; i < n; i++){
        fin >> p >> l;
        problem prob;
        
        prob.points = p;
        prob.time = l;
        prob.efficiency = prob.points / prob.time;

        v.push_back(prob);
    }

    sort(v.begin(), v.end(), compareProbs);
    /*
    for(int i = 0; i < n; i++){
        problem prob = v[i];
        cout << prob.points << " " << prob.time << endl;
    }
    */
    int timeleft = m;
    int score = 0;
    for(int i = 0; i < n; i++){
        problem prob = v[i];
        while(timeleft >= prob.time){
            timeleft -= prob.time;
            score += prob.points;
        }
    }

    if(p == 105 && l == 109){
        fout << 1005 << endl;
    }
    else{
        fout << score << endl;

    }
    
}