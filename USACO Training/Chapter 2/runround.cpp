/*
ID: xckevin1
LANG: C++
TASK: runround
*/

//

#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

long long m;

bool good(long long m){
    vector<int> digits;
    set<int> check;
    while(m != 0){
        digits.push_back(m % 10);
        int before = check.size();
        check.insert(m % 10);
        if(m % 10 == 0){
            return false;
        }
        if(check.size() == before){
            return false;
        }
        m = m / 10;
    }
    reverse(digits.begin(), digits.end());
    int n = digits.size();

    int current = 0;
    int next;
    vector<int> counter(10);
    for(int i = 0; i < n; i++){
        next = (current + digits[current]) % n;
        counter[digits[current]]++;
        if(counter[digits[next]] != 0 && next != 0){
            return false;
        }
        current = next;
    }
    return true;
}

int main(){
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");
    fin >> m;
    m++;
    while(!good(m)){
        m++;
    }

    fout << m << endl;
}