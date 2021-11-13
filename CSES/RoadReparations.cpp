#include <bits/stdc++.h>
using namespace std;

//kruskal

int n, m;
vector<tuple<long long, int, int>> v; //KRUSKAL - sorted edge list
int parent[100001]; //parent and size arrays for union-find
int componentsize[100001];

int findcomponent(int x){
    while(parent[x] != x){
        x = parent[x];
    }
    return x;
}

bool same(int a, int b){
    return (findcomponent(a) == findcomponent(b));
}

int unite(int a, int b){
    a = findcomponent(a);
    b = findcomponent(b);
    if(componentsize[a] < componentsize[b]){
        swap(a, b);
    }
    componentsize[a] += componentsize[b];
    parent[b] = a;
    return a;
}


int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        v.push_back({c, a, b});
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < 100001; i++){
        parent[i] = i;
        componentsize[i] = 1;
    }

    long long total = 0;
    int lastroot;
    for(int i = 0; i < m; i++){
        int a, b;
        long long c;
        tuple<long long, int, int> t = v[i];
        tie(c, a, b) = t;

        if(!same(a, b)){
            total += c;
            lastroot = unite(a, b);
        }
    }

    if(componentsize[lastroot] == n){
        cout << total << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }

}