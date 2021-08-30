#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;

int n, b;
int minExcess = INT_MAX;

void heightSum(bool picked[], int nums[]){
    vector<int> result;
    for(int i = 0; i < n; i++){
        if(picked[i] == true){
            result.push_back(nums[i]);
        }
    }

    int res = 0;
    for(int i = 0; i < result.size(); i++){
        res += result[i];
    }
    if(res >= b && res-b < minExcess){
        minExcess = res-b;
    }
}

void combo(int e, int lim, int numChosen, bool picked[], int a[]){
    if(e == n){
        if(numChosen == lim){
            heightSum(picked, a);
        }
        return;
    }
    else{
        picked[e] = true;
        combo(e+1, lim, numChosen+1, picked, a);
        picked[e] = false;
        combo(e+1, lim, numChosen, picked, a);
    }

}

int main(){
    cin >> n >> b;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    
    for(int i = 1; i <= n; i++){
        bool picked[n];
        combo(0, i, 0, picked, a);
    }
    cout << minExcess << endl;
}