#include <bits/stdc++.h>
using namespace std;

int t;

int components[100001];

void floodfill(int e, int id, vector<int> adj[]){
    components[e] = id;

    for(int g : adj[e]){
        if(components[g] == -1){
            floodfill(g, id, adj);
        }
    }
}

int main(){
    //reading input
    cin >> t;

    for(int i = 0; i < t; i++){
        int n, m;
        cin >> n >> m;
        vector<int> adj[n+1];

        for(int j = 0; j < m; j++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            //cout << "here: " << j << endl;
        }

        
        //flood filling components
        fill(components, components+100001, -1);
        int compnum = 1;
        for(int f = 1; f <= n; f++){
            if(components[f] == -1){
                floodfill(f, compnum, adj);
                compnum++;
            }
        }

        //startcomp is component with 1
        int startcomp = components[1];
        /*
        vector<long long> allstart;
        cout << "start" << endl;
        for(int j = 1; j <= n; j++){
            if(components[j] == startcomp){
                allstart.push_back(j);
                cout << j << " ";
            }
        }
        sort(allstart.begin(), allstart.end());
        cout << endl;
        */
        long long diffs1[n+1];
        fill(diffs1, diffs1+n+1, 99999999999999999);
        long long prev = -100000;
        for(int j = 1; j <= n; j++){

            if(components[j] == startcomp){
                prev = i;
            }
            diffs1[i] = min(diffs1[i], (i-prev) * (i-prev));
        }

        //endcomp is component with n
        int endcomp = components[n];
        /*
        cout << "end" << endl;
        vector<long long> allend;
        for(int j = 1; j <= n; j++){
            if(components[j] == endcomp){
                allend.push_back(j);
                cout << j << " ";
            }
        }
        sort(allend.begin(), allend.end());
        cout << endl;
        */
        long long diffs2[n+1];
        fill(diffs2, diffs2+n+1, 99999999999999999);
        prev = 200000;
        for(int j = n; j >= 1; j--){
            
            if(components[j] == endcomp){
                prev = i;
            }
            diffs2[i] = min(diffs2[i], (prev-i) * (prev-i));
        }
        /*
        bool seen[100001];
        fill(seen, seen+100001, false);
        */
        long long best = LONG_LONG_MAX;
        for(int j = 1; j <= n; j++){
            long long num = diffs1[j] + diffs2[j];
            best = min(num, best);
        }

        //going thru all k as a possible middle component
        /*
        for(int k = 1; k <= compnum; k++){
            if(seen[components[k]]){
                continue;
            }

            seen[components[k]] = true;



            //midcomp is middle connecting component
            int midcomp = components[k];
            vector<long long> allmid;
            for(int i = 1; i <= n; i++){
                if(components[i] == midcomp){
                    allmid.push_back(i);
                }
            }
            sort(allmid.begin(), allmid.end());

            //finding least cost between startcomp and midcomp
            long long min1 = 99999999999999999; //?
            for(long long e : allmid){
                min1 = min(min1, diffs1[e]);
            }

            

            //finding least cost between midcomp and endcomp
            long long min2 = 99999999999999999;
            for(long long e : allmid){
                min2 = min(min2, diffs2[e]);
            }
            

            long long res = min1 + min2;
            best = min(res, best);
        }
        */
        cout << best << endl;
    }
}