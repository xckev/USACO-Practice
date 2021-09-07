/*
ID: xckevin1
LANG: C++
TASK: frac1
*/

//complete search and then sorting

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;



struct frac{
    int numer, denom;
    double val;

    frac(int a, int b){
        numer = a;
        denom = b;
        val = ((double) a) / ((double) b);
    }
};

bool comp(frac f1, frac f2){
    return (f1.val < f2.val);
}

bool mutuallyPrime(int a, int b){
    /*
    for(int i = 2; i <= min(a, b); i++){
        if(a % i == 0 && b % i == 0){
            return false;
        }
    }
    return true;
    */

    //euclidean algorithm

    int r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return (b==1);

}

int n;
vector<frac> v;

int main(){
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");

    fin >> n;

    frac f(0, 1);
    v.push_back(f);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(mutuallyPrime(i, j)){
                frac fr(j, i);
                v.push_back(fr);
            }
        }
    }

    frac ff(1, 1);
    v.push_back(ff);
    sort(v.begin(), v.end(), comp);

    for(int i = 0; i < v.size(); i++){
        frac fr = v[i];

        fout << fr.numer << "/" << fr.denom << endl;
    }

}