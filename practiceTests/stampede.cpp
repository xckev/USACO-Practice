#include <bits/stdc++.h>
using namespace std;

// jan 2015

int n;

struct Event{
    int time;
    int type; //0 is start, 1 is end
    int y;
};

bool cmp(Event c1, Event c2){
    return c1.time < c2.time;
}

vector<Event> v;

int main(){
    ifstream fin("stampede.in");
    ofstream fout("stampede.out");
    fin >> n;

    int x, y, r;
    for(int i = 0; i < n; i++){
        fin >> x >> y >> r;
        int t = -(x * r);
        Event e1;
        e1.time = t - r;
        e1.type = 0;
        e1.y = y;
        v.push_back(e1);
        Event e2;
        e2.time = t;
        e2.type = 1;
        e2.y = y;
        v.push_back(e2);
    }

    sort(v.begin(), v.end(), cmp);

    int curr = 0;
    set<int> active;
    set<int> seen;
    while(curr < v.size()){
        Event e = v[curr];
        int same = curr;
        while(same < v.size() && v[same].time == e.time){
            if(v[same].type == 0){
                active.insert(v[same].y);
            }
            else{
                active.erase(v[same].y);
            }
            same++;
        }

        if(!active.empty()){
            seen.insert(*active.begin());
        }

        curr = same;
    }
    fout << seen.size() << endl;
}