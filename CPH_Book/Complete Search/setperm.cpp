#include <iostream>
using namespace std;

int n, m;

void printNum(int seq[]){
    for(int i = 0; i < n; i++){
        cout << seq[i];
    }
    cout << endl;
}

void permutation(int curr, int seq[], bool used[], int a[]){
    if(curr == n){
        printNum(seq);
        return;
    }
    else{
        for(int i = 0; i < m; i++){
            if(!used[i]){
                seq[curr] = a[i];
                used[i] = true;
                permutation(curr+1, seq, used, a);
                used[i] = false;
            }
        }
    }
}

int main(){
    cin >> m;

    int a[m];
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }

    cin >> n;

    int seq[n];
    bool used[m];

    permutation(0, seq, used, a);

}