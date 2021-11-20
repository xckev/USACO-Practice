#include <bits/stdc++.h>
using namespace std;

//dec 2015

int N, Q;
int H[100001];
int G[100001];
int J[100001];

int main(){
    ofstream fout ("bcount.out");
    ifstream fin ("bcount.in");
    fin >> N >> Q;

    int htotal = 0;
    int gtotal = 0;
    int jtotal = 0;
    for(int i = 1; i <= N; i++){
        int e;
        fin >> e;

        H[i] = H[i-1];
        G[i] = G[i-1];
        J[i] = J[i-1];
        if(e == 1){
            htotal++;
            H[i] = htotal;

        }
        else if(e == 2){
            gtotal++;
            G[i] = gtotal;
        }
        else{
            jtotal++;
            J[i] = jtotal;
        }
        
    }

    for(int i = 0; i < Q; i++){
        int a, b;
        fin >> a >> b;

        int hres = H[b] - H[a-1];
        int gres = G[b] - G[a-1];
        int jres = J[b] - J[a-1];

        fout << hres << " " << gres << " " << jres << endl;
    }


}