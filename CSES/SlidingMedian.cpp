#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> arr;
multiset<int> great;
multiset<int> lesser;

void add(int e){
    int med = *lesser.rbegin();
    if(med < e){
        great.insert(e);
        if(great.size() > k/2){
            lesser.insert(*great.begin());
            great.erase(great.begin());
        }
    }
    else{
        lesser.insert(e);
        if(lesser.size() > (k+1)/2){
            great.insert(*lesser.rbegin());
            lesser.erase(lesser.find(*lesser.rbegin()));
        }
    }
    
}

void del(int e){
    if(great.find(e) != great.end()){
        great.erase(great.find(e));
    }
	else{
        lesser.erase(lesser.find(e));
    }
	if(lesser.empty()){
		lesser.insert(*great.begin());
		great.erase(great.find(*great.begin()));
	}
}

int main(){
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int e;
        cin >> e;
        arr.push_back(e);
    }

    lesser.insert(arr[0]);
    for(int i = 1; i < k; i++){
        add(arr[i]);
    }
    cout << *lesser.rbegin() << " ";
    for(int i = k; i < n; i++){
        if(k == 1){
            add(arr[i]);
            del(arr[i-k]);
        }
        else{
            del(arr[i-k]);
            add(arr[i]);
        }
        cout << *lesser.rbegin() << " ";
    }
    cout << endl;
}