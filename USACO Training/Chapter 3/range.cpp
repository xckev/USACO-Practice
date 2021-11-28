/*
ID: xckevin1
LANG: C++
TASK: range
*/

//2d prefix sums

#include <bits/stdc++.h>
using namespace std;

int N;
int field[252][252];
map<int, int> ans;

int main(){
    ofstream fout ("range.out");
    ifstream fin ("range.in");
    fin >> N;

    for(int i = 1; i <= N; i++){
        string s;
        fin >> s;
        for(int j = 1; j <= N; j++){
            char c = s[j-1];
            if(c == '1'){
                field[i][j] = 1;
            }
            else{
                field[i][j] = 0;
            }
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int a = field[i-1][j];
            int b = field[i][j-1];
            int c = field[i-1][j-1];
            int d = field[i][j];

            field[i][j] = a + b - c + d;
            //cout << i << ", " << j << ": " << field[i][j] << endl;
            //cout << a << " + " << b << " - " <<  c << " + " <<  d << " = " << field[i][j] << endl;
        }
    }

    for(int y = 1; y < N; y++){
        for(int x = 1; x < N; x++){
            for(int side = 2; side <= N; side++){
                if(x + side - 1 <= N && y + side - 1 <= N){
                    int ideal = side*side;
                    int pfxsum = field[y+side-1][x+side-1] - field[y-1][x+side-1] - field[y+side-1][x-1] + field[y-1][x-1];
                    
                    if(pfxsum == ideal){
                        ans[side] = ans[side] + 1;
                    }
                }
            }
        }
    }

    for(pair<int, int> p : ans){
        fout << p.first << " " << p.second << endl;
    }


}