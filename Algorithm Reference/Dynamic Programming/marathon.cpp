#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<pair<int, int>> coords;
long long storage[501][501];

int dist(pair<int, int> p1, pair<int, int> p2){
    return (abs(p1.first - p2.first) + abs(p1.second - p2.second));
}

int main(){
    ofstream fout ("marathon.out");
    ifstream fin ("marathon.in");
    fin >> N >> K;

    for(int i = 0; i < N; i++){
        int x, y;
        fin >> x >> y;
        coords.push_back({x, y});
    }

    for(int i = 0; i < 501; i++){
        for(int j = 0; j < 501; j++){
            storage[i][j] = LLONG_MAX / 2;
        }
    }

    storage[0][0] = 0;
    for(int i = 0; i < K; i++){
        for(int j = 0; j < N; j++){
            for(int l = j+1; l < N && i + (l-j-1) <= K; l++){
                int nextskips = i + (l-j-1);
                int nextcp = l;
                long long orig = storage[nextcp][nextskips];
                long long newval = storage[j][i] + dist(coords[j], coords[l]);
                storage[nextcp][nextskips] = min(orig, newval);
                
            }
        }
    }

    fout << storage[N-1][K] << endl;

}