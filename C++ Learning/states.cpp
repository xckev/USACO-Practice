#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    string a[n];
    for(int i = 0; i < n; i++){
        string ct, st;
        cin >> ct >> st;
        string s = ct.substr(0,2) + st;
        a[i] = s;
        //cout << s << endl;
    }

    sort(a, a+n);
    
    int ans = 0;
    /*
    for(int i = 0; i < n; i++){
        string s = a[i];
        cout << s << endl;
        string temp = s.substr(2,1) + s.substr(3,1) + s.substr(0,1) + s.substr(1,1);
        ans += upper_bound(a, a+n, temp) - lower_bound(a, a+n, temp);
        cout << "upper: " << *upper_bound(a, a+n, temp) << "lower: " << *lower_bound(a, a+n, temp) << endl;
    }
    //ans /= 2;
    */

   for(int i = 0; i < n-1; i++){
        string s = a[i];
        string temp = s.substr(2,1) + s.substr(3,1) + s.substr(0,1) + s.substr(1,1);
       for(int j = i+1; j < n; j++){
           if(a[j] == temp){
               ans++;
           }
       }
   }
    cout << ans << endl;
}