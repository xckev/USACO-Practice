#include <bits/stdc++.h>
using namespace std;

//dec 2019

long long n;
vector<int> v;

//Within the first 15 turns exactly eight numbers are spoken; in fact, this is true for any 15 consecutive turns
//f(n)=f(n−8)+15
//num=⌊n−18⌋
//f(n)=f(n−8⋅num)+15⋅num

long long f(long long e){
    int num = (e-1) / 8;
    return v[e - (8*num) -1] + 15*num;
}

int main(){

    ifstream fin("moobuzz.in");
    ofstream fout("moobuzz.out");
    
    fin >> n;
    /*
    if(n < 3){
        cout << n << endl;
        return 0;
    }

    int mult3 = n / 3;
    int mult5 = n / 5;
    int mult15 = n / 15;

    int missing = mult3 + mult5 - mult15;

    //cout << "missing: " << missing << endl;

    int counter = n - missing;
    //cout << "counter start at : " << counter << endl;
    long long i = n+1;
    long long ans;
    while(counter < n){
        if(i % 3 != 0 && i % 5 != 0){
            counter++;
            ans = i;
        }
        i++;
    }
    */

    for(int i = 1; i < 16; i++){
        if(i % 3 != 0 && i % 5 != 0){
            v.push_back(i);
        }
    }
    long long ans = f(n);

    fout << ans << endl;
}