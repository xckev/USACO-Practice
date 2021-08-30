/*
ID: xckevin1
LANG: C++
TASK: milk2
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

int n;

struct event{
    int time, type;

    event(int timeP, int typeP){
        time = timeP;
        type = typeP;
    }
};

bool comp(event e1, event e2){
    return e1.time < e2.time;
}

int main(){
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

    fin >> n;

    vector<event> events;
    for(int i = 0; i < n; i++){
        int time1, time2;
        fin >> time1 >> time2;

        event e1 = event(time1, 0);
        event e2 = event(time2, 1);

        events.push_back(e1);
        events.push_back(e2);
    }

    sort(events.begin(), events.end(), comp);

    int current = 0;
    int bestNone = 0;
    int bestMilk = 0;
    int time = events[0].time;

    int currNone = 0, currMilk = 0;
    for(int i = 0; i < events.size(); i++){
        event e = events[i];
        int now = e.time;

        if(current == 0 && now != time){
            currNone += (now - time);
            currMilk = 0;

            bestNone  = max(bestNone, currNone);
        }
        else if(current > 0 && now != time){
            currMilk += (now - time);
            currNone = 0;

            bestMilk = max(bestMilk, currMilk);
        }


        if(e.type == 0){
            current++;
        }
        else{
            current--;
        }

        time = now;
    }

    fout << bestMilk << " " << bestNone << endl;
}