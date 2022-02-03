#include <bits/stdc++.h>
using namespace std;

int n;
long long cows[300005]; //pos[position of cow] = cowheight
long long pos[300005]; //pos[cowheight] = position of cow

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        long long e;
        cin >> e;

        cows[i] = e;
        pos[e] = i;
    }

    set<long long> positionsused; //sorted set of all positions seen
    positionsused.insert(pos[n]); //insert position of cow n
    long long total = 0;
    //going thru cows highest to lowest
    for(long long i = n-1; i >= 1; i--){
        long long p = pos[i]; //position of cow with height i
        positionsused.insert(p);

        long long maxp = *positionsused.rbegin(); //highest position seen
        long long minp = *positionsused.begin(); //lowest position seen

        if(minp < p){ //if there exists a seen position lower than current cow
            auto closeleft = positionsused.lower_bound(p);
            closeleft--; //iterator closeleft is now at the closest neighbor to the left
            long long poscl = *closeleft; 
            total += (p - poscl)+1;
        }
        if(maxp > p){ //if there exists a seen position higher than current cow
            auto closeright = positionsused.upper_bound(p); //iterator closeright is now at the closest neighbor to the right
            long long poscr = *closeright;
            total += (poscr - p)+1;
        }
        
    }

    cout << total << endl;
}