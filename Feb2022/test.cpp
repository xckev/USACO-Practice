#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    cout << (rand()*5 % 20) <<" " << (rand()*5 % 20) << endl;

    for(int i = 0; i < n; i++){
        int neg1 = rand() % 10;
        int neg2 = rand() % 10;
        int n1 = rand()*5 % 20;
        int n2 = rand()*5 % 20;
        if(neg1 > 7){
            n1 *= -1;
        }
        if(neg2 > 7){
            n2 *= -1;
        }
        cout << n1 << " " << n2 << endl;
    }
}