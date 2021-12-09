#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

//2018 open

int n;
vector<int> cows;

int main(){
    ofstream fout ("lemonade.out");
    ifstream fin ("lemonade.in");
    fin >> n;

    int e;
    for(int i = 0; i < n; i++){
        fin >> e;
        cows.push_back(e);
    }
    sort(cows.rbegin(), cows.rend());

    int curr = 0;
    for(int i = 0; i < n; i++){
        e = cows[i];
        if(e >= curr){
            curr++;
        }
    }

    fout << curr << endl;
}