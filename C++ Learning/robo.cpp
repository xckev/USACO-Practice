#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;

    int curr = 1;
    stack<int> s;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        if(temp == "ADD"){
            s.push(curr);
            curr++;
        }
        else{
            s.pop();
        }
    }

    int lim = s.size();
    cout << lim << endl;

    stack<int> toPrint;
    for(int i = 0; i < lim; i++){
        toPrint.push(s.top());
        s.pop();
    }

    for(int i = 0; i < lim; i++){
        cout << toPrint.top() <<endl;
        toPrint.pop();
    }

}