/*
ID: xckevin1
LANG: C++
TASK: zerosum
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n;
set<vector<string>> ans;

bool good(vector<string> ops){
    
    int result = 1;
    int lastOp = 1;
    int lastNum = 1;
    for(int i = 1; i < n; i++){
        if(ops[i-1] == "+"){
            result += (i+1);
            lastOp = 1;
            lastNum = i+1;
        }
        else if(ops[i-1] == "-"){
            result -= (i+1);
            lastOp = 2;
            lastNum = i+1;

        }
        else{
            int newnum = (lastNum * 10) + (i+1);
            if(lastOp == 1){
                result -= lastNum;
                result += newnum;
            }
            else if(lastOp == 2){
                result += lastNum;
                result -= newnum;
            }
            lastNum = newnum;
        }
    }
    return (result == 0);
}

void solve(int gap, vector<string> sofar){
    if(gap == n){
        if(good(sofar)){
            ans.insert(sofar);
        }
    }
    else{
        vector<string> newv1(sofar);
        newv1.push_back("+");
        solve(gap+1, newv1);

        vector<string> newv2(sofar);
        newv2.push_back("-");
        solve(gap+1, newv2);

        vector<string> newv3(sofar);
        newv3.push_back(" ");
        solve(gap+1, newv3);
    }
}

int main(){
    //ofstream fout ("zerosum.out");
    //ifstream fin ("zerosum.in");
    cin >> n;

    vector<string> v;
    solve(1, v);

    for(vector<string> elem : ans){
        for(int i = 1; i < n; i++){
            cout << i << elem[i-1];
        }
        cout << n << endl;
    }
}