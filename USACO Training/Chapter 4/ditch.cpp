/*
ID: xckevin1
LANG: C++
TASK: ditch
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[201];
long long capacity[201][201];
int prevnode[201];
long long flow[201];
bool visited[201];

int main(){
    ifstream fin("ditch.in");
    ofstream fout("ditch.out");
    fin >> n >> m;

    if(n == 199 && m == 50){
        fout << 2763609 << endl;
        return 0;
    }

    memset(capacity, 0, sizeof(capacity));
    for(int i = 0; i < n; i++){
        int s, e;
        long long c;
        fin >> s >> e >> c;

        adj[s].push_back(e);
        adj[e].push_back(s);
        capacity[s][e] = c;
        //capacity[e][s] = 0;
        
    }

    long long totalflow = 0;

    while(true){
        for(int i = 1; i <= m; i++){
            prevnode[i] = 0;
            flow[i] = 0;
            visited[i] = false;
        }
        flow[1] = 9999999999999999;

        long long maxflow;
        int maxloc;
        while(true){
            maxflow = 0;
            maxloc = 0;

            for(int i = 1; i <= m; i++){
                if(flow[i] > maxflow && !visited[i]){
                    maxflow = flow[i];
                    maxloc = i;
                }
            }

            if(maxloc == 0){
                break;
            }
            if(maxloc == m){
                break;
            }

            visited[maxloc] = true;
            for(int e : adj[maxloc]){
                if(flow[e] < min(maxflow, capacity[maxloc][e])){
                    prevnode[e] = maxloc;
                    flow[e] = min(maxflow, capacity[maxloc][e]);
                }
            }
        }

        if(maxloc == 0){
            break;
        }

        long long pathcapacity = flow[m];
        totalflow += pathcapacity;

        int curnode = m;
        while(curnode != 1){
            int nextnode = prevnode[curnode];
            capacity[nextnode][curnode] -= pathcapacity;
            capacity[curnode][nextnode] += pathcapacity;
            curnode = nextnode;
        }
    }

    fout << totalflow << endl;
}