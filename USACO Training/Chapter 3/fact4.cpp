/*
ID: xckevin1
LANG: C++
TASK: fact4
*/

// kinda dumb

#include <bits/stdc++.h>
using namespace std;

int N;

int cutright(int x){
    while(x % 10 == 0){
        x /= 10;
    }
    return x;
}

int main(){
    ofstream fout ("fact4.out");
    ifstream fin ("fact4.in");
    fin >> N;

    int curr = 1;
    for(int i = 1; i <= N; i++){
        curr *=  i;
        curr = cutright(curr);
        curr = curr % 1000;
    }

    fout << curr%10 << endl;
}