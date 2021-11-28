#include <bits/stdc++.h>
using namespace std;

//open 2017

int N;
vector<pair<int, int>> cows;

bool comp1(pair<int, int> p1, pair<int, int> p2){
    return p1.second < p2.second;
}

int main(){
    ofstream fout ("pairup.out");
    ifstream fin ("pairup.in");
    fin >> N;

    for(int i = 0; i < N; i++){
        int x, y;
        fin >> x >> y;
        cows.push_back({x, y});

    }
    sort(cows.begin(), cows.end(), comp1);

    int p1 = 0;
    int p2 = cows.size()-1;
    long long largest = 0;
    while(p1 < p2){
        pair<int, int> pair1 = cows[p1];
        pair<int, int> pair2 = cows[p2];
        long long time = pair1.second + pair2.second;
        largest = max(largest, time);
        int numdiff = abs(pair1.first - pair2.first);

        if(pair1.first < pair2.first){
            p1++;
            cows[p2].first = numdiff;
        }
        else if(pair1.first < pair2.first){
            p1++;
            p2--;
        }
        else{
            p2--;
            cows[p1].first = numdiff;
        }
    }

    fout << largest << endl;
}