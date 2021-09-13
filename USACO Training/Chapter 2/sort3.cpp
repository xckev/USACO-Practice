/*
ID: xckevin1
LANG: C++
TASK: sort3
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n;
int orig[1001];
int sorted[1001];

int search(int i){
    for(int j = i+1; j < n; j++){
        if(orig[j] == sorted[i] && orig[i] == sorted[j]){
            return j;
        }
    }
    for(int j = i+1; j < n; j++){
        if(orig[j] != sorted[j] && orig[j] == sorted[i]){
            return j;
        }
    }
    return -1;
}

int main(){
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");

    fin >> n;
    for(int i = 0; i < n; i++){
        int e;
        fin >> e;
        orig[i] = e;
        sorted[i] = e;
    }

    sort(sorted, sorted + n);

    int counter = 0;
    for(int i = 0; i < n; i++){
        if(orig[i] != sorted[i]){
            int ind = search(i);
            swap(orig[i], orig[ind]);
            counter++;
        }
    }

    fout << counter << endl;
}