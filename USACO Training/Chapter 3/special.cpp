#include <iostream>
#include <math.h>
#include <map>
#include <set>
#include <vector>
#include <fstream>
using namespace std;

bool isprime(int a){
    double lim = sqrt(a);
    for(int i = 2; i < lim; i++){
        if(a % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    set<int> s;
    int total = 0;
    for(int a = 1; a < 15; a++){
        double b = 15.0 - a;
        for(int i = 1; i < 15; i++){
            double j = 15.0 - i;
            
            double res = (a/b) + (i/j);
            if(res == (int)res){
                //cout << a << "/" << b << " and " << i << "/" << j << endl;
                total++;
                s.insert(res);
                cout << res << endl;
            }
        }
    }

    cout << s.size() << endl;
    
   /*
   for(int i = 16383; i >= 1; i--){
       if(isprime(i)){
           if(16383 % i == 0){
                cout << i << endl;
                break;
            }
            else{
                //cout << 16383 << "/" << i << " = " << ((double) 16383 / i) << endl;
            }
       }
        
    */
   
}