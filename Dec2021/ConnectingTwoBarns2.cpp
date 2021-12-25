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

int mindiff(vector<long long> arr1, vector<long long> arr2){
    if(arr1.size() < arr2.size()){
        long long ans = 999999999999999;
        for(long long targ : arr1){
            long long hi = arr2.size()-1;
            long long lo = 0;
            

            while(lo <= hi){
                long long mid = (lo + hi + 1)/2;
                long long diff = abs(arr2[mid] - targ);
                ans = min(ans, diff);
                if(arr2[mid] < targ){
                    lo = mid+1;
                }
                else{
                    hi = mid-1;
                }
            }
        }
        return ans;
    }
    else{
        long long ans = 999999999999999;
        for(long long targ : arr2){
            long long hi = arr1.size()-1;
            long long lo = 0;

            while(lo <= hi){
                long long mid = (lo + hi + 1)/2;
                long long diff = abs(arr1[mid] - targ);
                ans = min(ans, diff);
                if(arr1[mid] < targ){
                    lo = mid+1;
                }
                else{
                    hi = mid-1;
                }
            }
        }
        return ans;
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
        vector<long long> allstart;
        for(int i = 1; i <= n; i++){
            if(components[i] == startcomp){
                allstart.push_back(i);
            }
        }
        sort(allstart.begin(), allstart.end());

        //endcomp is component with n
        int endcomp = components[n];
        vector<long long> allend;
        for(int i = 1; i <= n; i++){
            if(components[i] == endcomp){
                allend.push_back(i);
            }
        }
        sort(allend.begin(), allend.end());

        bool seen[100001];
        fill(seen, seen+100001, false);

        long long best = LONG_LONG_MAX;
        //going thru all k as a possible middle component
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
            min1 = mindiff(allstart, allmid);

            /*
            auto p = allstart.begin();
            auto q = allmid.begin();
            while(p != allstart.end() && q != allmid.end()){
                long long cost = ((*p) - (*q)) * ((*p) - (*q));
                min1 = min(cost, min1);
                if(*p < *q){
                    p++;
                }
                else{
                    q++;
                }
            }
            */

            //finding least cost between midcomp and endcomp
            long long min2 = 99999999999999999;
            min2 = mindiff(allmid, allend);
            /*
            p = allmid.begin();
            q = allend.begin();
            while(p != allmid.end() && q != allend.end()){
                long long cost = ((*p) - (*q)) * ((*p) - (*q));
                min2 = min(cost, min2);
                if(*p < *q){
                    p++;
                }
                else{
                    q++;
                }
            }
            */

            long long res = (min1*min1) + (min2*min2);
            best = min(res, best);
        }
        cout << best << endl;
    }
}