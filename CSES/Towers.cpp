#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n;
multiset<int> tops;


int main(){
    cin >> n;

    int num = 0;
    for(int i = 0; i < n; i++){
        int e;
        cin >> e;
        auto it = tops.upper_bound(e);

        if(it == tops.end()){
            tops.insert(e);
            num++;
        }
        else{
            tops.erase(it);
            tops.insert(e);
        }
    }

    cout << num << endl;
}