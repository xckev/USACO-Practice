#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;

int l, c;

void printNum(bool picked[], string a[]){
    for(int i = 0; i < c; i++){
        if(picked[i]){
            cout << a[i];
        }
    }
    cout << endl;
}

void checkNum(bool picked[], string a[]){
    int vowels = 0;
    int cons = 0;
    string vwl = "aeiou";
    for(int i = 0; i < c; i++){
        if(picked[i]){
            string s = a[i];
            if(vwl.find(s) != string::npos){
                vowels++;
            }
            else{
                cons++;
            }
        }
        
        
    }

    if(vowels >= 1 && cons >= 2)
        printNum(picked, a);
}

void combo(int e, int numChosen, bool picked[], string a[]){
    if(e == c){
        if(numChosen == l){
            checkNum(picked, a);
        }
        return;
    }
    else{
        picked[e] = true;
        combo(e+1, numChosen+1, picked, a);
        picked[e] = false;
        combo(e+1, numChosen, picked, a);
    }

}

int main(){
    cin >> l >> c;

    string a[c];
    for(int i = 0; i < c; i++){
        cin >> a[i];
    }

    sort(a, a+c);

    bool picked[c];

    combo(0, 0, picked, a);

}