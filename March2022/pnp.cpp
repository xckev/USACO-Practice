#include <bits/stdc++.h>
using namespace std;

int N, K;
int ans = 0;

int dfs(int u, int s, int prevchange, int time){
    int c;
    cout << "U: " << u << " S: " << s << endl;
    cin >> c;
    if(u == K*s){
        cout<< "equal" << endl;
        return time;
    }
    else{
        int expectedU = K*s;
        if(expectedU > u){
            cout << "expectedU greater than U" << endl;
            //case 1: decrease S
            int newS = s-1;
            int res1;
            if(prevchange == 3){
                res1 == 99999999;
            }
            else{
                res1 = dfs(u, newS, 1, time+1);
            }

            //case 2: increase U
            int newU = u+1;
            int res2;
            if(prevchange == 4){
                res1 == 99999999;
            }
            else{
                res1 = dfs(newU, s, 2, time+1);;
            }

            return min(res1, res2);
        }
        else{
            cout << "expectedU less than U" << endl;
            //case 1: increase S
            int newS = s+1;
            int res1;
            if(prevchange == 1){
                res1 == 99999999;
            }
            else{
                res1 = dfs(u, newS, 3, time+1);
            }

            //case 2: decrease U
            int newU = u-1;
            int res2;
            if(prevchange == 2){
                res1 == 99999999;
            }
            else{
                res1 = dfs(newU, s, 4, time+1);;
            }

            return min(res1, res2);
        }
    }
}

int main(){
    cin >> N >> K;

    for(int i = 0; i < N; i++){
        int U, S;
        cin >> U >> S;

        ans += dfs(U, S, 0, 0);
    }
    cout << ans <<endl;
}