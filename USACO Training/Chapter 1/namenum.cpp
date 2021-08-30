/*
ID: xckevin1
LANG: C++
TASK: namenum
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream din ("dict.txt");

    string num;
    fin >> num;

    map<char, char> m;
    m['A'] = m['B'] = m['C'] = '2';
    m['D'] = m['E'] = m['F'] = '3';
    m['G'] = m['H'] = m['I'] = '4';
    m['J'] = m['K'] = m['L'] = '5';
    m['M'] = m['N'] = m['O'] = '6';
    m['P'] = m['R'] = m['S'] = '7';
    m['T'] = m['U'] = m['V'] = '8';
    m['W'] = m['X'] = m['Y'] = '9';

    int sols = 0;
    vector<string> names;

    while (true) {
        string x;
        din >> x;
        if(din.eof()) break;

        string numstr = "";
        for(int i = 0; i < x.size(); i++){
            char c = x[i];
            numstr += m[c];
        }
        if(numstr == num){
            sols++;
            names.push_back(x);
        }

    }

    if(sols == 0){
        fout << "NONE" << endl;
    }
    else{
        sort(names.begin(), names.end());
        for(string s : names){
            fout << s << endl;
        }
    }
    
}