/*
ID: xckevin1
LANG: C++
TASK: camelot
*/

//bfs + otherstuf

#include <bits/stdc++.h>
using namespace std;

struct Piece{
    int row;
    int col;
};

Piece king;
vector<Piece> knights;

int R, C;
int cost[35][35][35][35]; //cost[i][j][x][y] num moves from i, j to x, y

int main(){
    ofstream fout ("camelot.out");
    ifstream fin ("camelot.in");
    fin >> R >> C;
    char c;
    int r;
    fin >> c >> r;
    king.row = r;
    king.col = c -'A' + 1;


    while(fin >> c >> r){
        Piece p;
        p.row = r;
        p.col = c - 'A' + 1;
        knights.push_back(p);
    }

    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    //cout << "hjere" << endl;

    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            for(int x = 1; x <= R; x++){
                for(int y = 1; y <= C; y++){
                    cost[i][j][x][y] = 99999999;
                }
            }
        }
    }

    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            //bfs
            cost[i][j][i][j] = 0;
            queue<Piece> q;
            Piece p;
            p.row = i; p.col = j;
            q.push(p);
            while(!q.empty()){
                Piece f = q.front();
                q.pop();
                for(int k = 0; k < 8; k++){
                    int x = f.row + dx[k];
                    int y = f.col + dy[k];
                    if(x >= 1 && x <= R && y >= 1 && y <= C){
                        if(cost[i][j][f.row][f.col] + 1 < cost[i][j][x][y]){
                            cost[i][j][x][y] = cost[i][j][f.row][f.col] + 1;
                            Piece nu;
                            nu.row = x; nu.col = y;
                            q.push(nu);
                        }
                    }
                }
            }
        }
    }

    int ans = 99999999;
    //finding ans with king
    //i, j destinations
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            int cost1 = 0;
            int kingcost = max(abs(king.row - i), abs(king.col - j));
            for(Piece p : knights){
                cost1 += cost[p.row][p.col][i][j];
                //x, y king pickup points
                for(int x = king.row - 2; x <= king.row + 2; x++){
                    for(int y = king.col - 2; y <= king.col + 2; y++){
                        if(x >= 1 && x <= R && y >= 1 && y <= C){
                            kingcost = min(kingcost, cost[p.row][p.col][x][y] + cost[x][y][i][j] + max(abs(king.row - x), abs(king.col - y)) - cost[p.row][p.col][i][j]);
                            
                        }
                    }
                }
            }
            ans = min(ans, cost1+kingcost);
        }
    }
    fout << ans << endl;
}

