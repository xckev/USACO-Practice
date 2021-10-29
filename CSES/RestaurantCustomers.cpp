#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n;
vector<pair<int, int>> customers;

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        customers.push_back({a, 0});
        customers.push_back({b, 1});
    }

    sort(customers.begin(), customers.end());

    int best = 0;
    int curr = 0;

    for(pair<int, int> p : customers){
        int type = p.second;
        if(type == 0){
            curr++;
        }
        else{
            curr--;
        }

        best = max(best, curr);
    }

    cout << best << endl;
}