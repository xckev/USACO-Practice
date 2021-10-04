/*
ID: xckevin1
LANG: C++
TASK: money
*/

// make it so order doesnt matter

#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int v;
long long n;
long long storage[10001];

int main(){
    cin >> v >> n;
    vector<int> coins(v, 0);
    for(int i = 0; i < v; i++){
        int e;
        cin >> e;
        coins.push_back(e);
    }

    storage[0] = 1;

    for(int i = 1; i <= n; i++){
        for(int e : coins){
            if(i - e >= 0){
                storage[i] += storage[i-e];
            }
        }
        cout << "ways to make " << i << ": " << storage[i] << endl;
    }

    cout << storage[n] << endl;
    
}