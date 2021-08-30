#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;

struct endpoint{
    int x;
    int type; //0-left, 1-right
};

bool comp(endpoint e1, endpoint e2){
    return e1.x < e2.x;
}

int main(){
    int n;
    cin >> n;

    vector<endpoint> data;

    int location = 0;
    for(int i = 0; i < n; i++){
        int dist;
        string type;
        cin >> dist >> type;
        endpoint l, r;
        l.type = 0;
        r.type = 1;
        if(type == "R"){
            l.x = location;
            r.x = location + dist;
            location += dist;
        }
        else{
            l.x = location - dist;
            r.x = location;
            location -= dist;
        }
        data.push_back(l);
        data.push_back(r);
    }

    sort(data.begin(), data.end(), comp);

    int total = 0;
    int active = 0;
    int last = 0;
    for(int i = 0; i < data.size(); i++){
        endpoint e = data[i];
        if(active >= 2){
            total += abs(e.x - last);
        }
        if(e.type == 0){
            active++;
        }
        else{
            active--;
        }
        last = e.x;
    }
    cout << total << endl;
}