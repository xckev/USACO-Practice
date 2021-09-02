#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <set>
#include <fstream>
using namespace std;

int n, x;
int p[200000];
bool used[200000];

int main(){
    cin >> n >> x;

    for(int i = 0; i < n; i++){
        cin >> p[i];
    }

    sort(p, p+n);


    int counter = 0;
    int i = 0;
    int j = n-1;
    while(i < j){
        int l = p[i];
        int r = p[j];

        if(l + r <= x){
            used[i] = used[j] = true;
            i++;
            j--;
            counter++;
        }
        else{
            used[j] = true;
            j--;
            counter++;
        }
    }

    for(int ind = 0; ind < n; ind++){
        if(used[ind] == false){
            counter++;
        }
    }

    cout << counter << endl;
}