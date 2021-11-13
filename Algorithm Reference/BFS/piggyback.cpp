#include <bits/stdc++.h>
using namespace std;

int B, E, P, N, M;
int dist1[40001];
int dist2[40001];
int distn[40001];
vector<int> adj[40001];

void findDistTo(int x, int v[]){ //BFS
    queue<int> q;
    //bool visited[N];
    v[x] = 0;
    //visited[x] = true;
    q.push(x);
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(int u : adj[s]){
            if(v[u] == -1){
                //visited[u] = true;
                v[u] = v[s]+1;
                q.push(u);
            }
        }
    }
}

int main(){
    ofstream fout ("piggyback.out");
    ifstream fin ("piggyback.in");
    fin >> B >> E >> P >> N >> M;

    for(int i = 0; i < M; i++){
        int a, b;
        fin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    fill(dist1, dist1+40001, -1);
    fill(dist2, dist2+40001, -1);
    fill(distn, distn+40001, -1);

    findDistTo(1, dist1);
    findDistTo(2, dist2);
    findDistTo(N, distn);

    int ans = 99999999;
    for(int i = 1; i <= N; i++){ //for each possible meeting point
        //cout << distn[i] << endl;
        if(dist1[i] == -1 || dist2[i] == -1 || distn[i] == -1){
            //cout << "here" << endl;
            continue;
        }
        else{
            int distfrom1 = B * (dist1[i]);
            int distfrom2 = E * (dist2[i]);
            int distfromn = P * (distn[i]);
            ans = min(ans, distfrom1 + distfrom2 + distfromn);
        }
        
    }

    fout << ans << endl;

}