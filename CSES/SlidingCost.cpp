#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<long long> arr;
multiset<long long> great;
multiset<long long> lesser;
long long hisum, losum;

void add(long long e){
    long long med = *lesser.rbegin();
    if(med < e){
        great.insert(e);
        hisum += e;
        if(great.size() > k/2){
            long long tomove = *great.begin();
            lesser.insert(tomove);
            losum += tomove;
            great.erase(great.find(tomove));
            hisum -= tomove;
        }
    }
    else{
        lesser.insert(e);
        losum += e;
        if(lesser.size() > (k+1)/2){
            long long tomove = *lesser.rbegin();
            great.insert(tomove);
            hisum += tomove;
            lesser.erase(lesser.find(*lesser.rbegin()));
            losum -= tomove;
        }
    }
    
}

void del(long long e){
    if(great.find(e) != great.end()){
        great.erase(great.find(e));
        hisum -= e;
    }
	else{
        lesser.erase(lesser.find(e));
        losum -= e;
    }
	if(lesser.empty()){
        long long tomove = *great.begin();
		lesser.insert(*great.begin());
        losum += tomove;
		great.erase(great.find(*great.begin()));
        hisum -= tomove;
	}
}

long long median(){
    if(k % 2 == 0){
        return 0;
    }
    else{
        return *lesser.rbegin();
    }
}

int main(){
    cin >> n >> k;

    for(long long i = 0; i < n; i++){
        long long e;
        cin >> e;
        arr.push_back(e);
    }

    lesser.insert(arr[0]);
    losum += arr[0];
    for(long long i = 1; i < k; i++){
        add(arr[i]);
    }
    cout << hisum - losum + median();
    if(n != 1){
        cout << " ";
    }
    for(long long i = k; i < n; i++){
        if(k == 1){
            add(arr[i]);
            del(arr[i-k]);
        }
        else{
            del(arr[i-k]);
            add(arr[i]);
        }
        cout << hisum - losum + median();
        if(i != n-1){
            cout << " ";
        }
    }
    cout << endl;
}