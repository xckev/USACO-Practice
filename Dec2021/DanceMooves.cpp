#include <bits/stdc++.h>
using namespace std;

//jan 2021

int n, k;
int p[100001];
vector<int> been[100001]; //stores positions of where cow i has been
int ans[100001];
bool seen[100001];

int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        p[i] = i;
        been[i].push_back(i);
    }

    for(int i = 1; i <= k; i++){
        int a, b;
        cin >> a >> b;
        int cowata = p[a];
        int cowatb = p[b];
        p[a] = cowatb;
        p[b] = cowata;
        been[p[a]].push_back(a);
        been[p[b]].push_back(b);
    }

    fill(seen, seen+100001, false);
    for(int i = 1; i <= n; i++){
        if(!seen[i]){
            vector<int> cycle;
            int j = i;
            while(!seen[j]){
                cycle.push_back(j);
                int temp = j;
                j = p[j];
                seen[temp] = true;
            }

            set<int> s;
            for(int e : cycle){
                for(int f : been[e]){
                    s.insert(f);
                }
            }
            for(int e : cycle){
                ans[e] = s.size();
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] << endl;
    }


}