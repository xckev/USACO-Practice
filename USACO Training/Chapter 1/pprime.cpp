/*
ID: xckevin1
LANG: C++
TASK: pprime
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

int a, b;
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

void gen(int e, int len, string curr){
    string holder = curr;
    if(e == len){
        
        int num = stoi(curr);
        if(num >= a && num <= b && isprime(num)){
            good.push_back(num);
        }
    }
    else if(e == len-1){
        
        
        int l = curr.size();
        int split = l / 2;
        for(int i = 0; i < 10; i++){
            curr = curr.substr(0, split) + to_string(i) + curr.substr(split, l-split);
            gen(e+1, len, curr);

            curr = holder;
        }
        
        
    }
    else{
        
        for(int i = 0; i < 10; i++){
            string add = to_string(i);
            curr = add + curr + add;
            gen(e+2, len, curr);
            curr = holder;
        }
    }
}



int main(){
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");

    fin >> a >> b;
    
    int start;
    if(a % 2 == 0){
        start = a+1;
    }
    else{
        start = a;
    }

    int maxlen = to_string(b).size();
    int minlen = to_string(a).size();

    //cout << minlen << " " << maxlen << endl;

    for(int i = minlen; i <= maxlen; i++){
        gen(0, i, "");
    }

    sort(good.begin(), good.end());
    for(int x : good){
        fout << x << endl;
    }
    //cout << ispal(67) << endl;
}