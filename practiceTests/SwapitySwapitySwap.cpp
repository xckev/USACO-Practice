#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int l[101], r[101];
int p[100001];
bool seen[100001];


int main(){
    ofstream fout ("swap.out");
    ifstream fin ("swap.in");
    fin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        p[i] = i;
    }
    //finding places after first round
    for(int i = 0; i < m; i++){
        int l,r;
        fin >> l >> r;
        for(int j = 0; j < (r - l + 1)/2; j++){
            int temp = p[l + j];
            p[l + j] = p[r - j];
            p[r - j] = temp;
        }
    }

    //fill(seen, seen+100001, false);
    
    for(int i = 1; i <= n; i++){
        if(!seen[i]){
            seen[i] = true;
            int start = p[i];
            vector<int> cycle;
            cycle.push_back(i);
            while(start != i){
                seen[start] = true;
                cycle.push_back(start);
                start = p[start];
            }
            int mod = k % cycle.size();
            for(int j = 0; j < cycle.size(); j++){
                p[cycle[j]] = cycle[(j+mod) % cycle.size()];
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        fout << p[i] << endl;
    }

}