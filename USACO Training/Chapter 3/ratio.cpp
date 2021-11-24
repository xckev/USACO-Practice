/*
ID: xckevin1
LANG: C++
TASK: ratios
*/

#include <bits/stdc++.h>
using namespace std;

int goal[3];
int mixes[3][3];

int ans[3];
int mult;
int besttotal = 99999999;
bool found = false;

int check(int B, int O, int W){
    bool ok = true;
    if(B == 0){
        if(goal[0] > 0){
            ok = false;
        }
    }
    if(goal[0] == 0){
        if(B > 0){
            ok = false;
        }
    }
    else if(B % goal[0] > 0){
        ok = false;
    }

    if(O == 0){
        if(goal[1] > 0){
            ok = false;
        }
    }
    if(goal[1] == 0){
        if(O > 0){
            ok = false;
        }
    }
    else if(O % goal[1] > 0){
        ok = false;
    }

    if(W == 0){
        if(goal[2] > 0){
            ok = false;
        }
    }
    if(goal[2] == 0){
        if(W > 0){
            ok = false;
        }
    }
    else if(W % goal[2] > 0){
        ok = false;
    }
    
    if(ok){
        if((B * goal[1]) == (O * goal[0]) && (O * goal[2]) == (W * goal[1])){
            if(besttotal > B+O+W){
                besttotal = B+O+W;
                if(goal[0] != 0){
                    mult = B/goal[0];
                }
                else{
                    mult = 0;
                }
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    ofstream fout ("ratios.out");
    ifstream fin ("ratios.in");
    for(int i = 0; i < 3; i++){
        fin >> goal[i];
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            fin >> mixes[i][j];
        }
    }

    
    
    for(int f = 0; f < 100; f++){
        for(int s = 0; s < 100; s++){
            for(int t = 0; t < 100; t++){
                if(f != 0 || s!= 0 || t != 0){
                    //cout << "in" << endl;
                    int B = f * mixes[0][0] + s * mixes[1][0] + t * mixes[2][0];
                    int O = f * mixes[0][1] + s * mixes[1][1] + t * mixes[2][1];
                    int W = f * mixes[0][2] + s * mixes[1][2] + t * mixes[2][2];

                    int good = check(B, O, W);
                    if(good){
                        found = true;
                        ans[0] = f; ans[1] = s; ans[2] = t;
                    }
                }
            }
        }
    }
    if(found){
        fout << ans[0] << " " << ans[1] << " " << ans[2] << " " << mult << endl;
    }
    else{
        fout << "NONE" << endl;
    }

}