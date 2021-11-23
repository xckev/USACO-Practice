/*
ID: xckevin1
LANG: C++
TASK: spin
*/

//simulation...

#include <bits/stdc++.h>
using namespace std;

int num[5];
int speed[5];
int startangle[5][5];
int ext[5][5];

int numsame[360];

int main(){
    ofstream fout ("spin.out");
    ifstream fin ("spin.in");
    for(int i = 0; i < 5; i++){
        fin >> speed[i] >> num[i];
        for(int j = 0; j < num[i]; j++){
            fin >> startangle[i][j] >> ext[i][j];
        }
    }

    bool tobreak = false;
    for(int time = 0; time < 360; time++){
        fill(numsame, numsame+360, 0);

        for(int i = 0; i < 5; i++){
            int dir = (time * speed[i]);
            for(int j = 0; j < num[i]; j++){
                int start = (dir + startangle[i][j]);
                int end = start + ext[i][j];

                for(int k = start; k <= end; k++){
                    numsame[k%360]++;
                }
            }
        }
        for(int i = 0; i < 360; i++){
            if(numsame[i] == 5){
                fout << time << endl;
                tobreak = true;
                break;
            }
        }
        if(tobreak){
            break;
        }
    }
    
    if(tobreak == false){
        fout << "none" << endl;
    }


}