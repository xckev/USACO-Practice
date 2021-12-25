/*
ID: xckevin1
LANG: C++
TASK: nuggets
*/

#include <bits/stdc++.h>
using namespace std;

//dynamic knapsack
/*
int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}*/

int n;
int nums[10];
bool dp[64769+1]; //chicken mcnugget thm.

int main(){
    ofstream fout ("nuggets.out");
    ifstream fin ("nuggets.in");
    fin >> n;

    for(int i = 0; i < n; i++){
        fin >> nums[i];
    }

    int g = 0;
    for(int i = 0; i < n; i++){
        g = __gcd(g, nums[i]);
    }
    if(g != 1){
        fout << 0 << endl;
    }
    else{
        dp[0] = true;
        for(int i = 1; i <= 64769; i++){
            for(int j = 0; j < n; j++){
                if(i >= nums[j] && dp[i - nums[j]] == true){
                    dp[i] = true;
                }
            }
        }

        for(int i = 64769; i >= 0; i--){
            if(!dp[i]){
                fout << i << endl;
                return 0;
            }
        }
        fout << 0 << endl;
    }

    

}