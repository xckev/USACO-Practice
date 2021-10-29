#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

multiset<int> h;
int n, m;

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int e;
        cin >> e;
        h.insert(e);
    }

    for(int i = 0; i < m; i++){
        int q;
        cin >> q;
        auto ub = h.upper_bound(q);
        if(ub != h.begin()){
            --ub;
            cout << *ub << endl;
            h.erase(ub);
        }
        else{
            cout << -1 << endl;
        }
        
    }
}