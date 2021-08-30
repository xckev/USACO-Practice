#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
int counter;

void check(int cows[], vector<tuple<int, int>> sames, vector<tuple<int, int>> diffs){
    bool good = true;
    for(int i = 0; i < sames.size(); i++){
        int ind1 = get<0>(sames[i]);
        int ind2 = get<1>(sames[i]);
        if(cows[ind1] != cows[ind2]){
            good = false;
            return;
        }
    }
    for(int i = 0; i < diffs.size(); i++){
        int ind1 = get<0>(diffs[i]);
        int ind2 = get<1>(diffs[i]);
        if(cows[ind1] == cows[ind2]){
            good = false;
            return;
        }
    }
    if(good){
        counter++;
    }
}

void generate(int e, int cows[], vector<tuple<int, int>> sames, vector<tuple<int, int>> diffs){
    if(e == n){
        check(cows, sames, diffs);
    }
    else{
        cows[e] = 0;
        generate(e+1, cows, sames, diffs);
        cows[e] = 1;
        generate(e+1, cows, sames, diffs);
        cows[e] = 2;
        generate(e+1, cows, sames, diffs);
    }
}

int main(){
    cin >> n >> k;
    counter = 0;

    vector<tuple<int, int>> sames;
    vector<tuple<int, int>> diffs;

    for(int i = 0; i < n; i++){
        string lett, i1, i2;
        cin >> lett >> i1 >> i2;
        if(lett == "S"){
            sames.push_back(tuple<int, int>{stoi(i1), stoi(i2)});
        }
        else{
            diffs.push_back(tuple<int, int>{stoi(i1), stoi(i2)});
        }
    }

    int cows[n];
    generate(0, cows, sames, diffs);

    cout << counter << endl;
}