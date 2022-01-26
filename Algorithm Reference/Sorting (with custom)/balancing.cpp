#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <set>
#include <fstream>
using namespace std;

//feb 2016

int n;
vector<pair<int, int>> coords;

int main(){
	ofstream fout ("balancing.out");
    ifstream fin ("balancing.in");
    fin >> n;

    for(int i = 0; i < n; i++){
        int x, y;
        fin >> x >> y;
        coords.push_back({x, y});
    }
    sort(coords.begin(), coords.end());
    
    int ans = coords.size();
	
    for(int i = 0; i < n; i++) { //ith coordd determines horiz line
			//cout << "---------------horiz fence at y = " << coords[i].second << endl;
		vector<pair<int, int>> under;
		vector<pair<int, int>> above;

		for(int j = 0; j < n; j++) {
			if(coords[j].second <= coords[i].second) { //finding all coords above and below horiz line
				under.push_back(coords[j]);
			}
			else {
				above.push_back(coords[j]);
			}
		}
        //now to find vert line
        int underInd = 0;
		int aboveInd = 0;
		
		while(underInd < under.size() || aboveInd < above.size()) {
			int vertfence = 99999999;
            //picking smallest to largest x-coord for vertical lines
			if(underInd < under.size()) {
				vertfence = min(vertfence, under[underInd].first);
			}
			if(aboveInd < above.size()) {
				vertfence = min(vertfence, above[aboveInd].first);
			}
				//cout << "----------vert fence at x = " << vertfence << endl;
            //moving past indexes of coords on the fence
			while(underInd < under.size() && under[underInd].first == vertfence) {
				underInd++;
			}
			while(aboveInd < above.size() && above[aboveInd].first == vertfence) {
				aboveInd++;
			}
				//cout << "underInd = " << underInd << endl;
				//cout << "aboveInd = " << aboveInd << endl;

			int underSize = under.size();
			int aboveSize = above.size();
				//cout << "underSize = " << underSize << endl;
				//cout << "aboveSize = " << aboveSize << endl;
				//cout << "underSize - underInd = " << underSize - underInd << endl;
				//cout << "aboveSize - aboveInd = " << aboveSize - aboveInd << endl;
            int maxBotRegions = max(underInd, underSize - underInd);
            int maxTopRegions = max(aboveInd, aboveSize - aboveInd);
				//cout << "maxBotRegions = " << maxBotRegions << endl;
				//cout << "maxTopRegions = " << maxTopRegions << endl;
			ans = min(ans, max(maxBotRegions, maxTopRegions));
				//cout << "ans = " << ans << endl;
		}
		
    }
    fout << ans << endl;

}