#include <bits/stdc++.h>
using namespace std;

int N;
long long ans = 0;

struct Node{
    bool inuse = true;
    set<pair<int, long long>> incoming;
    pair<int, long long> outgoing;
};

Node nodes[100001];
int components[100001];
bool seen[100001];

long long total;
long long minmoo;

void fill(int i, int compnum){
    //cout << "on node " << i << endl;
    seen[i] = true;
    components[i] = compnum;

    long long w = nodes[i].outgoing.second;
    total += w;
    minmoo = min(minmoo, w);
    //cout << "weight is " << w << endl;

    //cout << "current total: " << total << endl;
    //cout << "current minmoo: " << minmoo << endl;
    
    int dest = nodes[i].outgoing.first;
    if(!seen[dest] && nodes[dest].inuse){
        fill(dest, compnum);
    }
}

void recursiveremove(int i){
    //cout << "removing node " << i << endl;
    long long w = nodes[i].outgoing.second;
    ans += w;
    //cout << "weight was: " << w << endl;
    //cout << "current ans: " << ans << endl;
    int dest = nodes[i].outgoing.first;
    nodes[dest].incoming.erase({i, w}); 
    nodes[i].inuse = false;
    if(nodes[dest].incoming.size() == 0){
        recursiveremove(dest);
    }
}

int main(){
    cin >> N;

    memset(components, 0, sizeof(components));
    memset(seen, false, sizeof(seen));

    for(int i = 1; i <= N; i++){
        Node n;
        nodes[i] = n;
    }

    for(int i = 1; i <= N; i++){
        int c;
        long long w;
        cin >> c >> w;
        nodes[i].outgoing = {c, w};
        nodes[c].incoming.insert({i, w});
    }

    for(int i = 1; i <= N; i++){
        if(nodes[i].incoming.size() == 0 && nodes[i].inuse){
            recursiveremove(i);
        }
    }
    /*
    cout << "After removals: " << endl;
    for(int i = 1; i <= N; i++){
        if(nodes[i].inuse){
            cout << "node " << i << " IN USE" << endl;
        }
        else{
            cout << "node " << i << " NOT IN USE" << endl;
        }
    }*/

    //cout << "ans so far: " << ans << endl;

    int compnum = 1;
    for(int i = 1; i <= N; i++){
        if(nodes[i].inuse && !seen[i]){
            //cout << "node " << i << " in use and not seen, start floodfill" << endl;
            total = 0;
            minmoo = LONG_LONG_MAX;
            fill(i, compnum);
            compnum++;

            ans += (total - minmoo);
        }
    }

    cout << ans << endl;
}