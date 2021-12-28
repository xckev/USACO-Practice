#include <bits/stdc++.h>
using namespace std;

//jan 2021
//either every row will alternate between cow and no-cow, or every column will alternate between cow and no-cow

int n;
int grid[1001][1001]; 

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    
    //for alternating cols
    int altcols = 0; 
    for(int row = 0; row < n; row++){
        int evensums = 0;
        int oddsums = 0;
        for(int col = 0; col < n; col++){
            if(col % 2 == 0){
                evensums += grid[row][col];
            }
            else{
                oddsums += grid[row][col];
            }
        }
        int better = max(evensums, oddsums);
        altcols += better;
    }

    //for alternating rows
    int altrows = 0; 
    for(int col = 0; col < n; col++){
        int evensums = 0;
        int oddsums = 0;
        for(int row = 0; row < n; row++){
            if(row % 2 == 0){
                evensums += grid[row][col];
            }
            else{
                oddsums += grid[row][col];
            }
        }
        int better = max(evensums, oddsums);
        altrows += better;
    }

    int ans = max(altrows, altcols);
    cout << ans << endl;
}