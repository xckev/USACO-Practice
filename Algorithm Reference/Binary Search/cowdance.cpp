#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

//jan 2017

int n, T;
vector<int> durs;

int main(){
    ofstream fout ("cowdance.out");
    ifstream fin ("cowdance.in");
    fin >> n >> T;

    int e;
    for(int i = 0; i < n; i++){
        fin >> e;
        durs.push_back(e);
    }

    int lo = 1;
    int hi = n;
    int ans = n;

    while(lo <= hi){
        int mid = (lo + hi + 1)/2;
        int j = 0;
        priority_queue<int> q;
        int size = 0;
        while(size < mid && j < n){
            q.push(-1 * durs[j]);
            size++;
            j++;
        }

        int t = 0;
        while(!q.empty()){
            t += max(0, -1* (q.top() + t));
            q.pop();
            if(j < n){
                q.push(-1 * (durs[j] + t));
                j++;
            }
        }

        if(t > T){
            lo = mid + 1;
        }
        else{
            ans = min(ans, mid);
            hi = mid - 1;
        }
    }

    fout << ans << endl;
}