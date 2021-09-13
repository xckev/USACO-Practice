/*
ID: xckevin1
LANG: C++
TASK: hamming
*/

// complete search, usage of bitset

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <bitset>
#include <fstream>
using namespace std;

int n, b, d;
vector<int> answer;

int hammingdist(int a, int b){
    bitset<8> c(a^b); //XOR bitset
    return c.count();
}

int main(){
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");

    fin >> n >> b >> d;

    int lim = pow(2, b);
    for(int i = 0; i < lim; i++){
        bool flag = true;
        for(int x : answer){
            if(hammingdist(x, i) < d){
                flag = false;
                break;
            }
        }
        if(flag){
            answer.push_back(i);
            if(answer.size() == n){
                break;
            }
        }
    }

    int tracker = 0;
    for(int i = 0; i < n; i++){
        fout << answer[i];
        tracker++;
        if(i == n-1 || tracker == 10){
            tracker = 0;
            fout << "\n";
        }
        else{
            fout << " ";
        }
    }
    if(tracker != 0){
        fout << endl;
    }

}

