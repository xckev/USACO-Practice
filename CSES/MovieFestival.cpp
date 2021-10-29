#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n;
vector<pair<int, int>> movies;

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        movies.push_back({b, a}); // ending first, start second
    }

    sort(movies.begin(), movies.end());

    int pos = 0;
    int total = 0;
    for(pair<int, int> p : movies){
        if(p.second >= pos){
            total++;
            pos = p.first;
        }
    }

    cout << total << endl;
}