#include <bits/stdc++.h>
using namespace std;

int k, m, n;
vector<int> patches;
map<int, int> taste;
vector<int> nhoj;

vector<int>::iterator hi;
vector<int>::iterator lo;

long long getscore(double john, int left, int right){
    long long res = 0;
    auto it = lo;
    while(hi > it){
        int farmpos = *it;
        int leftdist = farmpos - left;
        int rightdist = right - farmpos;
        int best = min(leftdist, rightdist);
        double johndist = abs(farmpos - john);

        if(johndist < best){
            res += taste[farmpos];
        }
        it++;
    }
    return res;
}

int main(){
    cin >> k >> m >> n;

    for(int i = 0; i < k; i++){
        int p, t;
        cin >> p >> t;
        patches.push_back(p);
        taste[p] = t;
    }
    sort(patches.begin(), patches.end());

    for(int i = 0; i < m; i++){
        int f;
        cin >> f;
        nhoj.push_back(f);
    }
    //nhoj.push_back(1000000000);//what happens at last chunk ?
    sort(nhoj.begin(), nhoj.end());

    //chunking number line

    int left;
    int right;
    vector<long long> cowscores;
    //before 1st nhoj
    int lim = nhoj[0];
    int sum = 0;
    for(int i = 0; i < k && patches[i] < lim; i++){
        sum += taste[patches[i]];
    }
    cowscores.push_back(sum);

    //after last nhoj
    lim = nhoj[m-1];
    auto iter = upper_bound(patches.begin(), patches.end(), lim);
    sum = 0;
    while(iter < patches.end()){
        sum += taste[*iter];
        iter++;
    }
    cowscores.push_back(sum);

    for(int i = 1; i < m; i++){
        left = nhoj[i-1];
        right = nhoj[i];
        
        lo = lower_bound(patches.begin(), patches.end(), left);
        hi = lower_bound(patches.begin(), patches.end(), right);
        if(lo == patches.end()){
            continue;
        }


        auto it = lo;
        long long totaltaste = 0;
        long long best = 0;
        while(hi > it){
            int farmpos = *it;
            int leftdist = farmpos - left;
            int rightdist = right - farmpos;
            double better = min(leftdist, rightdist)-0.5;

            double candpos1 = farmpos - better;
            double candpos2 = farmpos + better;

            long long score1 = getscore(candpos1, left, right);
            long long score2 = getscore(candpos2, left, right);
            

            long long bestscore = max(score1, score2);
            best = max(best, bestscore);

            totaltaste += taste[farmpos];
            it++;
        }
        cowscores.push_back(best);
        cowscores.push_back(totaltaste - best);
    }
    sort(cowscores.rbegin(), cowscores.rend());

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += cowscores[i];
    }
    cout << ans << endl;
}