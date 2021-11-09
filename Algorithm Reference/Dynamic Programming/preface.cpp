/*
ID: xckevin1
LANG: C++
TASK: preface
*/

//dynamic

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n;

map<char, int> ans;
string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
char order[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

void solve(int x){
    for(int i = 0; i <= 12; i++){
        while(x >= nums[i]){
            x -= nums[i];
            for(char ch : numerals[i]){
                if(ans[ch] == 0){
                    ans[ch] = 1;
                }
                else{
                    ans[ch]++;
                }
            }
        }
    }
}

int main(){
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");
    fin >> n;

    for(int i = 1; i <= n; i++){
        solve(i);
    }

    for(int i = 0; i < 7; i++){
        if(ans[order[i]] != 0){
            fout << order[i] << " " << ans[order[i]] << endl;
        }
    }
}