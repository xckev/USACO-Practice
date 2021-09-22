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
#include <set>
#include <vector>
#include <fstream>
using namespace std;

int n, m;
bool bisquare[125000];
set<int> good;

int main(){
    //ofstream fout ("ariprog.out");
    //ifstream fin ("ariprog.in");
    cin >> n >> m;

    for(int i = 0; i <= m; i++){
        for(int j = i; j <= m; j++){
            int ind = pow(i, 2) + pow(j, 2);
            bisquare[ind] = true;
            good.insert(ind);
        }
    }
    //cout <<  "size: " << good.size() << endl;
    //sort(good.begin(), good.end());
    //int maxm = (m*m)/3;

    bool any = false;
    for(int d = 1; d < 2000; d++){
        for(int elem : good){
            //int elem = good[start];
            int start = elem;
            int elemnum = 1;
            while(elemnum <= n){
                elem += d;
                if(!bisquare[elem]){
                    break;
                }
                else{
                    elemnum++;
                    if(elemnum == n){
                        any = true;
                        cout << start << " " << d << endl;
                    }
                }
            }
        }
    }
    if(!any){
        cout << "NONE" << endl;
    }

}