#include <bits/stdc++.h>
using namespace std;

string s;
int Q;
int prefixC[200001];
int prefixO[200001];
int prefixW[200001];

int main(){
    cin >> s;
    cin >> Q;

    memset(prefixC, 0, sizeof(prefixC));
    memset(prefixO, 0, sizeof(prefixO));
    memset(prefixW, 0, sizeof(prefixW));

    for(int i = 1; i <= s.size(); i++){
        prefixC[i] = prefixC[i-1];
        prefixO[i] = prefixO[i-1];
        prefixW[i] = prefixW[i-1];
        char c = s[i-1];
        if(c == 'C'){
            prefixC[i] += 1;
        }
        else if(c == 'O'){
            prefixO[i] += 1;
        }
        else if(c == 'W'){
            prefixW[i] += 1;
        }
    }
    
    string ans = "";
    for(int i = 0; i < Q; i++){
        int l, r;
        cin >> l >> r;

        //cout << "from " << l << " to " << r << endl
        int numc = prefixC[r] - prefixC[l-1];
        //cout << "num c: " << numc << endl;
        int numo = prefixO[r] - prefixO[l-1];
        ///cout << "num o: " << numo << endl;
        int numw = prefixW[r] - prefixW[l-1];
        //cout << "num w: " << numw << endl;

        if(numc % 2 == 1 && numo % 2 == 0 && numw % 2 == 0){
            //cout << "yes" << endl;
            ans += "Y";
        }
        else if(numc % 2 == 0 && numo % 2 == 1 && numw % 2 == 1){
            //cout << "yes" << endl;
            ans += "Y";
        }
        else{
            //cout << "no" << endl;
            ans += "N";
        }
        //cout << "----------" << endl;
    }

    cout << ans << endl;
}