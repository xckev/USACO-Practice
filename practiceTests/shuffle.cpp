#include <bits/stdc++.h>
using namespace std;

//dec 2017

int n;
int a[100001];
int parent[100001]; //how many parents a location has

int main(){
    ofstream fout ("shuffle.out");
    ifstream fin ("shuffle.in");
    fin >> n;
    memset(parent, 0, sizeof(parent));

    for(int i = 1; i <= n; i++){
        fin >> a[i];
        parent[a[i]]++; 
    }

    int ans = n;
    queue<int> q; //positions that are known to never contain cows at some point
    for(int i = 1; i <= n; i++){
        if(parent[i] == 0){
            //cout << i << " has " << parent[i] << " parents" << endl;
            ans--;
            q.push(i);
        }
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        int childofcurr = a[curr];
        parent[childofcurr] -= 1;
        if(parent[childofcurr] == 0){ //childofcurr has no parents that have cows
            q.push(childofcurr);
            ans--;
        }
    }

    fout << ans << endl;
}