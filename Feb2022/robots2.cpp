#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> moves1;
vector<pair<int, int>> moves2;
unordered_map<pair<pair<int, int>, int>, int> locationfreq1;
unordered_map<pair<pair<int, int>, int>, int> locationfreq2;
int fh, sh;
long long xg, yg;

void populate1(long long x, long long y, int depth, int chosen, bool lastused){
    //cout << "got to " << x << ", " << y << " with " << chosen << " moves" << endl;
    if(lastused){
        locationfreq1[{{x, y}, chosen}] += 1;
    }
    
    //cout << "frequency of that state after adding 1: " << locationfreq1[{{x, y}, chosen}] << endl;
    if(depth >= fh){
        return;
    }
    else{
        //choose to use move[depth]
        pair<int, int> p = moves1[depth];
        populate1(x+p.first, y+p.second, depth+1, chosen+1, true);

        //choose without
        populate1(x, y, depth+1, chosen, false);
    }
}

void populate2(long long x, long long y, int depth, int chosen, bool lastused){
    if(lastused){
        locationfreq2[{{x, y}, chosen}] += 1;
    }
    //cout << "got to " << x << ", " << y << " with " << chosen << " moves" << endl;
    //locationfreq2[{{x, y}, chosen}] += 1;
    
    //cout << "frequency of that state after adding 1: " << locationfreq2[{{x, y}, chosen}] << endl;
    if(depth >= sh){
        return;
    }
    else{
        //choose to use move[depth]
        pair<int, int> p = moves2[depth];
        populate2(x+p.first, y+p.second, depth+1, chosen+1, true);

        //choose without
        populate2(x, y, depth+1, chosen, false);
    }
}

int main(){
    cin >> N;
    cin >> xg >> yg;
    fh = (N+1)/2;
    sh = N-fh;

    for(int i = 0; i < fh; i++){
        int x, y;
        cin >> x >> y;
        moves1.push_back({x, y});
    }

    for(int i = 0; i < sh; i++){
        int x, y;
        cin >> x >> y;
        moves2.push_back({x, y});
    }


    populate1(0, 0, 0, 0, true);
    //cout << "----" << endl;
    populate2(0, 0, 0, 0, true);

    //cout << "--------------------------" << endl;

    for(auto p : locationfreq1){
        pair<int, int> loc = p.first.first;
        int moves = p.first.second;
        int freq1 = p.second;
        if(loc.first == 0 && loc.second == 0){
            freq1 = 1;
        }
        

        //cout << "location " << loc.first << ", " << loc.second << " with " << moves << " moves has frequency: " << freq1 << endl;
    }
    //cout << "-----" << endl;
    for(auto p : locationfreq2){
        pair<int, int> loc = p.first.first;
        int moves = p.first.second;
        int freq1 = p.second;
        if(loc.first == 0 && loc.second == 0){
            if(moves == 0){
                freq1 = 1;
            }
            else{
                freq1 = 0;
            }
        }
        

        //cout << "location " << loc.first << ", " << loc.second << " with " << moves << " moves has frequency: " << freq1 << endl;
    }
    //cout << "-----" << endl;
    
    for(int i = 1; i <= N; i++){
        long long ans = 0;
        //cout << "with " << i << " moves:" << endl; 
        for(auto& p : locationfreq1){
            pair<int, int> loc = p.first.first;
            int moves = p.first.second;
            int freq1 = p.second;

            int xdiff = xg - loc.first;
            int ydiff = yg - loc.second;
            int movesdiff = i - moves;

            if(loc.first == 0 && loc.second == 0){
                if(moves == 0){
                    freq1 = 1;
                }
            }
            
            if(movesdiff >= 0){
                int freq2 = locationfreq2[{{xdiff, ydiff}, movesdiff}];
                if(xdiff == 0 && ydiff == 0){
                    if(movesdiff == 0){
                        freq2 = 1;
                    }
                    
                }
                //cout << "move (" << loc.first << ", " << loc.second << ") of " << moves << " moves and " << freq1 << " frequency works with move (" << xdiff << ", " << ydiff << ") of " << movesdiff << " moves and " << freq2 << " frequency" << endl;
                if(!(loc.first == 0  && loc.second == 0 && movesdiff > 1) || !(moves > 1 && xdiff == 0 && ydiff == 0)){
                    ans += (freq1 * freq2);
                }
            }
        }
        cout << ans << endl;
    }
}