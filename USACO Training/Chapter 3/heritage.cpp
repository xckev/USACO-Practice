/*
ID: xckevin1
LANG: C++
TASK: heritage
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

char inorder[29];
char preorder[29];

void solve(int instart, int inend, int prestart, int preend, ofstream &fout){
    if(instart == inend){
        fout << inorder[instart];
        return;
    }
    else if (instart > inend){
        return;
    }
    
    char preroot = preorder[prestart];
    int inroot = 0;
    for(int i = instart; i <= inend; i++){
        if(inorder[i] == preroot){
            inroot = i;
        }
    }
    //left subtree
    solve(instart, inroot-1, prestart+1, prestart + (inroot - instart) - 1, fout);
    //right subtree
    solve(inroot+1, inend, prestart + (inroot - instart) + 1, preend, fout);
    //root
    fout << preroot;
}

int main(){
    ofstream fout ("heritage.out");
    ifstream fin ("heritage.in");
    string s1, s2;
    fin >> s1;
    fin >> s2;

    for(int i = 0; i < s1.size(); i++){
        inorder[i] = s1[i];
    }
    for(int i = 0; i < s2.size(); i++){
        preorder[i] = s2[i];
    }
    int n = s1.size();
    solve(0, n-1, 0, n-1, fout);
    fout << endl;

}