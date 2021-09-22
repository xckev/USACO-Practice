#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

//Dynamic

int n;
int storage[1000001];

int main(){
    cin >> n;

    for(int i = 0; i <= n; i++){
        storage[i] = 0;
    }
    storage[0] = 1;


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(i - j >= 0){
                storage[i] = (storage[i] + storage[i-j]) % 1000000007;
            }

        }
    }
    

    cout << storage[n] << endl;
}