#include <bits/stdc++.h>
using namespace std;

long long N;
long long ans = 0;

struct Node{
    bool inuse = true;
    set<pair<long long, long long>> incoming;
    pair<long long, long long> outgoing;
};

Node nodes[100001];
long long components[100001];
bool seen[100001];

long long total;
long long minmoo;

void fill(long long i, long long compnum){
    seen[i] = true;
    components[i] = compnum;

    long long w = nodes[i].outgoing.second;
    total += w;
    minmoo = min(minmoo, w);
    
    long long dest = nodes[i].outgoing.first;
    if(!seen[dest] && nodes[dest].inuse){
        fill(dest, compnum);
    }
}

void recursiveremove(long long i){
    long long w = nodes[i].outgoing.second;
    ans += w;
    long long dest = nodes[i].outgoing.first;
    nodes[dest].incoming.erase({i, w}); 
    //need to delete from nodes array too
    nodes[i].inuse = false;
    if(nodes[dest].incoming.size() == 0){
        recursiveremove(dest);
    }
}

int main(){
    cin >> N;

    memset(components, 0, sizeof(components));
    memset(seen, false, sizeof(seen));

    for(long long i = 1; i <= N; i++){
        Node n;
        nodes[i] = n;
    }

    for(long long i = 1; i <= N; i++){
        long long c;
        long long w;
        cin >> c >> w;
        nodes[i].outgoing = {c, w};
        nodes[c].incoming.insert({i, w});
    }

    for(long long i = 1; i < N; i++){
        if(nodes[i].incoming.size() == 0){
            recursiveremove(i);
        }
    }

    long long compnum = 1;
    for(long long i = 1; i <= N; i++){
        if(nodes[i].inuse && !seen[i]){
            total = 0;
            minmoo = LONG_LONG_MAX;
            fill(i, compnum);
            compnum++;

            ans += (total - minmoo);
        }
    }

    cout << ans << endl;
}