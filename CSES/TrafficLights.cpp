#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

multiset<int> s;
set<int> lights;
int x, n;

int main(){
    cin >> x >> n;

    lights.insert(0);
    lights.insert(x);
    s.insert(x);

    for(int i = 0; i < n; i++){

        int e;
        cin >> e;
        auto it = lights.upper_bound(e);
        auto it2 = it;
        --it2;
        int higher = *it;
        int lower = *it2;
        s.erase(s.find(higher -lower));

        lights.insert(e);

        int lgap = e - lower;
        int rgap = higher - e;
        s.insert(lgap);
        s.insert(rgap);

        auto last = s.end();
        last--;
        if(i == n-1){
            cout << *last << endl;
        }
        else{
            cout << *last << " ";
        }
    }



}