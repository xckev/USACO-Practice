#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> moves;
map<pair<int, int>, tuple<int, int, int>> ans[501];
long long xg, yg;

int main(){
    cin >> N;
    cin >> xg >> yg;

    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        moves.push_back({x, y});
    }

    for(auto& p : moves){
        if(p.first == xg && p.second == yg){
            ans[1][p] = {p.first, p.second, 1};
        }
        else{
            ans[1][p] = {p.first, p.second, 0};
        }
    }

    for(int move = 2; move <= N; move++){
        for(auto& p : moves){
            int xdiff = xg - p.first;
            int ydiff = yg - p.second;

            int prevplacex = get<0>(ans[move][p]);
            int prevplacey = get<1>(ans[move][p]);
            if(prevplacex == xdiff && prevplacey == ydiff){
                get<2>(ans[move][p]) += ans[move-1][{xdiff, ydiff}];
            }
            
        }
    }

    for(int i = 1; i <= N; i++){
        int total = 0;
        for(auto& p : moves){
            total += ans[i][p];
        }
        cout << total << endl;
    }

}
