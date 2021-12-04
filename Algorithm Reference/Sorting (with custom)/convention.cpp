#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

//dec 2018

using namespace std;

int N;
vector<vector<int>> cows;

bool cmp(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int main() {
	ofstream fout ("convention2.out");
    ifstream fin ("convention2.in");
	
	
	fin >> N;
	for (int i = 0; i < N; i++) {
		int start, duration;
		fin >> start >> duration;
		cows.push_back({i, start, duration});
	}

	sort(cows.begin(), cows.end(), cmp);

	int time = 0;
    int curr = 0;
    int ans = 0;
	
	// sorted by highest seniority
	set<vector<int>> waiting;
	while (curr < N || waiting.size() > 0) {
		// add new cow to wait queue
		if (curr < N && cows[curr][1] <= time) {
			waiting.insert(cows[curr]);
			curr++;
		} 
        // no cow waiting
        else if (waiting.size() == 0) {
			// set time to the ending time of the next cow
			time = cows[curr][1] + cows[curr][2];
			curr++;
		} 
        else {
			// process next cow
			vector<int> next = *waiting.begin();
			ans = max(ans, time - next[1]);

			//set the time to when cow finishes
			time += next[2];
			waiting.erase(waiting.begin());
		}
	}
	fout << ans << '\n';
}
