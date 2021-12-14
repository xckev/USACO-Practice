#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;


int N, M;
bool bad, vis[100001], group[100001];
vector<int> a[100001];

void dfs(int n, bool g)
{
	vis[n]=1;
	group[n]=g;
	for(int u:a[n])
		if(vis[u])
		{
			if(group[u]==g)
				bad=1;
		}
		else{
            dfs(u, !g);
        }	
}
int main()
{
	cin >> N >> M;
	for(int i = 0; i < M; i++){
        int u;
        int v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
		
	for(int i = 1 ; !bad && i <= N; i++){
        if(!vis[i]){
            dfs(i, false);
        }
    }
		
	if(bad)
		cout << "IMPOSSIBLE" << endl;
	else{
        for(int i=1;i<=N;++i){
            cout << group[i]+1 << " ";
            if(i == N){
                cout << endl;
            }
        }
    }
}