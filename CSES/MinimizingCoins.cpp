#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

//Dynamic

int n, x;
int coins[101];
int storage[1000001];

int main(){
    cin >> n >> x;

    fill_n(storage, 1000001, -1);

    for(int i = 0; i < n; i++){
        cin >> coins[i];
        storage[coins[i]] = 1;
    }

    for(int i = 1; i <= x; i++){
        if(storage[i] != 1){
            int val = 9999999;
            for(int j = 0; j < n; j++){
                int c = coins[j];
                if(i-c >= 0){
                    if(storage[i-c] != -1){
                        val = min(val, storage[i-c] + storage[c]);
                        //cout << "best for " << i << ": " << i-c << " and " << c << endl;
                    }
                }
            }
            if(val != 9999999){
                storage[i] = val;
            }
        }
    }

    cout << storage[x] << endl;
}