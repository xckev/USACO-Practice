#include <bits/stdc++.h>
using namespace std;

//feb 2020

int n;
pair<int,int> posts[100000];
long long sumx[100000]; //stores sum in x-diffs
long long sumy[100000]; //stores sum in y-diffs
map<pair<int,int>,int> mp;

bool ycompare(pair<int,int> x, pair<int,int> y) {
    if(x.second < y.second) {
        return true;
    }
    else if (x.second == y.second) {
        return x.first < y.first;
    }
    return false;
}

//overall idea: ans = (sum of all differences in y along the same x) * (sum of all differences in x along the same y) for all posts

int main() {
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");
    fin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        fin >> x >> y;
        posts[i].first = x;
        posts[i].second = y;
        mp[posts[i]] = i; //giving each x,y pair ID
    }
    sort(posts, posts + n); //sort by x
    for (int i = 0; i < n;) {
        int j = i + 1;
        int total = 1; //num of posts with same x
        //this loop only runs for the first post with a new x-coordinate*
        while (posts[j].first == posts[i].first) { //going thru all the ones with same x
            sumy[mp[posts[i]]] += posts[j].second-posts[i].second; //all the differences in y-coords for the posts ABOVE i-th post
            total++;
            j++;
        }
        j = i + 1;
        long long prev = sumy[mp[posts[i]]]; //using sumy of i-th post to find sumy of j-th post. sumy of posts can be found using the previous posts' sumy
        while (posts[j].first == posts[i].first) {
            /*
            explanation for next lines of code:
            unit = (posts[j].second - posts[j-1].second) represents distance between current post j and previous post i
            below = (j-i) represents the number of posts below j (so we must add that number of units to the distances corresponding with the posts below j)
            above = total - (below)  represents the number of posts above j (so we must subtract that number of units to the distances corresponding with the posts above j)
            */
            int unit = posts[j].second - posts[j-1].second;
            int below = j-i;
            int above = total - below;
            sumy[mp[posts[j]]] = prev + (unit) * (below - above); //"recursive" formula for sumy
            prev = sumy[mp[posts[j]]]; //update prev
            j++;
        }
        i = j; //*skip i to the next x-coord
    }
//same thing, but now sort by y and add x-diffs
    sort(posts, posts + n, ycompare);
    for (int i = 0; i < n;) {
        int j = i + 1;
        int total = 1;
        while (posts[j].second == posts[i].second) {
            sumx[mp[posts[i]]] += posts[j].first-posts[i].first;
            total++;
            j++;
        }
        j = i + 1;
        long long prev = sumx[mp[posts[i]]];
        while (posts[j].second == posts[i].second) {
            int unit = posts[j].first - posts[j-1].first;
            int left = j-i;
            int right = total - left;
            sumx[mp[posts[j]]] = prev + (unit) * (left - right);
            prev = sumx[mp[posts[j]]];
            j++;
        }
        i = j;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += sumx[mp[posts[i]]]*sumy[mp[posts[i]]] % 1000000007;
        ans %= 1000000007;
    }
    fout << ans << endl;
}