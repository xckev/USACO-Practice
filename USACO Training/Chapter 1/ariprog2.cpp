/*
ID: xckevin1
LANG: C++
TASK: ariprog
*/

//category: complete search
//note: I was able to either under runtime or under memory limit, but not both

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <set>
#include <fstream>
using namespace std;

int n, m;
//bool bisquare[125000];
set<int> good;


int main(){
    //ofstream fout ("ariprog.out");
    //ifstream fin ("ariprog.in");
    cin >> n >> m;

    for(int i = 0; i <= m; i++){
        for(int j = i; j <= m; j++){
            int ind = pow(i, 2) + pow(j, 2);
            //bisquare[ind] = true;
            good.insert(ind);
        }
    }

    vector<int> bisquares(good.begin(), good.end());
    //cout <<  "size: " << good.size() << endl;
    //sort(good.begin(), good.end());
    //int maxm = (m*m)/3;

    bool any = false;
    for(int d = 1; d < 2000; d++){
        for(int i = 0; i < bisquares.size(); i++){
            int elem = bisquares[i];
            int start = bisquares[i];
            int elemnum = 1;
            while(elemnum <= n){
                elem += d;

                bool found = false;
                int next = 1;
                while(bisquares[i+next] <= elem){
                    if(bisquares[next+i] == elem){
                        found = true;
                        break;
                    }
                    else{
                        next++;
                    }
                }

                if(found){
                    elemnum++;
                    if(elemnum == n){
                        any = true;
                        cout << start << " " << d << endl;
                    }
                }
                else{
                    break;
                }
                
                
            }
        }
    }
    if(!any){
        cout << "NONE" << endl;
    }

}