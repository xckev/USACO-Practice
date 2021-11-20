/*
ID: xckevin1
PROG: contact
LANG: C++11
*/


#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <fstream>
using namespace std;

int A, B, N;
map<string, int> M;

bool cmp(pair<string, int> a, pair<string, int> b){
    if(a.second > b.second){
        return true;
    }
    else if(a.second < b.second){
        return false;
    }
    else{
        if(a.first.size() == b.first.size()){
            return a.first < b.first;
        }
        else{
            return a.first.size() < b.first.size();
        }
    }
}

void sortnsolve(ofstream &fout){
 
    vector<pair<string, int>> A;
 
    for (pair<string, int> p : M) {
        A.push_back(p);
    }
 
    sort(A.begin(), A.end(), cmp);
    int asize = A.size();
    cout << "sorting done!" << endl;

    //print stuf here
    int counter = 0;
    int i = 0;
    int lastfreq;
    while(counter < N && i < asize){
        counter++;

        pair<string, int> p = A[i];
        fout << p.second << endl;
        lastfreq = p.second;

        int numsameline = 0;
        while(i < asize && p.second == lastfreq){
            fout << p.first;
            numsameline++;
            if(i+1 < asize) {
                if( A[i+1].second == lastfreq){
                    if(numsameline % 6 == 0){
                        fout << endl;
                    }
                    else{
                        fout << " ";
                    }
                }
                p = A[i+1];
            }
            i++;
        }
        fout << endl;

        cout << "freq = " << lastfreq << endl;
    }
    cout << "Finished printing" << endl;
}

int main(){
    ofstream fout ("contact.out");
    ifstream fin ("contact.in");
    fin >> A >> B >> N;

    string s;
    string data = "";
    
    while(fin >> s){
        data += s;
    }
    data.erase(remove(data.begin(), data.end(), '\n'), data.end());
    int datasize = data.size();

    set<int> freqs;
    for(int len = A; len <= B; len++){

        for(int i = 0; i <= datasize-len; i++){
            string sub = data.substr(i, len);

            bool toadd = true;
            if(len > A){
                string s1 = sub.substr(0, len-1);
                string s2 = sub.substr(1, len-1);
                int fr1 = M[s1];
                int fr2 = M[s2];
                int nthfreq = *freqs.begin();
                if(fr1 < nthfreq && fr2 < nthfreq){
                    toadd = false;
                    M.erase(s1);
                    M.erase(s2);
                }
                else if(fr1 < nthfreq){
                    M.erase(s1);
                }
                else if(fr2 < nthfreq){
                    M.erase(s2);
                }
            }

            if(toadd){
                M[sub] += 1;
            }
        }

        for(auto e : M){
            freqs.insert(e.second);
        }

        while(freqs.size() > N){
            freqs.erase(freqs.begin());
        }

        

    }

    sortnsolve(fout);
}