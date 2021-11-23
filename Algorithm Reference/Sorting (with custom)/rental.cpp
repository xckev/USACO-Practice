#include <bits/stdc++.h>
using namespace std;

//jan 2018

int N, M, R;

int main(){
    ofstream fout ("rental.out");
    ifstream fin ("rental.in");
    fin >> N >> M >> R;

    vector<int> milkrates;
    for(int i = 0; i < N; i++){
        int e;
        fin >> e;
        milkrates.push_back(e);
    }

    int totalbuy = 0;
    vector<pair<int, int>> stores;
    for(int i = 0; i < M; i++){
        int q, p;
        fin >> q >> p;
        stores.push_back({p, q});
    }

    vector<int> rentals;
    for(int i = 1; i <= R; i++){
        int e;
        fin >> e;
        rentals.push_back(e);
    }


    
    sort(milkrates.rbegin(), milkrates.rend());
    sort(stores.rbegin(), stores.rend());
    sort(rentals.rbegin(), rentals.rend());
    
    vector<long long> pfx;
    pfx.push_back(0);
    for(int i = 1; i <= R; i++){
        int e = rentals[i-1];
        pfx.push_back(pfx[i-1] + e);
    }

    long long best = 0;

    for(int torent = 0; torent < min(R, N); torent++){
        //cout << "renting " << torent <<endl;
        long long profit = 0;
        profit += pfx[torent];

        int tosell = N - torent;
        //cout << "selling " << tosell <<endl;
        int sellind = 0;
        int currdemand = stores[sellind].second;
        int cowsind = 0;
        int currsupply = milkrates[cowsind];
        while(sellind < M && cowsind < tosell){
            if(currsupply < currdemand){
                currdemand -= currsupply;
                profit += currsupply * stores[sellind].first;
                cowsind++;
                currsupply = milkrates[cowsind];
            }
            else if(currsupply > currdemand){
                currsupply -= currdemand;
                profit += currdemand * stores[sellind].first;
                sellind++;
                currdemand = stores[sellind].second;
            }
            else{
                profit += currdemand * stores[sellind].first;
                cowsind++;
                sellind++;
                currsupply = milkrates[cowsind];
                currdemand = stores[sellind].second;
            }
        }

        best = max(best, profit);

    }
    fout << best << endl;
}