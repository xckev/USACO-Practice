/*
ID: xckevin1
LANG: C++
TASK: rockers
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n, t, m;
int sz[25];
int res = 0;

void solve1(int currsong, int numsongs, int numdisks, int disksize){
    if(numdisks > m || disksize > t){
        return;
    }
    if(currsong == n+1){
        res = max(res, numsongs);
        return;
    }
    //not using song currsong
    solve1(currsong+1, numsongs, numdisks, disksize);
    //adding currsong to current disk
    solve1(currsong+1, numsongs+1, numdisks, disksize+sz[currsong]);
    //start using a new disk
    solve1(currsong+1, numsongs+1, numdisks+1, sz[currsong]);
}

int main(){
    ofstream fout ("rockers.out");
    ifstream fin ("rockers.in");
    fin >> n >> t >> m;

    for(int i = 1; i <= n; i++){
        fin >> sz[i];
    }

    solve1(1, 0, 1, 0);
    fout << res << endl;
}