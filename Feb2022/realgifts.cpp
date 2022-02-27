#include <bits/stdc++.h>
using namespace std;

int N;

int preference[500+1][500];
bool seen[501];
int indofself[500+1];
//set<pair<int, int>> preferedmost[500+1];


bool canget(int curr, int start){
    //cout << "on cow " << curr << endl;
    
    if(curr == start){
        //cout << "got back to starting cow" << endl;
        return true;
    }
    if(preference[curr][0] == curr || seen[curr]){
        //cout << "mission failed" << endl;
        return false;
    }
    seen[curr] = true;
    bool allfailed = true;
    for(int i = 0; i < indofself[curr]; i++){

        int g = preference[curr][i];
        bool ok = canget(g, start);
        if(ok){
            allfailed = false;
            break;
        }
        
    }
    if(allfailed){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    cin >> N;

    for(int i = 1; i <= N; i++){
        //ownedby[i] = i;
        for(int j = 0; j < N; j++){
            int g;
            cin >> g;
            preference[i][j] = g;
            if(g == i){
                indofself[i] = j;
            }
            //preferedmost[g].insert({j, i}); //(pos, cow)
        }
    }


    for(int cow = 1; cow <= N; cow++){
        //cout << "starting from cow " << cow << endl;
        for(int i = 0; i < N; i++){
            int g = preference[cow][i];
            if(g == cow){
                //cout << "preference at self" << endl;
                cout << g << endl;
                break;
            }
            else{
                //cout << "testing preference of gift " << g << endl;
                memset(seen, false, sizeof(seen));
                //cout << "everything unmarked" << endl;
                if(canget(g, cow)){
                    //cout << "i could get it!" << endl;
                    cout << g << endl;
                    break;
                }
            }
            
        }
    }
}