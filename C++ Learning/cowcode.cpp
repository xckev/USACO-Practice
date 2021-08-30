#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n;


int main(){
    string code;
    cin >> code >> n;
    n = n-1;
    int l = code.size();
    
    while(l < n){
        l = l*2;
    }

    while(l > code.size()){
        if(n == l/2){
            n = n-1;
        }
        else if(n > l/2){
            n = n - (l/2) - 1;
        }
        else{
            l = l/2;
        }
    }
    
    
    cout << code[n] << endl;
}