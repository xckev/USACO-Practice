#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

//jan 2016

int n, k;
set<int> bales;

int main(){
    ofstream fout ("angry.out");
    ifstream fin ("angry.in");
    fin >> n >> k;

    int e;
    for(int i = 0; i < n; i++){
        fin >> e;
        bales.insert(e);
    }

    int lo = 1;
    auto last = bales.end();
    last--;
    int hi = *last - *bales.begin();
    int ans = 1000000000;
    //cout<< hi << endl;

    while(lo <= hi){
        int mid = (lo + hi + 1)/2;
        //cout << "r: " << mid << endl;
        int j = 0;
        auto pos = bales.begin();
        int currstart = *pos;
        int birds = 1;
        while(j < n){
            int s = *pos;
            if(s <= currstart + (2*mid)){
                //cout << s << " is within " << (2*mid) << " of " << currstart << endl;
                j++;
                pos++;
            }
            else{
                currstart = *pos;
                birds++;
                //cout << s << " is not within " << (2*mid) << " of " << currstart << ", new currstart is " << currstart << endl;
            }
        }
        //cout<< "birds: " << birds << endl;
        if(birds <= k){
            ans = min(ans, mid);
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }

    fout << ans << endl;
}