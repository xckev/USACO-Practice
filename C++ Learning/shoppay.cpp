#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    queue<int> q;
    vector<int> a[n];
    string dum;
    getline(cin, dum);

    string s;
    getline(cin, s);
    while(!s.empty()){
        string comm = s.substr(0, 1);
        string temp = s.substr(2, 1);
        int i = stoi(temp);

        if(comm == "C"){
            q.push(i);
        }
        else{
            a[i-1].push_back(q.front());
            q.pop();
        }

        getline(cin, s);
    }

    for(int i = 0; i < n; i++){
        cout << i+1 << " ";
        for(int j = 0 ; j < a[i].size(); j++){
            cout << j << " ";
        }
        cout << endl;
    }
}