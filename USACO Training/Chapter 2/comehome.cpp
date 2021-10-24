/*
ID: xckevin1
LANG: C++
TASK: comehome
*/

//shortest paths

#include <bits/stdc++.h>
using namespace std;

int p;
int d[52][52];

int minimum(int x, int y){
    if(x < y){
        return x;
    }
    else{
        return y;
    }
}

int asciiconvert(char c){
    if(c >= 'a' && c <= 'z'){
        return (c - 'a');
    }
    else{
        return (c - 'A' + 26);
    }
}

int main(){
    ofstream fout ("comehome.out");
    ifstream fin ("comehome.in");
    fin >> p;

    for(int i = 0; i < 52; i++){
        for(int j = 0; j < 52; j++){
            if(i == j){
                d[i][j] == 0;
            }
            else{
                d[i][j] = 99999999;
            }
        }
    }
    for(int i = 0; i < p; i++){
        char a, b;
        int w;
        fin >> a >> b >> w;
        
        int A = asciiconvert(a);
        int B = asciiconvert(b);
        d[A][B] = minimum(d[A][B], w);
        d[B][A] = minimum(d[B][A], w);;
    }

    for(int k = 0; k < 52; k++){
        for(int i = 0; i < 52; i++){
            for(int j = 0; j < 52; j++){
                d[i][j] = minimum(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int result;
    int distance = 99999999;
    for(int i = 26; i < 51; i++){
        if(d[i][51] < distance){
            result = i;
            distance = d[i][51];
        }
    }

    char toprint = 'A' + result - 26;
    fout << toprint << " " << distance << endl;
}