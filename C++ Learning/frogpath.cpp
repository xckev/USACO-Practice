#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;

int count;
int len;

int solve(int e, string a){
    if(e >= len){
        return 0;
    }
    else if(e == len-1){
        return 1;
    }
    else{
        if(e < len-2 && a[e+1] == '#' && a[e+2] == '#'){
            return 0;
        }
        else if(e == len-2){
            return solve(e+1, a);
        }
        else if(e < len-1 && a[e+1] == '#'){
            return solve(e+2, a);
        }
        else if(e < len-2 && a[e+2] == '#'){
            return solve(e+1, a);
        }
        else{
            return solve(e+1, a) + solve(e+2, a);
        }
    }

}

int main(){
    string path;
    getline(cin, path);

    len = path.size();

    cout << solve(0, path) << endl;
}