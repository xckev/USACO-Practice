#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

struct seat{
    int row, col;
    double dist;
    
    seat(){
    }
    /*
    void distance(seat s){
        dist = pow((row - s.row), 2) + pow((col - s.col), 2);
        cout << row << "-" << s.row << " squared plus " << col << "-" << s.col << " squared is " << dist << endl;
    }*/
};

bool comp(seat s1, seat s2){
    if(s1.dist < s2.dist){
        return true;
    }
    else if(s1.dist > s2.dist){
        return false;
    }
    else{
        if(s1.row < s2.row){
            return true;
        }
        else if(s1.row > s2.row){
            return false;
        }
        else{
            if(s1.col < s2.col){
                return true;
            }
            else{
                return false;
            }
        }
    }
}

int main(){
    int w, r;
    cin >> w >> r;

    seat best = seat();
    best.row = 1; best.col = (w+1)/2;
    //cout << "best col is " << best.col << endl;

    seat theater[w*r];

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= w; j++){
            int ind = (i-1)*w + (j-1);
            //cout << ind << endl;
            if(i == best.row && j == best.col){
                best.dist = 0;
                theater[ind] = best;
                //cout << "seat at " << i << ", " << j << " has distance " << best.dist << endl;
            }
            else{
                seat s = seat();
                s.row = i; s.col = j;
                s.dist = pow((i-best.row), 2) + pow((j-best.col),2);
                //cout << i << "-" << best.row << " squared plus " << j << "-" << best.col << " squared is " << s.dist << endl;
                theater[ind] = s;
                //cout << "seat at " << i << ", " << j << " has distance " << s.dist << endl;
            }
        }
    }

    sort(theater, theater + (w*r), comp);
    int display[r][w];

    for(int i = 0; i < w*r; i++){
        seat s = theater[i];
        display[s.row-1][s.col-1] = i+1;
        //cout << s.row-1 << " " << s.col-1 << endl;
        //cout << i+1 << endl;
    }
    for(int i = r-1; i >= 0; i--){
        for(int j = 0; j < w; j++){
            cout << display[i][j] << " ";
        }
        cout << "\n";
    }
}