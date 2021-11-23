#include <bits/stdc++.h>
using namespace std;

//2d prefix

int N, Q;
int pfx[1001][1001];

int main(){
    cin >> N >> Q;

    for(int i = 1; i <= N; i++){
        string line;
        cin >> line;
        for(int j = 1; j <= N; j++){
            char c = line[j-1];
            int toadd = 0;
            if(c == '*'){
                toadd = 1;
            }
            
            pfx[i][j] = pfx[i-1][j] + pfx[i][j-1] - pfx[i-1][j-1] + toadd;
        }
    }

    for(int i = 0; i < Q; i++){
        int a, b, A, B;
        cin >> a >> b >> A >> B;

        int ans = pfx[A][B] - pfx[a-1][B] - pfx[A][b-1] + pfx[a-1][b-1];
        cout << ans << endl;
    }


}