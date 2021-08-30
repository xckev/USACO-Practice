/*
ID: xckevin1
LANG: C++
TASK: dualpal
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

bool ispal(string s){
    if(s.size() == 1){
        return true;
    }
    else{
        int mid = (s.size()+1) / 2;
        int left = 0; int right = s.size()-1;
        while(left < mid && right >= mid){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}

string convert(int n, int b){
    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string result = "";

    int exp = 0;
    int val = pow(b, exp+1);
    while(val <= n){
        exp++;
        val = pow(b, exp+1);
    }

    while(exp >= 0){
        int divisor = pow(b, exp);
        int dig = n / (divisor);
        result += digits[dig];
        n -= (dig*divisor);
        exp--;
    }

    return result;
}

int main(){
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    int n, s;

    fin >> n >> s;

    int good = 0;
    int num = s+1;
    while(good < n){
        int numgood = 0;
        for(int i = 2; i <= 10; i++){
            if(ispal(convert(num, i))){
                numgood++;
            }
            if(numgood >= 2){
                break;
            }
        }
        if(numgood >= 2){
            fout << num << endl;
            good++;
        }
        num++;        
    }
}