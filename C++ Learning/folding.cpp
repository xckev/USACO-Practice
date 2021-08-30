#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int n, l;

bool check_palindrome(int start, int end, int diffs[]){
    
    int i;
    for (i=0; start+i<=end-i; i++)
        if (diffs[start+i] != diffs[end-i]) return false;
    return true;

}

int main(){

    
    cin >> n >> l;
    vector<int> knots;
    for(int i = 0; i < n; i++){
        int elem;
        cin >> elem;
        knots.push_back(elem);
    }

    sort(knots.begin(), knots.end());

    int total = 0;

    int diffs[n-1];
    for(int i = 0; i < n-1; i++){
        diffs[i] = knots[i+1] - knots[i];
    }

    for (int i=0; i<n-1; i++)
        if (check_palindrome(0,i, diffs)) total++;

    for (int i=1; i<n-1; i++)
        if (check_palindrome(i,n-2, diffs)) total++;

    cout << total << endl;
}