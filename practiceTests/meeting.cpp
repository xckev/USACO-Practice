#include <bits/stdc++.h>
using namespace std;

// jan 2015

int n, m;
vector<pair<int, int>> bessieAdj[101];
vector<pair<int, int>> elsieAdj[101];
bool seen[101];
set<int> bessieTimes;
set<int> elsieTimes;

void bessie(int field, int time){
    seen[field] = true;
    if(field == n){
        bessieTimes.insert(time);
    }
    else{
        for(pair<int, int> p : bessieAdj[field]){
            int to = p.first;
            int w = p.second;
            if(!seen[to]){
                bessie(to, time+w);
            }
        }
    }
    seen[field] = false;
}

void elsie(int field, int time){
    seen[field] = true;
    if(field == n){
        elsieTimes.insert(time);
    }
    else{
        for(pair<int, int> p : elsieAdj[field]){
            int to = p.first;
            int w = p.second;
            if(!seen[to]){
                elsie(to, time+w);
            }
        }
    }
    seen[field] = false;
}

int main(){
    ifstream fin("meeting.in");
    ofstream fout("meeting.out");
    fin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        bessieAdj[a].push_back({b, c});
        elsieAdj[a].push_back({b, d});
    }

    memset(seen, false, sizeof(seen));
    bessie(1, 0);
    memset(seen, false, sizeof(seen));
    elsie(1, 0);
    
    if(bessieTimes.empty() || elsieTimes.empty()){
        fout << "IMPOSSIBLE" << endl;
    }
    else{
        auto bessieIt = bessieTimes.begin();
        int bessieInd = 0;
        auto elsieIt = elsieTimes.begin();
        int elsieInd = 0;

        bool found = false;
        while(elsieInd < elsieTimes.size() && bessieInd < bessieTimes.size()){
            if(*bessieIt == *elsieIt){
                found = true;
                fout << *bessieIt << endl;
                break;
            }
            else if(*bessieIt > *elsieIt){
                elsieIt++;
                elsieInd++;
            }
            else if(*bessieIt < *elsieIt){
                bessieIt++;
                bessieInd++;
            }
        }
        if(!found){
            fout << "IMPOSSIBLE" << endl;
        }
    }
}