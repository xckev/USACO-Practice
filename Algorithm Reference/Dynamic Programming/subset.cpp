/*
ID: xckevin1
LANG: C++
TASK: subset
*/

// dynamic

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n;
long long storage[781];

int main(){
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");
    fin >> n;

    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += i;
    }

    if(sum % 2 == 1){
        fout << 0 << endl;
    }
    else{
        fill(storage, storage+781, 0);
        int half = sum / 2;
        storage[0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = half-i; j >= 0; j--){
                storage[j+i] += storage[j];
            }
        }

        fout << storage[half]/2 << endl;
    }

}
