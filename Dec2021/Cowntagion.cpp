#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100000

int N;
int d[MAXN]; //num of children nodes


int main()
{
	cin >> N;
	int a, b;
	for(int i = 0; i < N-1; i++)
	{
		cin >> a >> b;
		a--,b--;
		d[a]++, d[b]++;
	}
	int ans = N-1; // number of move events
	for(int i = 0; i < N; i++)
		if(d[i] > 1 || i == 0)	// check that i is not leaf node in tree
		{
			int children = d[i];
			if(i != 0){
                children--;
            }
			// compute ceil(log(children + 1))
			int log_children = 0;
			int pow = 1;
			while(pow < children + 1){
                log_children++, pow *= 2;
            }
			ans += log_children;
		}
	cout << ans << '\n';
}

/*
int n;
vector<int> adj[100001];
int ans;


void solve(int e, int day, bool seen[], int disease[], int numaffected){
    if(numaffected == n){
        ans = day;
        return;
    }
    seen[e] = true;
    int orig = disease[e];

    //double
    disease[e] = 2*orig;
    solve(e, day+1, seen, disease, numaffected);
    //disease[e] = orig;

    //cow moves
    for(int f : adj[e]){
        if(!seen[f] && disease[e] > 0){
            disease[e] -= 1;
            disease[f] += 1;
            if(disease[f] == 1){
                solve(f, day+1, seen, disease, numaffected+1);
            }
            else{
                solve(f, day+1, seen, disease, numaffected);
            }
            
            //disease[e] += 1;
            //disease[f] -= 1;
        }
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool seen[n];
    int disease[n];
    fill(seen, seen+n, false);
    fill(disease, disease+n, 0);
    disease[1] = 1;

    solve(1, 1, seen, disease, 1);

    cout << ans << endl;

}
*/