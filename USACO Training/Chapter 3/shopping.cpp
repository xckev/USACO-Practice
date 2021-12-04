/*
ID: xckevin1
LANG: C++
TASK: shopping
*/

//dynamic prog (knapsack)

#include <bits/stdc++.h>
using namespace std;

int s, b;
int id[1000];
int currid = 0;
int dp[6][6][6][6][6];

struct Deal{
    int price;
    int num[5];
    Deal(){
        price = 0;
        num[0] = num[1] = num[2] = num[3] = num[4] = 0;
    }
};

vector<Deal> deals;
int numprod[5];

int getID(int x){
    if(id[x] == -1){
        id[x] = currid;
        currid++;
    }
    return id[x];
}

int main(){
    ofstream fout ("shopping.out");
    ifstream fin ("shopping.in");
    fin >> s;
    fill(id, id+1000, -1);

    for(int i = 0; i < s; i++){
        int n;
        fin >> n;
        Deal d;
        for(int j = 0; j < n; j++){
            int c, k;
            fin >> c >> k;
            d.num[getID(c)] = k;
        }
        int p;
        fin >> p;
        d.price = p;
        deals.push_back(d);
    }

    fin >> b;
    for(int i = 0; i < b; i++){
        int c, k, p;
        fin >> c >> k >> p;
        numprod[getID(c)] = k;

        Deal d;
        d.price = p;
        d.num[getID(c)] = 1;
        deals.push_back(d);
        //cout << "ID of " << c << ": " << getID(c) << endl;
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0][0][0] = 0;

    int a[5];
    int c[5];
    for(a[0] = 0; a[0] <= numprod[0]; a[0]++){
        for(a[1] = 0; a[1] <= numprod[1]; a[1]++){
            for(a[2] = 0; a[2] <= numprod[2]; a[2]++){
                for(a[3] = 0; a[3] <= numprod[3]; a[3]++){
                    for(a[4] = 0; a[4] <= numprod[4]; a[4]++){
                        //cout << "dp[" << a[0] << a[1] << a[2] << a[3] << a[4] << "] = " << dp[a[0]][a[1]][a[2]][a[3]][a[4]] << endl;
                        for(Deal d : deals){
                            bool good = true;
                            for(int i = 0; i < 5; i++){
                                c[i] = a[i] + d.num[i];
                                if(c[i] > numprod[i]){
                                    good = false;
                                }
                            }
                            if(good){
                                dp[c[0]][c[1]][c[2]][c[3]][c[4]] = min(dp[c[0]][c[1]][c[2]][c[3]][c[4]], dp[a[0]][a[1]][a[2]][a[3]][a[4]] + d.price);
                            }
                        }
                    }
                }
            }
        }
    }

    fout << dp[numprod[0]][numprod[1]][numprod[2]][numprod[3]][numprod[4]] << endl;

}