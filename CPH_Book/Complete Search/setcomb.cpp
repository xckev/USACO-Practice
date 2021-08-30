#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;

int n, m;

void printVec(bool picked[], int nums[]){
    vector<int> result;
    for(int i = 0; i < m; i++){
        if(picked[i] == true){
            result.push_back(nums[i]);
        }
    }

    for(int i = 0; i < result.size(); i++){
        cout << result[i];
    }
    cout << endl;
}

void combo(int e, int numChosen, bool picked[], int a[]){
    if(e == m){
        if(numChosen == n){
            printVec(picked, a);
        }
        return;
    }
    else{
        picked[e] = true;
        combo(e+1, numChosen+1, picked, a);
        picked[e] = false;
        combo(e+1, numChosen, picked, a);
    }

}

int main(){
    cin >> m;

    int a[m];
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }

    cin >> n;

    bool picked[m];

    combo(0, 0, picked, a);
}