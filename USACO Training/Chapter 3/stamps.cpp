/*
ID: xckevin1
LANG: C++
TASK: stamps
*/

//dynamic prog

#include <bits/stdc++.h>
using namespace std;

int n, k;
int storage[2100000]; //stores number of coins to make index i cost
vector<int> costs;

int main(){
    ofstream fout ("stamps.out");
    ifstream fin ("stamps.in");
    fin >> k >> n;

    for(int i = 0; i < n; i++){
        int e;
        fin >> e;
        costs.push_back(e);
        //storage[e] = 1;
    }

    fill(storage, storage+2100000, 99999999);
    storage[0] = 0;

    for(int i = 0; i <= k*10000; i++){
        if(storage[i] > k && storage[i] != 99999999){
            fout << i-1 << endl;
            break;
        }
        else{
            for(int j = 0; j < n; j++){
                int c = costs[j];
                //cout << "min of " << storage[i + c] << " and " << storage[i] + 1 << " is ";
                storage[i + c] = min(storage[i + c], storage[i] + 1);
                //cout << storage[i + c] << endl;
                //cout << "storage[" << (i+c) << "] = " << storage[i+c] << endl;
            }
        }
        
    }
}