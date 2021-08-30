/*
ID: xckevin1
LANG: C++
TASK: milk
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");

    int n, m;
    fin >> n >> m;

    vector<pair<int, int>> farms;

    for(int i = 0; i < m; i++){
        int p1, p2;
        fin >> p1 >> p2;
        pair<int, int> p = {p1, p2};
        farms.push_back(p);
    }

    sort(farms.begin(), farms.end());

    int i = 0;
    int total = 0;
    while(n > 0){
        pair<int, int> currpair = farms[i];
        int tosub = min(n, currpair.second);

        int price = currpair.first;
        total += price * tosub;
        n -= tosub;
        i++;

    }

    fout << total << endl;
}