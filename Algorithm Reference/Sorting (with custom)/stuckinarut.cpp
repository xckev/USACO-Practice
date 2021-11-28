#include <bits/stdc++.h>
using namespace std;

//dec 2020

int N;
vector<int> easters;
vector<int> northers;
int xcoords[1001];
int ycoords[1001];

bool comp1(int a, int b){
    return ycoords[a] < ycoords[b];
}

bool comp2(int a, int b){
    return xcoords[a] < xcoords[b];
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        string dir;
        int x, y;
        cin >> dir >> x >> y;
        if(dir == "E"){
            easters.push_back(i);
        }
        else{
            northers.push_back(i);
        }
        xcoords[i] = x;
        ycoords[i] = y;
    }

    sort(easters.begin(), easters.end(), comp1);
    sort(northers.begin(), northers.end(), comp2);
    bool stopped[N];
    fill(stopped, stopped + N, false);
    int numstopped[N];
    fill(numstopped, numstopped + N, 0);
    for(int i : easters){
        for(int j : northers){
            if(!stopped[i] && !stopped[j] && xcoords[j] > xcoords[i] && ycoords[i] > ycoords[j]){
                if (xcoords[j] - xcoords[i] > ycoords[i] - ycoords[j]) {
                    stopped[i] = true;
                    numstopped[j] += 1 + numstopped[i];
                } 
                else if (ycoords[i] - ycoords[j] > xcoords[j] - xcoords[i]) {
                    stopped[j] = true;
                    numstopped[i] += 1 + numstopped[j];
                }
            }
        }
    }

    for(int i = 0; i < N; i++){
        cout << numstopped[i] << endl;
    }
}