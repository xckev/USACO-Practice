/*
ID: xckevin1
LANG: C++
TASK: job
*/

#include <bits/stdc++.h>
using namespace std;

int n, m1, m2;
int origA[30]; //this will never change
int origB[30]; //this will never change
int a[30];
int b[30];
int times1[1000]; //for a machines
int times2[1000]; //for b machines

int cmp(int x, int y){
    return x > y;
}

int main(){
    ofstream fout ("job.out");
    ifstream fin ("job.in");
    fin >> n >> m1 >> m2;

    for(int i = 0; i < m1; i++){
        fin >> a[i];
        origA[i] = a[i];
    }

    for(int i = 0; i < m2; i++){
        fin >> b[i];
        origB[i] = b[i];
    }
    memset(times1, 0, sizeof(times1));
    memset(times2, 0, sizeof(times2));
    //A machines
    int ans = 0;
    for(int i = 0; i < n; i++){
        int minmachine = min_element(a, a+m1) - a; //machine that can finish work earliest

        times2[i] = times1[i] + a[minmachine]; //updating times for b machines 
        ans = max(ans, times1[i] + a[minmachine]); 
        a[minmachine] += origA[minmachine]; //updating time a machine can finish work after it has been used
    }
    fout << ans << " ";

    sort(times2, times2+n, cmp); //sort by reverse orders of times (WE WANT TO MATCH MOST EFFICIENT B TIMES WITH LEAST EFFICIENT A TIMES TO BALANCE OUT THE TIMES FOR A LEAST OVERALL ENDING TIME)
    ans = 0;
    for(int i = 0; i < n; i++){
        int minmachine = min_element(b, b+m2) - b;
        
        ans = max(ans, times2[i] + b[minmachine]);
        b[minmachine] += origB[minmachine];
    }
    fout << ans << endl;
}