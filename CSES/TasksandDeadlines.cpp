#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <set>
#include <fstream>
using namespace std;

int n;
vector<pair<int, int>> tasks;



int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        tasks.push_back({a, b});
    }
    sort(tasks.begin(), tasks.end());

    long long score = 0;
    long long currtime = 0;
    for(int i = 0; i < n; i++){
        int dur = tasks[i].first;
        int dead = tasks[i].second;

        currtime += dur;
        score += (dead - currtime);
    }

    cout << score << endl;

}