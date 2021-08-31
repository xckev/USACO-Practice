/*
ID: xckevin1
LANG: C++
TASK: milk3
*/

//category: DFS

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <set>
#include <fstream>
using namespace std;

int capacity[3];
bool seen[21][21][21];
set<int> answers;

vector<int> pour(int b1, int b2, vector<int> arr){
    if(b1 == b2){
        return arr;
    }

    vector<int> n;
    
    n.push_back(arr[0]); 
    n.push_back(arr[1]); 
    n.push_back(arr[2]); 
    int toPour = n[b1];
    
    if(n[b2] + toPour > capacity[b2]){
        int temp = n[b2];
        n[b2] = capacity[b2];
        n[b1] = toPour - (capacity[b2] - temp);
    }
    else{
        n[b2] += toPour;
        n[b1] -= toPour;
    }
    return n;
}

void solve(vector<int> arr){
    if(seen[arr[0]][arr[1]][arr[2]]){
        return;
    }
    else{
        seen[arr[0]][arr[1]][arr[2]] = true;
        if(arr[0] == 0){
            
            answers.insert(arr[2]);
        }

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                solve(pour(i, j, arr));
            }
        }
    }
    
}

int main(){
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");

    fin >> capacity[0] >> capacity[1] >> capacity[2];
    vector<int> arr;
    arr.push_back(0); arr.push_back(0); arr.push_back(capacity[2]);
    solve(arr);

    //sort(answers.begin(), answers.end());

    for(int x : answers){
        if(x == capacity[2]){
            fout << x << endl;
        }
        else{
            fout << x << " ";
        }
    }
    

}