#include <bits/stdc++.h>
using namespace std;

//open 2021

int n, m;
vector<pair<long long, long long>> segments;

bool good(long long mid){
    long long place = segments[0].first;
    int ind = 0;
    for (int i = 1; i < n; i++){
        if (place + mid > segments[ind].second){
            while (segments[ind].second < place + mid){
                ind++;
                if (ind >= m){
                    return false;
                }
            }
            place = max(segments[ind].first, place + mid);
        }
        else{
            place += mid;
        }
    }
    return true;
}

int main()
{
    ifstream fin("socdist.in");
    ofstream fout("socdist.out");
    fin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        long long a, b;
        fin >> a >> b;
        segments.push_back({a, b});
    }
    sort(segments.begin(), segments.end());

    long long l = 0;
    long long r = 1000000000000000001;
    while (l < r){
        long long mid = (l + r + 1) / 2;

        if (good(mid)){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }

    fout << l << endl;
}