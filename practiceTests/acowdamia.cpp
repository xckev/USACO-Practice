#include <bits/stdc++.h>
using namespace std;

//2021 open

int n;
long long k, l;
vector<int> papers(100001);

bool check(int m){
    long long area = 0; //area needed to be made up through surveys
    for(int i = 0; i < m; i++){
        if(papers[i] < m){
            area += m - papers[i];
            if(abs(m - papers[i]) > k){
                return false;
            }
        }
    }
    if(area <= l*k){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    cin >> n >> k >> l;
    papers.resize(n);
    for(int i = 0; i < n; i++){
        cin >> papers[i];
    }
    sort(papers.rbegin(), papers.rend());

    int lo = 0;
    int hi = n;
    while(lo < hi){
        int mid = (lo + hi + 1) / 2; //!
        if(check(mid)){
            lo = mid;
        }
        else{
            hi = mid - 1;
        }
    }
    cout << lo << endl;
}