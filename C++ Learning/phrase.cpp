#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    cin.ignore();
    //cout << m << " " << n << endl;

    string s[m];
    for(int i = 0; i < m; i++){
        getline(cin, s[i]);
        //cout << s[i] << endl;
    }

    string q[n];
    for(int i = 0; i < n; i++){
        getline(cin, q[i]);
        //cout << q[i] << endl;
    }

    int total = 0;
    for(int i = 0; i < n; i++){
        string pre = q[i];
        for(int j = 0; j < m; j++){
            if(pre.size() <= s[j].size()){
                if(s[j].find(pre) == 0){
                    total++;
                    break;
                }
            }
        }
    }
    cout << total << endl;

}