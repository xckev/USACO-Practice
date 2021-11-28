/*
ID: xckevin1
LANG: C++
TASK: msquare
*/

#include <bits/stdc++.h>
using namespace std;

string goal = "";
map<string, string> config;
set<string> seen;

int main(){
    ofstream fout ("msquare.out");
    ifstream fin ("msquare.in");
    for(int i = 0; i < 8; i++){
        int e;
        fin >> e;
        goal += char('0' + (e - 0));
    }

    queue<string> q;
    q.push("12345678");
    seen.insert("12345678");
    config["12345678"] = "";

    while(!q.empty()){
        string s = q.front();
        q.pop();
        if(s == goal){
            break;
        }

        string next = s;
        reverse(next.begin(), next.end());
        if(seen.find(next) == seen.end()){
            seen.insert(next);
            config[next] = config[s] + "A";
            q.push(next);
        }


        next = s.substr(3,1) + s.substr(0,1) + s.substr(1,1) + s.substr(2,1) + s.substr(5,1) + s.substr(6,1) + s.substr(7,1) + s.substr(4,1);
        if(seen.find(next) == seen.end()){
            seen.insert(next);
            config[next] = config[s] + "B";
            q.push(next);
        }

        next = next = s.substr(0,1) + s.substr(6,1) + s.substr(1,1) + s.substr(3,1) + s.substr(4,1) + s.substr(2,1) + s.substr(5,1) + s.substr(7,1);
        if(seen.find(next) == seen.end()){
            seen.insert(next);
            config[next] = config[s] + "C";
            q.push(next);
        }
    }
    fout << config[goal].size() << endl;
    int num = 0;
    for(char ch : config[goal]){
        fout << ch;
        num++;
        if(num % 60 == 0){
            fout << endl;
        }
    }
    if(num % 60 != 0 || num == 0){
        fout << endl;
    }
}