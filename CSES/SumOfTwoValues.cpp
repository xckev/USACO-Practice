#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> orig;
int arr[200001];

int main(){
    cin >> n >> x;

    for(int i = 0; i < n; i++){
        int e;
        cin >> e;
        orig.push_back(e);
        arr[i] = e;
    }

    sort(arr, arr+n);

    int p1 = 0;
    int p2 = n-1;
    int a, b;
    int none = true;
    while(p1 < p2){
        a = arr[p1];
        b = arr[p2];

        if(a + b == x){
            none = false;
            break;
        }
        else if(a + b < x){
            p1++;
        }
        else{
            p2--;
        }
    }

    if(none){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        int pos1 = find(orig.begin(), orig.end(), a) - orig.begin() + 1;
        reverse(orig.begin(), orig.end());
        int pos2 = orig.end() - find(orig.begin(), orig.end(), b);

        cout << min(pos1, pos2) << " " << max(pos1, pos2) << endl;
    }
    
}