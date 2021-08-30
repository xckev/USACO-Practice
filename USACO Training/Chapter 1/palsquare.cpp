/*
ID: xckevin1
LANG: C++
TASK: palsquare
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
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");

    int b;
    fin >> b;

    for(int i = 1; i <= 300; i++){
        int square = pow(i, 2);
        string converted = convert(square, b);
        if(ispal(converted)){
            fout << convert(i, b) << " " << converted << endl;
        }
    }
}