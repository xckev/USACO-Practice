#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <set>
#include <fstream>
using namespace std;

int n;
set<int> s;
int a[200000];
int ans;

int main() {
	int r = -1;
	cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> a[i];
    } 
	for(int i = 0; i < n; i++) {
		while (r < n-1 && s.count(a[r+1]) == 0){
            s.insert(a[++r]);
        }
		ans = max(ans,r-i+1);
		s.erase(a[i]);
	}
	cout << ans << endl;
}
/*
int n;
set<int> s;
int a[200000], ans;

int main() {
	int r = -1;
	cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    } 
	for(int i = 0; i < n; i++) {
		while (r < n-1 && !s.count(a[r+1])) s.insert(a[++r]);
		ans = max(ans,r-i+1);
		s.erase(a[i]);
	}
	cout << ans;
}
*/