#include <bits/stdc++.h>
using namespace std;

//jan 2021

int n, q;
vector<char> arr;


void precompute(int ans[]){
    stack<char> colors;
    for(int i = 0; i < n; i++){
        char c = arr[i];
        ans[i+1] = ans[i];
        while(!colors.empty() && colors.top() > c){
            colors.pop();
        }
        if(colors.empty() || colors.top() < c){
            colors.push(c);
            ans[i+1] += 1;
        }
    }
}


int main(){
    cin >> n >> q;
    string s;
    cin >> s;
    
    for(int i = 0; i < s.size(); i++){
        arr.push_back(s[i]);
    }
    
    int before[100001];
    int after[100001];
    precompute(before);
    reverse(arr.begin(), arr.end());
    precompute(after);


    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        int answer = 0;
        answer += before[a-1];
        answer += after[n-b];
        
        cout << answer << endl;
    }
    
    
}