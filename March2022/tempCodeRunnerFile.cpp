#include <bits/stdc++.h>
using namespace std;

int T;

int main(){
    cin >> T;

    for(int i = 0; i < T; i++){
        long long n;
        cin >> n;

        if(n == 1){
            cout << "1 2 3 3" <<endl;
        }
        else{
            cout << n-1 << " " << n << " " << 2*n-1 << " " << 2*n-1 << endl;
        }
    }
}