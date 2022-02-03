#include <bits/stdc++.h>
using namespace std;

int n, m;
int wanted[100001];
bool taken[100001];
set<int> remaining;
pair<int, int> choices[100001];
vector<int> cowsleft;

int main(){
    cin >> n >> m;
    memset(wanted, 0, sizeof(wanted));
    memset(taken, false, sizeof(taken));

    for(int i = 1; i <= n; i++){
        int f, s;
        cin >> f >> s;
        choices[i] = {f, s};
        cowsleft.push_back(i);
        wanted[f]++;
        wanted[s]++;
    }

    for(int i = 1; i <= m; i++){
        remaining.insert(i);
    }
    vector<int> ans;
    while(true){
        int chosen = -1;
        int chosenind = -1;
        for(int i = 0; i < cowsleft.size(); i++){
            int f = choices[cowsleft[i]].first;
            int s = choices[cowsleft[i]].second;

            if((taken[f] && !taken[s]) || (!taken[f] && taken[s])){
                chosen = cowsleft[i];
                chosenind = i;
                //cout << "chose cow " << i+1 << " because one of its cereals is taken" << endl;
                break;
            }
        }
        if(chosen == -1){
            for(int i = 0; i < cowsleft.size(); i++){
                int f = choices[cowsleft[i]].first;
                int s = choices[cowsleft[i]].second;

                if(wanted[s] > 1){
                    chosen = cowsleft[i];
                    chosenind = i;
                    //cout << "chose cow " << i+1 << " because its second choice is wanted" << endl;
                    break;
                }
            }
        }
        if(chosen == -1){
            for(int i = 0; i < cowsleft.size(); i++){
                int f = choices[cowsleft[i]].first;
                int s = choices[cowsleft[i]].second;

                if(wanted[f] > 1){
                    chosen = cowsleft[i];
                    chosenind = i;
                    //cout << "chose cow " << i+1 << " because its second choice is wanted" << endl;
                    break;
                }
            }
        }
        if(chosen == -1){
            for(int i = 0; i < cowsleft.size(); i++){
                int f = choices[cowsleft[i]].first;
                int s = choices[cowsleft[i]].second;

                if(!taken[f] || !taken[s]){
                    chosen = cowsleft[i];
                    chosenind = i;
                    //cout << "chose cow " << i+1 << " because it can still take" << endl;
                    break;
                }
            }
        }
        if(chosen == -1){
            break;
        }

        if(!taken[choices[chosen].first]){
            remaining.erase(choices[chosen].first);
            taken[choices[chosen].first] = true;
            //cout << "removed cow's first choice: " << choices[chosen].first << endl;
        }
        else if(!taken[choices[chosen].second]){
            remaining.erase(choices[chosen].second);
            taken[choices[chosen].second] = true;
            //cout << "removed cow's second choice: " << choices[chosen].first << endl;
        }
        ans.push_back(chosen);
        cowsleft.erase(cowsleft.begin()+chosenind);
        //cout << "cows left: " << endl;
        //for(int c : cowsleft){
        //    cout << c << " ";
        //}
        //cout << endl;
        wanted[choices[chosen].first]--;
        wanted[choices[chosen].second]--;
        
        
    }
    //cout << "-------" << endl;
    cout << cowsleft.size() << endl;
    for(int c : ans){
        cout << c << endl;
    }
    for(int c : cowsleft){
        cout << c << endl;
    }
}