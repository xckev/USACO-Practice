#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int m, n;
int best = 0;

void solve(int pos, int total, int arr[]){
    if(pos >= n){
        if(total <= m){
            best = max(best, total);
        }
        return;
    }
    else{
        solve(pos+1, total, arr);

        solve(pos+1, total + arr[pos], arr);
    }
}

int main(){
    cin >> m >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    solve(0, 0, arr);

    cout << best << endl;
}