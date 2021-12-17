#include <string.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n, m;
int startx, starty;
int minHeight = 999999999;
int maxHeight = 0;

int course[501][501];
bool waypoints[501][501];
bool seen[501][501];

void floodfill(int i, int j, int d, int prevHeight) {
	if (i < 0 || i >= n || j < 0 || j >= m) {
		return;
	}
	if (seen[i][j]) {
		return;
	}
	if (abs(course[i][j] - prevHeight) > d) {
		return;
	}

	seen[i][j] = true;

	floodfill(i + 1, j, d, course[i][j]);
	floodfill(i - 1, j, d, course[i][j]);
	floodfill(i, j + 1, d, course[i][j]);
	floodfill(i, j - 1, d, course[i][j]);
}

bool reachable(int d) {
	memset(seen, false, sizeof(seen));
	floodfill(startx, starty, d, course[startx][starty]);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (waypoints[i][j] && !seen[i][j]) {
				return false;
			}
		}
	}
		
	return true;
}

int main(){
    ofstream fout ("ccski.out");
    ifstream fin ("ccski.in");
    fin >> n >> m;

    for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fin >> course[i][j];
			minHeight = min(minHeight, course[i][j]);
			maxHeight = max(maxHeight, course[i][j]);
		}
	}

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int e;
            fin >> e;

            if(e == 1){
                waypoints[i][j] = true;
                startx = i;
                starty = j;
            }
            else{
                waypoints[i][j] = false;
            }
        }
    }

    int lo = 0;
	int hi = maxHeight - minHeight;
	int minD = -1;
	while (lo <= hi) {
		int d = (lo + hi) / 2;
		if (reachable(d)) {
			minD = d;
			hi = d - 1;
		} 
        else {
			lo = d + 1;
        }
	}

    fout << minD << endl;
}