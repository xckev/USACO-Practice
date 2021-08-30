/*
ID: xckevin1
LANG: C++
TASK: friday
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    int n;
    fin >> n;
    map<int, int> thirteen;

    for(int i = 0; i < 7; i++){
        thirteen[i] = 0;
    }

    int currday = 0;
    for(int i = 0; i < n; i++){
        int year = 1900 + i;
        for(int j = 1; j <= 12; j++){
            //cout << "first day of month " << j << ": " << currday << endl;
            int thirteenth = (currday + 12) % 7;
            thirteen[thirteenth] += 1;

            if(j == 2){
                if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
                    currday = (currday + 29) % 7;
                }
                else{
                    currday = (currday + 28) % 7;
                }
            }
            else if(j == 9 || j == 4 || j == 6 || j == 11){
                currday = (currday + 30) % 7;
            }
            else{
                currday = (currday + 31) % 7;
            }

        }
    }

    fout << thirteen[5] << " " << thirteen[6];
    for(int i = 0; i < 5; i++){
        fout << " " << thirteen[i];
    }
    fout << endl;

}