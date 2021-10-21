/*
ID: xckevin1
LANG: C++
TASK: maze1
*/

//shortest paths

#include <bits/stdc++.h>
using namespace std;

int w, h;
vector<int> exits;
int maxroomnum;

vector<pair<int, int>> adj[3801]; // get {b, w} from a
int dist[3801];
bool seen[3801];
priority_queue<pair<int, int>> q; // pair is {dist, node}

int resultscombined[3801];

void dijkstra(int i){
    fill(dist, dist+3801, 99999999);
    fill(seen, seen+3801, false);
    dist[i] = 1;
    q.push({0, i});

    while(!q.empty()){
        int a = q.top().second;
        q.pop();
        if(!seen[a]){
            seen[a] = true;
            for(pair<int, int> p : adj[a]){
                int b = p.first;
                int w = p.second;
                if(dist[a] + w < dist[b]){
                    dist[b] = dist[a] + w;
                    q.push({-1 * dist[b], b});
                }
            }
        }
    }
}

int main(){
    ofstream fout ("maze1.out");
    ifstream fin ("maze1.in");
    string l1;
    //getline(fin, l1);
    //w = stoi(l1.substr(0,1));
    //h = stoi(l1.substr(2,1));
    fin >> w >> h;
    getline(fin, l1);
    maxroomnum = w*h - 1;

    for(int i = 0; i < (2*h +1); i++){
        string ln;
        getline(fin, ln);

        int row = (i-1) / 2;

        for(int j = 0; j < (2*w +1); j++){
            
            int col = (j-1) / 2;
            int roomnum = (row * w) + col;
            
            if(ln[j] == ' '){
                if(i % 2 == 0){
                    if(i == 0){
                        exits.push_back(roomnum);
                        //cout << "exit: " << roomnum << endl;
                    }
                    else if(i == 2*h){
                        exits.push_back(roomnum);
                        //cout << "exit: " << roomnum << endl;
                    }
                    else{
                        adj[roomnum].push_back({roomnum + w, 1});
                        adj[roomnum+w].push_back({roomnum, 1});
                        //cout << "connecting " << roomnum << " and " << roomnum+w
                    }
                }
                else{
                    if(j % 2 == 0){
                        if(j == 0){
                            exits.push_back(roomnum);
                            //cout << "exit: " << roomnum << endl;
                        }
                        else if(j == 2*w){
                            exits.push_back(roomnum);
                            //cout << "exit: " << roomnum << endl;
                        }
                        else{
                            adj[roomnum].push_back({roomnum + 1, 1});
                            adj[roomnum+1].push_back({roomnum, 1});
                            
                        }
                    }
                }
            }
        }
        //cout << endl;
    }


   fill(resultscombined, resultscombined+3801, 99999999);

    for(int e : exits){
        dijkstra(e);
        for(int j = 0; j <= maxroomnum; j++){
            resultscombined[j] = min(resultscombined[j], dist[j]);
        }
    }

    int longest = 0;
    for(int i = 0; i <= maxroomnum; i++){
        longest = max(longest, resultscombined[i]);
    }

    fout << longest << endl;
}