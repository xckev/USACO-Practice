/*
ID: xckevin1
LANG: C++
TASK: nocows
*/

//dynamic programming

#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n, k;
int storage[201][101];

int main(){
    ofstream fout ("nocows.out");
    ifstream fin ("nocows.in");
    fin >> n >> k;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(i == 1){
                storage[i][j] = 1;
            }
            else{
                for(int h = 1; h <= i-1; h++){
                    storage[i][j] += storage[h][j-1] * storage[i-1-h][j-1];
                    storage[i][j] = (storage[i][j]) % 9901;
                }
            }
            
        }
    }
    int result = storage[n][k] - storage[n][k-1];
    if(result < 0){
        fout << (result + 9901) % 9901 << endl;
    }
    else{
        fout << result % 9901 << endl;
    }
}