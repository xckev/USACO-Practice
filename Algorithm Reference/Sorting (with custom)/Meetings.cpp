#include <bits/stdc++.h>
using namespace std;

//dec 2019

int N, L;
vector<int> w, x, d;

bool comp(int a, int b){
    return x[a] < x[b];
}

int getTime(){
    
    vector<int> left, right;
	for(int i = 0; i < N; i++){
		if (d[i] == -1){
            left.push_back(x[i]);
        }
		else {
            right.push_back(x[i]);
        }
	}
	vector<pair<int, int>> v;
	for(int i = 0; i < left.size(); i++){
        v.push_back({left[i], w[i]});
    } 
	for(int i = 0; i < right.size(); i++){ 
        v.push_back({L-right[i], w[left.size() + i]});
    }
	sort(v.begin(), v.end());
	int tot = 0; 
    for(pair<int, int> p : v){
        tot += p.second;
    } 
	for(pair<int, int> p : v){
		tot -= 2 * p.second; // determining when half the weight has reached barns
		if (tot <= 0){
            return p.first;
        }
	}
    return 0;
}

int main(){
    ifstream fin("meetings.in");
    ofstream fout("meetings.out");
    fin >> N >> L;

    w.resize(N);
    x.resize(N);
    d.resize(N);
    for(int i = 0; i < N; i++){
        fin >> w[i] >> x[i] >> d[i];
    }

    vector<int> indices;
    for(int i = 0; i < N; i++){
        indices.push_back(i);
    }
    sort(indices.begin(), indices.end(), comp);

    vector<int> W, X, D;
	for(int t : indices) {
		W.push_back(w[t]);
		X.push_back(x[t]);
		D.push_back(d[t]);
	}
	swap(w,W);
    swap(x,X);
    swap(d,D);

    int time = getTime();
    queue<int> right;
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(d[i] == -1){
            // two cows with xi<xj will meet if di=1,dj=−1,xi+2T≥xj
            while(!right.empty() && (right.front() + 2*time) < x[i]){
                right.pop();
            }
            ans += right.size();
        }
        else{
            right.push(x[i]);
        }
    }
    fout << ans << endl;
}