#include <iostream>
#include <algorithm>
using namespace std;

int dif = INT32_MAX;

void check(int skills[], int ans[]){
    int sums[4];
    for(int i = 0; i < 4; i++){
        sums[i] = 0;
    }

    for(int i = 0; i < 12; i++){
        int ind = ans[i]-1;
        sums[ind] += skills[i];
    }

    sort(sums, sums+4);
    int newdif = sums[3] - sums[0];
    if(newdif < dif){
        dif = newdif;
    }
}

void solve(int pos, int marked[], int skills[], int ans[]){
    if(pos == 12){
        check(skills, ans);
        return;
    }
    else{
        for(int i = 1; i <= 4; i++){
            if(marked[i-1] < 3){
                ans[pos] = i;
                marked[i-1]++;
                solve(pos+1, marked, skills, ans);
                marked[i-1]--;
            }
        }
    }
}

int main(){
    int skills[12];

    for(int i = 0; i < 12; i++){
        cin >> skills[i];
    }

    int marked[4];
    for(int i = 0; i < 4; i++){
        marked[i] = 0;
    }
    int ans[12];

    solve(0, marked, skills, ans);

    cout << dif << endl;
}