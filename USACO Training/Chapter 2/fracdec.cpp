/*
ID: xckevin1
LANG: C++
TASK: fracdec
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n, d;
int col = 0;

void display(string x){
    for (char c : x){
        if(col == 76){
            cout << endl;
            col = 0;
        }
        cout << c;
        col++;
    }
}

int main(){
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);
    cin >> n >> d;

    if(n % d == 0){
        display(to_string(n/d));
        display(".0");
    }
    else{
        display(to_string(n/d));
        display(".");
        n = n % d;

        vector<int> values;
        map<int, int> position;
        while(true){
            int n2 = n * 10;
            int dig = n2 / d;

            n2 = n2 % d;
            if(n == 0){
                for(int i = 0; i < values.size(); i++){
                    display(to_string(values[i]));
                }
                break;
            }
            if(position.find(n) != position.end()){
                for(int i = 0; i < position[n]; i++){
                    display(to_string(values[i]));
                }
                display("(");
                for(int i = position[n]; i < values.size(); i++){
                    display(to_string(values[i]));
                }
                display(")");
                break;
            }
            else{
                position[n] = position.size();
                values.push_back(dig);
                n = n2;
            }
        }
    }
    cout << endl;
}