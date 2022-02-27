#include <bits/stdc++.h>
using namespace std;

int N;
int preference[500+1][500];
vector<int> ownedby;

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        ownedby.push_back(i);
        for(int j = 0; j < N; j++){
            int g;
            cin >> g;
            preference[i][j] = g;
        }
    }

    int bestimprovement = 0;
    vector<int> ans;

    do{
        int improvement = 0;
        bool good = true;
        for(int i = 1; i <= N; i++){
            if(ownedby[i-1] == i){
                continue;
            }

            int origInd;
            for(int j = 0; j < N; j++){
                if(preference[i][j] == i){
                    origInd = j;
                    break;
                }
            }
            
            int currInd;
            for(int j = 0; j < N; j++){
                if(preference[i][j] == ownedby[i-1]){
                    currInd = j;
                    break;
                }
            }

            if(currInd > origInd){
                good = false;
                break;
            }
        }
        if(good){
            if(improvement > bestimprovement){
                bestimprovement = improvement;
                ans.clear();
                for(int i = 1; i <= N; i++){
                    ans.push_back(ownedby[i-1]);
                }
            }
        }

    } while (next_permutation(ownedby.begin(), ownedby.end()));

    for(int e: ans){
        cout << e << endl;
    }
}
