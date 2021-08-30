#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int v, g;

string decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];
 
    // counter for binary array
    int i = 0;
    while (n > 0) {
 
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    // printing binary array in reverse order
    string s = "";
    for (int j = i - 1; j >= 0; j--){
        s += binaryNum[j];
    }

    return s;
}

bool check(int req[], int sums[]){
    for(int i = 0; i < v; i++){
        if(sums[i] < req[i]){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> v;
    int required[v];
    for(int i = 0; i < v; i++){
        cin >> required[i];
    }

    cin >> g;
    int feeds[g][v];
    for(int i = 0; i < g; i++){
        for(int j = 0; j < v; j++){
            cin >> feeds[i][j];
        }
    }

    int sums[v];
    for(int i = 0; i < v; i++){
        sums[i] = 0;
    }
    int min = INT32_MAX;
    string correct = "";

    int max = pow(2, g);
    int i = 0;
    while(i < max){
        int sums[v];
        for(int j = 0; j < v; j++){
            sums[j] = 0;
        }
        string binS = decToBinary(i);
        cout << binS << endl;
        int scoops = 0;
        string curr = "";
        for(int j = binS.size()-1; j >= 0; j++){
            if(binS[j] == '1'){
                scoops++;
                curr += (j+1) + " ";
                int diff = g - (binS.size() - j);
                for(int k = 0; k < v; k++){
                    sums[k] += feeds[diff][k];
                }
            }
        }

        if(check(required, sums)){
            if(scoops < min){
                min = scoops;
                correct = curr;
            }
        }

    }


    cout << min << correct << endl;

}