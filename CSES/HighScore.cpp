#include <iostream>
#include <algorithm>
#include <tuple>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n, m;
vector<tuple<int, int, int>> edges;
long long dist[2502];
const long long neginf = -99999999999999999;

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b, x;
        cin >> a >> b >> x;

        edges.push_back({a, b, x});
    }

    for(int i = 1; i <= n; i++){
        dist[i] = neginf;
    }
    dist[1] = 0;

    for(int i = 1; i <= n-1; i++){
        for(auto e : edges){
            int a, b, w;
            tie(a, b, w) = e;
            dist[b] = max(dist[b], dist[a]+w);
        }
    }
    
    
    bool changeonlast = false;
    long long before = dist[n];
    for(int i = 1; i <= n-1; i++){
        for(auto e : edges){
            int a, b, w;
            tie(a, b, w) = e;
            //dist[b] = max(dist[b], dist[a]+w);
            if(dist[a]+w > dist[b]){
                changeonlast = true;
                break;
            }
        }
    }
    //bool changeonlast = !(before == dist[n]);


    if(changeonlast){
        cout << -1 << endl;
    }
    else{
        cout << dist[n] << endl;
    }
}