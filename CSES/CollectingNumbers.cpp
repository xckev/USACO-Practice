#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <set>
#include <fstream>
using namespace std;

int n;
//vector<int> v;
int arr[200001];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int e;
        cin >> e;
        //v.push_back(e);
        arr[e] = i;
    }

    int counter = 1;
    for(int i = 1; i <= n-1; i++){
        int ind1 = arr[i];
        int ind2 = arr[i+1];

        if(ind1 > ind2){
            counter++;
        }
    }

    cout << counter << endl;

}