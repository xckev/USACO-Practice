/*
ID: xckevin1
LANG: C++
TASK: lamps
*/

//

#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n, c;
vector<int> on;
vector<int> off;
set<vector<int>> storage[10001];

bool check(vector<int> lamps){
    for(int x : on){
        if(lamps[x] != 1){
            return false;
        }
    }
    for(int x : off){
        if(lamps[x] != 0){
            return false;
        }
    }
    return true;
}

vector<int> button1(vector<int> before){
    for(int i = 1; i <= n; i++){
        before[i] = 1-before[i];
    }
    return before;
}

vector<int> button2(vector<int> before){
    for(int i = 1; i <= n; i+=2){
        before[i] = 1-before[i];
    }
    return before;
}

vector<int> button3(vector<int> before){
    for(int i = 2; i <= n; i+=2){
        before[i] = 1-before[i];
    }
    return before;
}

vector<int> button4(vector<int> before){
    for(int i = 1; i <= n; i+=3){
        before[i] = 1-before[i];
    }
    return before;
}

int main(){
    ofstream fout ("lamps.out");
    ifstream fin ("lamps.in");
    fin >> n >> c;

    int e;
    fin >> e;
    while (e != -1){
        on.push_back(e);
        fin >> e;
    }

    fin >> e;
    while (e != -1){
        off.push_back(e);
        fin >> e;
    }
    vector<int> v(n+1, 1);
    storage[0].insert(v);

    set<vector<int>> ans;

    for(int i = 1; i <= c; i++){
        for(vector<int> elem : storage[i-1]){

            if((c-(i-1))%2 == 0){
                if(check(elem)){
                    ans.insert(elem);
                }
            }
            storage[i].insert(button1(elem));
            
            storage[i].insert(button2(elem));

            storage[i].insert(button3(elem));

            storage[i].insert(button4(elem));

        }
    }

    //check all before deciding impossible or not
    for(vector<int> elem : storage[c]){
        if(check(elem)){
            ans.insert(elem);
        }
    }


    if(ans.size() == 0){
        fout << "IMPOSSIBLE" << endl;
    }
    else{
        for(vector<int> elem : ans){
            for(int i = 1; i <= n; i++){
                fout << elem[i];
            }
            fout << endl;

        }
    }

}