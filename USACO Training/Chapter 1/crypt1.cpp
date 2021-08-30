/*
ID: xckevin1
LANG: C++
TASK: crypt1
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int gooddigits[10];

int isgood(int n, int d){
    if(n == 0)
		return 0;

    while(n) {
        if(!gooddigits[n%10])
            return 0;
        n /= 10;
        d--;
    }

    if( d == 0 )
       return 1;
    else
       return 0;
}

int isgoodprod(int n, int m) {
    if(!isgood(n,3) || !isgood(m,2) || !isgood(n*m,4))
	    return 0;

    while(m) {
        if(!isgood(n*(m%10),3))
            return 0;
	    m /= 10;
    }
    return 1;
}

int main(){
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");

    int n;
    fin >> n;

    for(int i = 0; i < n; i++){
        int e;
        fin >> e;
        gooddigits[e] = 1;
    }


    int found = 0;
    for(int i=100; i<1000; i++){
        for(int j=10; j<100; j++){
            if(isgoodprod(i, j))
		        found++;
        }
    }

    fout << found << endl;

}