#include <bits/stdc++.h>
using namespace std;

//feb 2018

ifstream fin("teleport.in");
ofstream fout("teleport.out");

int n;
vector<pair<int,int>> rc;
vector<pair<int,int>> lc;

int main()
{
    fin >> n;
    long long dist = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        fin >> a >> b;
        dist += abs(a - b);
        if (b > a)
        {
            if (b <= 2 * a)
                continue;
            if (b <= 0)
                continue;
            rc.push_back({max(2 * a, 0), 1}); //benefit increase of 1 for every y past 2a or 0
            rc.push_back({b, -2}); // benefit has a relative decrease from 1 to -1 for every y past b
            rc.push_back({2 * b - max(2 * a, 0), 1}); // remove benefit consideration after b + (b-2a)... -1 + 1 = 0
        }
        else
        {
            a = -a;
            b = -b;
            if (b <= 2 * a)
                continue;
            if (b <= 0)
                continue;
            lc.push_back({max(2 * a, 0), 1});
            lc.push_back({b, -2});
            lc.push_back({2 * b - max(2 * a, 0), 1});
        }
    }
    sort(rc.begin(), rc.end());
    sort(lc.begin(), lc.end());

    long long maxbenefit = 0;
    long long benefit = 0;
    long long increment = 0;
    long long prev = 0;
    for (pair<int,int> p : rc)
    {
        benefit += increment * (p.first - prev);
        increment += p.second;
        prev = p.first;
        maxbenefit = max(maxbenefit, benefit);
    }
    benefit = 0;
    increment = 0;
    prev = 0;
    for (pair<int,int> p : lc)
    {
        benefit += increment * (p.first - prev);
        increment += p.second;
        prev = p.first;
        maxbenefit = max(maxbenefit, benefit);
    }
    fout << dist - maxbenefit << endl;
}