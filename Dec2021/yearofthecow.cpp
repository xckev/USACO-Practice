#include <bits/stdc++.h>
using namespace std;

//feb 2021

int n, k;
set<int> periods;
vector<int> skips;

int main(){
    cin >> n >> k;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int year;
        cin >> year;
        int per = (year+11)/12;
        periods.insert(per);
        ans = max(ans, per);
    }

    int prev = 0;
    while(!periods.empty()){
        int first = *periods.begin();
        int s = first - prev - 1;
        skips.push_back(s);
        prev = first;
        periods.erase(periods.begin());
    }
    sort(skips.rbegin(), skips.rend());

    for(int i = 0; i < skips.size(); i++){
        if(i >= k-1){
            break;
        }
        ans -= skips[i];
    }
    cout << ans*12 << endl;
}