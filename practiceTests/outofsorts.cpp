#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

// 2018 open

int N;
vector<int> nums;
vector<int> sorted;
map<int, int> correspond;

int main(){
    ifstream fin("sort.in");
    ofstream fout("sort.out");
    fin >> N;

    for(int i = 0; i < N; i++){
        int e;
        fin >> e;
        nums.push_back(e);
        sorted.push_back(e);
    }
    sort(sorted.begin(), sorted.end());

    for(int i = 0; i < N; i++){
        correspond[sorted[i]] = i;
    }

    for(int i = 0; i < N; i++){
        nums[i] = correspond[nums[i]];
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        int dist = i - nums[i];
        ans = max(ans, dist);
    }

    fout << ans+1 << endl;

}