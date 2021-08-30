#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;

int n, m;

void printNums(int digits[]){
    for(int i = 0; i < n; i++){
        cout << digits[i];
    }
    cout << endl;
}

void generate(int d, int digits[], int a[]){
    if(d == n){
        printNums(digits);
        return;
    }
    else{
        for(int i = 0; i < m; i++){
            int num = a[i];
            digits[d] = num;
            generate(d+1, digits, a);
        }
    }
}

int main(){
    
    cin >> m;

    int a[m];
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }

    cin >> n;

    int digits[n];
    generate(0, digits, a);
}