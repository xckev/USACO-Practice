#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int, int>> aID;
vector<pair<int, int>> bID;
vector<pair<int, int>> cID;

int ans = 0;

int main(){
    cin >> N >> M;
    char grid[N+1][M+1];
    for(int i = 0; i <= M; i++){
        for(int j = 0; j <= N; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                aID.push_back({i, j});
            }
            else if(grid[i][j] == 'B'){
                bID.push_back({i, j});
            }
            else if(grid[i][j] == 'C'){
                cID.push_back({i, j});
            }
        }
    }

    for(auto p1 : aID){
        for(auto p2 : bID){
            int row1 = p1.first;
            int col1 = p1.second;
            int row2 = p2.first;
            int col2 = p2.second;
            
            double rise = row2 - row1;
            int run = col2 - col1;

            bool good = true;
            for(auto p3 : cID){
                int row3 = p3.first;
                int col3 = p3.second;

                double rise2 = row3 - row1;
                int run2 = col3 - col1;

                if((rise/run) == (rise2/run2)){
                    good = false;
                    break;
                }
            }

            if(good){
                ans++;
            }

        }   
    }

    cout << ans;


}