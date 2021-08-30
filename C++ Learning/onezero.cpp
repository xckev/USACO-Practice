#include <iostream>
#include <algorithm>
using namespace std;

int n, half, counter;

void solve(int e, int zeros, string bin){
    if(e == n){
        if(zeros >= half){
            cout << bin << endl;
            counter++;
        }
    }
    else{
        solve(e+1, zeros, bin + "0");
        solve(e+1, zeros+1, bin + "1");
    }
}

int main(){
    cin >> n;
    half = (n/2) + 1;
    counter = 0;

    solve(0, 0, "");

    cout << counter << endl;
}