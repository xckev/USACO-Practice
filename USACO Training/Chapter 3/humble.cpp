/*
ID: xckevin1
LANG: C++
TASK: humble
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int k, n;
long s[103];
long humbles[100001];
long previous[100001]; 

int main(){
    ofstream fout ("humble.out");
    ifstream fin ("humble.in");
    fin >> k >> n;

    for(int i = 0; i < k; i++){
        fin >> s[i];
    }
    humbles[0] = 1;

    for(int i = 1; i <= n; i++){
        humbles[i] = 1999999999;
        for(int j = 0; j < k; j++){
            while(previous[j] < i && s[j] * humbles[previous[j]] <= humbles[i-1]){
                previous[j]++;
            }
            if(s[j] * humbles[previous[j]] > humbles[i-1]){
                humbles[i] = min(humbles[i], s[j] * humbles[previous[j]]);
            }
        }
    }
    fout << humbles[n] << endl;
}