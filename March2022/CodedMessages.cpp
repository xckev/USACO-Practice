#include <bits/stdc++.h>
using namespace std;

string s;
string t;
int Q;

map<char, int> lettercountsS;
map<char, int> lettercountsT;

int lastseenS[100000][18]; 
int lastseenT[100000][18];

bool works[19*18];

int chartoint(char c){
    return (int)(c - 'a');
}
char inttochar(int i){
    return (char)('a' + i);
}

int main(){
    cin >> s;
    cin >> t;
    cin >> Q;

    memset(lastseenS, -1, sizeof(lastseenS));
    memset(lastseenT, -1, sizeof(lastseenT));

    int lastind = s.size()-1;
    int last = chartoint(s[lastind]);
    lettercountsS[s[lastind]] += 1;
    for(int i = s.size()-2; i >= 0; i--){
        lettercountsS[s[i]] += 1;
        for(int j = 0; j < 18; j++){
            lastseenS[i][j] = lastseenS[i+1][j];
        }
        lastseenS[i][last] = lastind;
        last = chartoint(s[i]);
        lastind = i;
    }

    lastind = t.size()-1;
    last = chartoint(t[lastind]);
    lettercountsT[t[lastind]] += 1;
    for(int i = t.size()-2; i >= 0; i--){
        lettercountsT[t[i]] += 1;
        for(int j = 0; j < 18; j++){
            lastseenT[i][j] = lastseenT[i+1][j];
        }
        lastseenT[i][last] = lastind;
        last = chartoint(t[i]);
        lastind = i;
    }
    
    /*
    for(int i = 0; i < s.size(); i++){
        cout << "for character " << inttochar(i) << " at position " << i << ": " << endl;
        for(int j = 0; j < 18; j++){
            cout << "next " << inttochar(j) << " at " << lastseenS[i][j] << endl;
        }
        cout << "-------------" << endl
    }*/
    
    //cout << chartoint('r') << endl;
    
    

    for(int i = 0; i < 18; i++){
        for(int j = i+1; j < 18; j++){
            
            char c1 = inttochar(i);
            char c2 = inttochar(j);

            string sres = "";
            if(s[0] == c1 || s[0] == c2){
                sres += s[0];
            }
            int currlet = 0;
            while(lastseenS[currlet][i] != -1 || lastseenS[currlet][j] != -1){
                int ipos = lastseenS[currlet][i];
                int jpos = lastseenS[currlet][j];
                int next;
                if(ipos == -1){
                    next = jpos;
                }
                else if(jpos == -1){
                    next = ipos;
                }
                else{
                    next = min(ipos, jpos);
                }
                sres += s[next];

                currlet = next;
            }

            string tres = "";
            if(t[0] == c1 || t[0] == c2){
                tres += t[0];
            }
            currlet = 0;
            while(lastseenT[currlet][i] != -1 || lastseenT[currlet][j] != -1){
                int ipos = lastseenT[currlet][i];
                int jpos = lastseenT[currlet][j];

                int next;
                if(ipos == -1){
                    next = jpos;
                }
                else if(jpos == -1){
                    next = ipos;
                }
                else{
                    next = min(ipos, jpos);
                }
                tres += t[next];

                currlet = next;
            }

            //cout << "sres was: " << sres << "  ||  tres was: " << tres << endl;
            if(sres == tres){
                //cout << c1 << c2 << ": " << " TRUE" << endl;
                works[i*18 + j] = true;
            }
            else{
                //cout << c1 << c2 << ": " << " false" << endl;
                works[i*18 + j] = false;
            }
        }
    }
    
    //cout << "here2" << endl;
    
    string ans = "";
    for(int i = 0; i < Q; i++){
        string query;
        cin >> query;
        int len = query.size();

        bool good = true;
        if(len == 1){
            good = (lettercountsS[query[0]] == lettercountsT[query[0]]);
        }
        else{
            
            for(int i = 0; i < len; i++){
                for(int j = i+1; j < len; j++){
                    int c1 = chartoint(query[i]);
                    int c2 = chartoint(query[j]);

                    if(works[c1*18 + c2] == false){
                        good = false;
                        break;
                    }
                }
                if(!good){
                    break;
                }
            }
        }

        if(good){
            ans += "Y";
        }
        else{
            ans += "N";
        }
    }

    cout << ans << endl;
}