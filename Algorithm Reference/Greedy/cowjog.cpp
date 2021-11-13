#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, T;
vector<pair<ll, int>> v; // {distance supposed to end at, cow number}

bool comparecows(pair<ll, int> p1, pair<ll, int> p2){
    if(p1.first < p2.first){
        return true;
    }
    else if(p1.first == p2.first){
        if(p1.second > p2.second){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

int main(){
    ofstream fout ("cowjog.out");
    ifstream fin ("cowjog.in");
    fin >> N >> T;

    for(int i = 1; i <= N; i++){
        ll init, speed;
        fin >> init >> speed;
        v.push_back({init + (speed * T), i});
    }

    sort(v.begin(), v.end(), comparecows);

    ll total = 1;
    ll maxnum = v[0].second;
    for(int i = 0; i < N; i++){
        pair<ll, int> p = v[i];
        ll pos = p.first;
        int num = p.second;
        //cout << "num: " << num;
        //cout << ", pos: " << pos << endl;

        if(num > maxnum){
            total++;
            maxnum = num;
        }
    }
    //cout << total << endl;
    fout << total << endl;
}