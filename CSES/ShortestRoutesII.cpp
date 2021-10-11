#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n, m, q;
long long dist[502][502];

int main(){
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                dist[i][j] = 0;
            }
            else{
                dist[i][j] = 999999999999999999;
                dist[j][i] = 999999999999999999;
            }
        }
    }
    
    for(int i = 0; i < m; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        dist[a][b] = min(c, dist[a][b]);
        dist[b][a] = dist[a][b];
        //cout << a << ", " << b << ": " << c << endl;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                //cout << i << ", " << j << " shortned from : " << dist[i][j] << " to ";
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                //cout << " " << dist[i][j] << endl;
                dist[j][i] = dist[i][j];
            }
        }
    }

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        long long ans = dist[a][b];
        if(ans == 999999999999999999){
            cout << -1 << endl;
        }
        else{
            cout << ans << endl;
        }
    }
}