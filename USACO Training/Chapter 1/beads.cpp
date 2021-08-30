/*
ID: xckevin1
LANG: C++
TASK: beads
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

int n;

int score(string s, int ind){

    int left = 0, right = 0;
    int i = ind-1;
    string lcolor = "", rcolor = "";

    while(left < n){
        string bead = s.substr(i, 1);
        if(lcolor == "" && bead != "w"){
            lcolor = bead;
            //cout << "initiated lcolor as " << lcolor << ", ";
            if(lcolor == "r"){
                rcolor = "b";
            }
            else{
                rcolor = "r";
            }
            //cout << "rcolor is " << rcolor << endl;
        }

        if(bead == lcolor || bead == "w"){
            left++;
        }
        else{
            break;
        }
        i--;
    }

    if(lcolor == ""){
        return n;
    }

    i = ind;
    while(right < n){
        string bead = s.substr(i, 1);
        if(bead == rcolor || bead == "w"){
            right++;
        }
        else{
            break;
        }
        i++;
    }

    //cout << "left score: " << left << ", right score: " << right << endl;
    if(right + left > n){
        return n;
    }
    else{
        return right + left;
    }
}

int main(){
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    fin >> n;

    //          01234567890123456789012345678
    string s;// = "wwwbbrwrbrbrrbrbrwrwwrbwrwrrb";
    fin >> s;

    s += (s + s);

    int best = 0;
    for(int i = n; i < n + n; i++){
        //cout << " --------- " << endl;
        int curr = score(s, i);

        //cout << "break after " << i-n << ", score: " << curr << endl;
        //cout << " --------- " << endl;
        best = max(curr, best);
        if(best == n){
            break;
        }
    }

    fout << best << endl;


}