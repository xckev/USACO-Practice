#include <bits/stdc++.h>
using namespace std;

//KEY IDEAS: if we multiply, we do not want to divide again
//Division/addition first, then multiplication/addition

int n;
long long solve(long long a, long long b){
    if(a > b){
        return 99999999;
    }
    if(a == b){
        return 0;
    }
    if(b % 2 == 0 && a <= (b/2)){
        return solve(a, b/2) + 1;
    }
    else if(a > b/2){
        long long diff = b-a;
        return solve(a, b-diff) + diff;
    }
    else{
        return solve(a, b-1) + 1;
    }
}

int main(){
    cin >> n;
    
    for(int i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;


        long long best = solve(a, b);
        long long firstnum = a;
        long long numdiv = 0;
        long long numadd = 0;

        while(firstnum > 1){
            if(firstnum % 2 == 0){
                firstnum /= 2;
                numdiv++;
                best = min(best, numdiv + numadd + solve(firstnum, b));
            }
            else{
                firstnum++;
                numadd++;
            }
        }

        cout << best << endl;
    }
    
}