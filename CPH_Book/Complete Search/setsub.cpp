#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;

int n;

void printVec(vector<int> vec){
    for(int x : vec){
        cout << x;
    }
    cout << endl;

}

void subset(int e, vector<int> arr, int nums[]){
    
    if(e == n){
        printVec(arr);
    }
    else{
        subset(e+1, arr, nums);
        arr.push_back(nums[e]);
        subset(e+1, arr, nums);
        arr.pop_back();
    }
}

int main(){
    cin >> n;

    int a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> arr;
    subset(0, arr, a);
}