#include <bits/stdc++.h>
using namespace std;

//feb 2021

int n;
bool cows[3000][3000];
//int xcoords[100001];
//int ycoords[100001];
int ans = 0;

int iscomfortable(int x, int y){
    int count = 0;
    int toret = 0;
    if(cows[x-1][y]){
        count++;
    }
    else{
        toret = 1;
    }
    if(cows[x+1][y]){
        count++;
    }
    else{
        toret = 2;
    }
    if(cows[x][y-1]){
        count++;
    }
    else{
        toret = 3;
    }
    if(cows[x][y+1]){
        count++;
    }
    else{
        toret = 4;
    }
    if(count == 3){
        return toret;
    }
    return 0;
}

void add(int x, int y){
    if(!cows[x][y]){
        cows[x][y] = true;
        ans++;
        int comfy = iscomfortable(x, y);
        if(comfy != 0){
            if(comfy == 1){
                add(x-1, y);
            }
            else if(comfy == 2){
                add(x+1, y);
            }
            else if(comfy == 3){
                add(x, y-1);
            }
            else{
                add(x, y+1);
            }
        }

        comfy = iscomfortable(x-1, y);
        if(cows[x-1][y] && comfy != 0){
            if(comfy == 1){
                add(x-1-1, y);
            }
            else if(comfy == 2){
                add(x-1+1, y);
            }
            else if(comfy == 3){
                add(x-1, y-1);
            }
            else{
                add(x-1, y+1);
            }
        }
        comfy = iscomfortable(x+1, y);
        if(cows[x+1][y] && comfy != 0){
            if(comfy == 1){
                add(x+1-1, y);
            }
            else if(comfy == 2){
                add(x+1+1, y);
            }
            else if(comfy == 3){
                add(x+1, y-1);
            }
            else{
                add(x+1, y+1);
            }
        }
        comfy = iscomfortable(x, y-1);
        if(cows[x][y-1] && comfy != 0){
            if(comfy == 1){
                add(x-1, y-1);
            }
            else if(comfy == 2){
                add(x+1, y-1);
            }
            else if(comfy == 3){
                add(x, y-1-1);
            }
            else{
                add(x, y-1+1);
            }
        }
        comfy = iscomfortable(x, y+1);
        if(cows[x][y+1] && comfy != 0){
            if(comfy == 1){
                add(x-1, y+1);
            }
            else if(comfy == 2){
                add(x+1, y+1);
            }
            else if(comfy == 3){
                add(x, y+1-1);
            }
            else{
                add(x, y+1+1);
            }
        }

    }
    
}

int main(){
    cin >> n;

    //memset(cows, false, size(cows));
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        ans--; //to remove the cow needed for prev iteration
        x += 1000;
        y += 1000;
        add(x, y);
        cout << ans << endl;
    }

}