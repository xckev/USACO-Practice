/*
ID: xckevin1
LANG: C++
TASK: fence9
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

//pick's theorem
//A = a + (b/2) - 1;
//2a = 2area - b + 2;


int n, m, p;

int mygcd(int a, int b){
    if(b == 0){
        return a;
    }
    return mygcd(b, a%b);
}


int main(){
    ofstream fout ("fence9.out");
    ifstream fin ("fence9.in");
    fin >> n >> m >> p;

    int b = p+1; //inclusive of 0 on x axis

    int numerator1 = m;
    int denominator1 = n;
    if(denominator1 == 0){
        b += m;
    }
    else{
        int gcd1 = mygcd(max(numerator1, denominator1), min(numerator1, denominator1));
        int smallnumerator1 = numerator1/gcd1;
        int smalldenominator1 = denominator1/gcd1;

        b += (m / smallnumerator1);
    }
    

    int numerator2 = m;
    int denominator2 = abs(p-n);
    if(denominator2 == 0){
        b += m;
    }
    else{
        int gcd2 = mygcd(max(numerator2, denominator2), min(numerator2, denominator2));
        int smallnumerator2 = numerator2/gcd2;
        int smalldenominator2 = denominator2/gcd2;

        b += (m / smallnumerator2);
    }
    
    b--; //subtract meeting point at (n, m)

    //cout << b << endl;

    int areatimes2 = p*m;
    int a = (areatimes2 - b + 2)/2;

    fout << a << endl;
}