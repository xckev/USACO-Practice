#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

//jan 2020

long long n, k, m;

int valid(long long n, long long k, long long m, long long x) {
    long long g = 0;
    while(k > 0 && g < n) {
        long long y = (n - g) / x;
        if(y < m) {
            long long leftover = (n-g + m-1) / m;
            return leftover <= k;
        }
        long long maxmatch = n - x*y;
        long long numdays = (maxmatch - g) / y + 1;
        if(numdays > k){
            numdays = k;
        }
        g += y * numdays;
        k -= numdays;
    }
    return g >= n;
}

int main(){
    ofstream fout ("loan.out");
    ifstream fin ("loan.in");
    fin >> n >> k >> m;

    long long hi = (n/m);
    long long lo = 1;
    long long ans = 1;

    while(lo <= hi){
        long long mid = (lo + hi + 1)/2;
        if(valid(n, k, m, mid)){
            ans = max(ans, mid);
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }

    }

    fout << ans << endl;

}