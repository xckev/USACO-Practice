/*
ID: xckevin1
LANG: C++
TASK: buylow
*/

#include <bits/stdc++.h>
using namespace std;

struct BigNum {
    int size;
    int digits[100];
    BigNum() {
        size = 1;
        memset(digits, 0, sizeof(digits));
    }
    BigNum(int s) {
        size = 1;
        memset(digits, 0, sizeof(digits));
        digits[0] = s;
    }
};

void add(BigNum& a, BigNum b) {
    BigNum sum;
    int carry = 0;
    int len = max(a.size, b.size);
    for (int i = 0; i < len; i++) {
        int tmp = a.digits[i] + b.digits[i] + carry;
        if (tmp >= 10) {
            sum.digits[i] = tmp-10;
            carry = 1;
        } else {
            carry = 0;
            sum.digits[i] = tmp;
        }
    }
    sum.size = len;
    if (carry != 0) {
        sum.digits[len] = 1;
        sum.size++;
    }
    a = sum;
}


int n;
int stocks[5005];
BigNum ans;
BigNum cnt[5005];
int best = 0;
int dp[5005]; //stores longest increasing subsequence till that pos
unordered_map<int, bool> visited; //what prices have been seen (for distinct prices)

int main(){
    ifstream fin("buylow.in");
    ofstream fout("buylow.out");
    fin >> n;
    for(int i = 0; i < n; i++){
        fin >> stocks[i];
    }

    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(stocks[j] > stocks[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        best = max(best, dp[i]);
    }

    for(int i = 0; i < n; i++){
        if(dp[i] == 1){
            cnt[i] = BigNum(1);
        }
        else{
            visited.clear();
            for(int j = i-1; j >= 0; j--){
                if(visited.count(stocks[j])){
                    continue;
                }
                if(stocks[j] > stocks[i] && dp[j] == dp[i] - 1){
                    visited[stocks[j]] = true;
                    add(cnt[i], cnt[j]);
                }
            }
        }
    }

    visited.clear();
    int prev = -1;
    for(int i = n-1; i >= 0; i--){
        if(visited.count(stocks[i])){
            continue;
        }
        if(dp[i] == best){
            visited[stocks[i]] = true;
            add(ans, cnt[i]);
        }
    }

    fout << best << " ";
    for(int i = ans.size - 1; i >= 0; i--){
        fout << ans.digits[i];
    }
    fout << endl;
}