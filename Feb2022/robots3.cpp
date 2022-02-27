#include <bits/stdc++.h>
using namespace std;

struct hash_tuple {
    template <class T1, class T2, class T3>
    size_t operator()(const tuple<T1, T2, T3>& p) const
    {
        auto a = get<0>(p);
        auto b = get<1>(p);
        auto c = get<2>(p);
        return (1000000000+7)*(1000000000+7) * a + (1000000000+7)*b + c;
    }
};

int N;
vector<pair<int, int>> moves1;
vector<pair<int, int>> moves2;
unordered_map<tuple<int, int, int>, int, hash_tuple> locationfreq1;
unordered_map<tuple<int, int, int>, int, hash_tuple> locationfreq2;
int fh, sh;
long long xg, yg;

void populate1(long long x, long long y, int depth, int chosen, bool lastused){
    if(lastused){
        locationfreq1[{x, y, chosen}] += 1;
    }
    
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
        locationfreq2[{x, y, chosen}] += 1;
    }
    
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
    populate2(0, 0, 0, 0, true);
    
    
    //int cnt = 0;
    for(int i = 1; i <= N; i++){
        
        long long ans = 0;
        for(auto& p : locationfreq1){
            //cnt++;
            auto& state = p.first;
            int x = get<0>(state);
            int y = get<1>(state);
            int moves = get<2>(state);
            int freq1 = p.second;

            int xdiff = xg - x;
            int ydiff = yg - y;
            int movesdiff = i - moves;

            if(x == 0 && y == 0){
                if(moves == 0){
                    freq1 = 1;
                }
            }
            
            if(movesdiff >= 0){
                if (locationfreq2.count({xdiff, ydiff, movesdiff})){
                    int freq2 = locationfreq2[{xdiff, ydiff, movesdiff}];
                    if(xdiff == 0 && ydiff == 0){
                        if(movesdiff == 0){
                            freq2 = 1;
                        }
                        
                    }
                    if(!(x == 0  && y == 0 && movesdiff > 1) || !(moves > 1 && xdiff == 0 && ydiff == 0)){
                        ans += (freq1 * freq2);
                    }
                }
                
            }
            //if(cnt > 5000000){
            //    cout << "test" << endl;
            //    return 0;
            //}
        }
        cout << ans << endl;
    }
}