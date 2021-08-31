/*
ID: xckevin1
LANG: C++
TASK: sprime
*/

//category: complete search

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <set>
#include <fstream>
using namespace std;

ofstream fout ("sprime.out");
ifstream fin ("sprime.in");

int n;
vector<int> good;

bool isprime(int n){
    int lim = (int) sqrt(n);
    for(int i = 2; i <= lim; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void gen(int e, int num){
    if(e == n-1){
        fout << num << endl;
        return;
    }
    else{
        num *= 10;
        if(isprime(num+1)){
            gen(e+1, num+1);
        }
        if(isprime(num+3)){
            gen(e+1, num+3);
        }
        if(isprime(num+7)){
            gen(e+1, num+7);
        }
        if(isprime(num+9)){
            gen(e+1, num+9);
        }
    }
}

int main(){
    fin >> n;

    gen(0, 2);
    gen(0, 3);
    gen(0, 5);
    gen(0, 7);

}