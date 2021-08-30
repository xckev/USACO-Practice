/*
ID: xckevin1
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    int n;
    fin >> n;

    map<string, int> money;
    vector<string> order;
    for(int i = 0; i < n; i++){
        string s = "";
        fin >> s;
        order.push_back(s);
        money[s] = 0;
    }

    for(int i = 0; i < n; i++){
        string giver = "";
        fin >> giver;

        int dollars, div;
        fin >> dollars >> div;
        money[giver] -= dollars;

        if(div == 0){
            continue;
        }
        int quot = dollars / div;
        int rem = dollars % div;

        for(int j = 0; j < div; j++){
            string name = "";
            fin >> name;

            money[name] += quot;

            //cout << "reciever: " << name << " -> " << money[name] << endl;
        }
        money[giver] += rem;
        //cout << "giver: " << giver << " -> " << money[giver] << endl;
    }

    for(int i = 0; i < n; i++){
        string name = order[i];
        fout << name << " " << money[name] << endl;
    }
}