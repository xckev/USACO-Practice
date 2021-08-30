/*
ID: xckevin1
LANG: C++
TASK: combo
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;


int n;

bool within2(int n1, int n2, int nums[]){
    int ind = n+n1-1;
    for(int i = ind-2; i <= ind+2; i++){
        if(nums[i] == n2){
            return true;
        }
    }
    return false;
}

bool good(int test[], int arr1[], int arr2[], int nums[]){
    bool good1 = true;
    bool good2 = true;
    for(int i = 0; i < 3; i++){
        int testnum = test[i];
        if(!within2(testnum, arr1[i], nums)){
            good1 = false;
        }

        if(!within2(testnum, arr2[i], nums)){
            good2 = false;
        }
    }

    return (good1 || good2);    
}



int main(){
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");

    fin >> n;

    int nums[3*n];

    for(int i = 1; i <= n; i++){
        nums[i-1] = i;
    }
    for(int i = 1; i <= n; i++){
        nums[n+i-1] = i;
    }
    for(int i = 1; i <= n; i++){
        nums[n+n+i-1] = i;
    }

    int arr1[3];
    int arr2[3];

    fin >> arr1[0] >> arr1[1] >> arr1[2];
    fin >> arr2[0] >> arr2[1] >> arr2[2];

    int counter = 0;
    for(int i1 = 1; i1 <= n; i1++){
        for(int i2 = 1; i2 <= n; i2++){
            for(int i3 = 1; i3 <= n; i3++){
                int test[3];
                test[0] = i1; test[1] = i2; test[2] = i3;
                if(good(test, arr1, arr2, nums)){
                    counter++;
                }
            }
        }
    }

    fout << counter << endl;
}