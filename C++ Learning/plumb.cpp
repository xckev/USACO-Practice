#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int r, c;

bool adjcheck(int *a[], int i, int j){
    int val = a[i][j];
    if(i != 0){
        if(a[i-1][j] == val){
            return true;
        }
        if(j != 0){
            if(a[i-1][j-1] == val){
                return true;
            }
        }
        if(j != c-1){
            if(a[i-1][j+1] == val){
                return true;
            }
        }
    }
    if(i != r-1){
        if(a[i+1][j] == val){
            return true;
        }
        if(j != 0){
            if(a[i+1][j-1] == val){
                return true;
            }
        }
        if(j != c-1){
            if(a[i+1][j+1] == val){
                return true;
            }
        }
    }
    if(j != 0){
        if(a[i][j-1] == val){
            return true;
        }
    }
    if(j != c-1){
        if(a[i][j+1] == val){
            return true;
        }
    }
    return false;
}


int main(){
    cin >> r >> c;
    int *pond[r];
    for (int i = 0; i < r; i++){ 
        pond[i] = new int[c];
        for(int j = 0; j < c; j++){
            cin >> pond[i][j];
        }
    }

    int result = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(pond[i][j] != 0 && pond[i][j] > result){
                if(adjcheck(pond, i, j)){
                    result = pond[i][j];
                }
            }
        }
    }

    cout << result << endl;
}


