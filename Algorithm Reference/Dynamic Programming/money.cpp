/*
ID: xckevin1
LANG: C++
TASK: money
*/

// make it so order doesnt matter

#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int v;
long long n;
int arr[25];
long long storage[10001];

int main(){
    ofstream fout ("money.out");
    ifstream fin ("money.in");
    fin >> v >> n;
    for(int i = 0; i < v; i++){
        fin >> arr[i];
    }

    storage[0] = 1;

    for(int i = 0; i < v; i++){
        for(int j = 0; j <= n; j++){
            if(arr[i] + j <= n){
                storage[j + arr[i]] += storage[j];
            }
        }
    }

    fout << storage[n] << endl;
    
}