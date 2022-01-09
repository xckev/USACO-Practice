#include <bits/stdc++.h>
using namespace std;

//feb 2016

int n;
long long cows[1000];
bool full[1000];

int main(){
    ofstream fout ("cbarn.out");
    ifstream fin ("cbarn.in");
    fin >> n;

    for(int i = 0; i < n; i++){
        fin >> cows[i];
    }

    long long ans = 999999999999999;
    for(int start = 0; start < n; start++){
        queue<int> q;
        long long total = 0;
        int good = true;
        memset(full, false, sizeof(full));
        //cout << "---------- starting at " << start << "----------" << endl;
        for(int curr = start; curr < start+n; curr++){
            int room = curr%n;
            //cout << "on room " << room << " , curr = " << curr << endl;
            if(cows[room] > 0){
                long long newcows = cows[room];
                for(int j = 0; j < newcows; j++){
                    q.push(curr);
                }
            }
            //cout << "picked up " << cows[room] << " new cows from room" << endl;
            if(q.empty()){
                //cout << "nothing in queue... ended" << endl;
                good = false;
                break;
            }
            if(!full[room]){
                long long d = curr - q.front();
                total += d*d;
                //cout << "dropped off a cow at room " << room << ", added " << d*d << " to total" << endl;
                q.pop();
                full[room] = true;
            }
            //cout << "total is now " << total << endl;
            
        }
        if(good){
            ans = min(ans, total);
        }
    }

    fout << ans << endl;
}