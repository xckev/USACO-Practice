#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
#include <sstream>
using namespace std;

int n;
/*
void printAll(int arr[]){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
*/
struct path{
    int f1, f2;

    path(int p1, int p2){
        f1 = p1;
        f2 = p2;
    }
};

int main(){

    cin >> n;

    vector<path> v;
    for(int i = 0; i < n-1; i++){
        int p1, p2;
        cin >> p1 >> p2;
        path p = path(p1, p2);
        v.push_back(p);
    }

    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = 1;
    }

    for(int i = 0; i < v.size(); i++){
        path p = v[i];
        arr[p.f1]++;
        arr[p.f2]++;
    }

    sort(arr, arr+n);
    cout << arr[n-1] << endl;

}