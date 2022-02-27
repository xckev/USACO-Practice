#include <bits/stdc++.h>
using namespace std;

int T;

int main(){
    cin >> T;

    for(int i = 0; i < T; i++){
        int M, N, K;
        cin >> M >> N >> K;

        int folderCapacity[M+1];
        memset(folderCapacity, 0, sizeof(folderCapacity));
        vector<pair<int, int>> emails; //<folder, pos>
        map<int, pair<int, int>> posToEmail;
        priority_queue<pair<int, int>> pq;
        set<int> posOrder;
        vector<pair<int, int>> below;
        for(int j = 1; j <= N; j++){
            int f;
            cin >> f;
            folderCapacity[f]++;
            pair<int, int> p = {-1 * f, j};
            emails.push_back(p);
            posToEmail[j] = p;

            if(j <= K){
                pq.push(p);
                posOrder.insert(j);
            }
            else{
                below.push_back(p);
            }
        }

        cout << "finished reading input." << endl;
        cout << "all emails: ";
        for(auto p : emails){
            cout << "(" << p.first << ", " << p.second << ") " ;
        }
        cout << "all emails mapped from pos: ";
        for(auto p : posToEmail){
            cout << "(" << p.first << ", " << "(" << p.second.first << ", " << p.second.second << ")" << ") " ;
        }
        cout << endl;
        cout << "all emails ON SCREEN initially: ";
        for(int pos : posOrder){
            auto p = posToEmail[pos];
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
        cout << "all emails BELOW SCREEN initially: ";
        for(auto p : below){
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;

        cout << "all folder capacities: ";
        for(int h = 1; h <= M; h++){
            cout << "folder " << h << " has capacity " << folderCapacity[h];
            cout << endl;
        }
        
        
        int fstart = 1;
        //int estart = 1; int eend = 1+K;
        //cout << "estart: " << estart << " | eend: " << eend << endl; 
        vector<pair<int, int>> above;
        map<int, bool> scrolledpast;
        int infolder[M];
        memset(infolder, 0, sizeof(infolder));
        int belowind = 0;

        int numfull = 0;

        bool possible = true;
        while(numfull != M){
            cout << "! size of pq: " << pq.size() << endl;
            if(infolder[fstart] == folderCapacity[fstart]){
                cout << "top folder " << fstart << " filled. " << endl;
                numfull++;
                cout << "NumFull: " << numfull << endl;
                if(numfull == M){
                    break;
                }
                fstart++;
                cout << "scrolled folders down so that folder " << fstart << " is first" << endl;
            }
            else{
                pair<int, int> smallest = pq.top();
                int folder = -1 * smallest.first;
                if(!scrolledpast[smallest.second] && folder >= fstart && folder < fstart+K){   //!scrolledpast[smallest.second] && 
                    cout << "smallest fileable email is (" << smallest.first << ", " << smallest.second << ")" << endl;
                    //if(smallest.second == estart){
                    //    posOrder.erase(smallest.second);
                    //    estart = *posOrder.begin();
                    //    cout << "estart updated to: " << estart << endl;
                    //}
                    infolder[folder]++;
                    cout << "email added and folder number " << folder << " size  updated to: " << infolder[folder] << endl;
                    scrolledpast[smallest.second] = true;
                    pq.pop();
                    cout << "size of pq AFTER POPPING: " << pq.size() << endl;
                    posOrder.erase(smallest.second);
                    cout << "all emails ON SCREEN now: ";
                    for(int pos : posOrder){
                        auto p = posToEmail[pos];
                        cout << "(" << p.first << ", " << p.second << ") ";
                    }
                    cout << endl;

                    if(belowind == below.size()){
                        cout << "no more emails below to shift up" << endl;
                        if(!above.empty()){
                            cout << "moving email down from above" << endl;
                            pq.push(above[above.size()-1]);
                            //estart = above[above.size()-1].second;
                            //cout << "estart updated to: " << estart << endl;
                            posOrder.insert(above[above.size()-1].second);
                            scrolledpast[above[above.size()-1].second] = false;
                            cout << "moved down email (" << above[above.size()-1].first << ", " << above[above.size()-1].second << ")" << endl;
                            cout << "size of pq: " << pq.size() << endl;
                            above.pop_back();
                            cout << "all emails ABOVE SCREEN now: ";
                            for(auto p : above){
                                cout << "(" << p.first << ", " << p.second << ") ";
                            }
                            cout << endl;
                            cout << "all emails ON SCREEN now: ";
                            for(int pos : posOrder){
                                auto p = posToEmail[pos];
                                cout << "(" << p.first << ", " << p.second << ") ";
                            }
                            cout << endl;
                            cout << "all emails scrolled past: ";
                            for(auto p : scrolledpast){
                                cout << "(" << p.first << ", " << p.second << ") ";
                            }
                            cout << endl;
                        }
                    }
                    else{
                        cout << "shifting email (" << below[belowind].first << ", " << below[belowind].second << ") up from below" << endl;
                        pq.push(below[belowind]);
                        posOrder.insert(below[belowind].second);
                        //estart = *posOrder.begin();
                        //cout << "estart updated to: " << estart << endl;
                        //eend = below[belowind].second;
                        //cout << "eend updated to: " << eend << endl;
                        belowind++;
                        cout << "all emails ON SCREEN now: ";
                        for(int pos : posOrder){
                            auto p = posToEmail[pos];
                            cout << "(" << p.first << ", " << p.second << ") ";
                        }
                        cout << endl;
                        cout << "all emails BELOW SCREEN now: ";
                        for(int h = belowind; h < below.size(); h++){
                            auto p = below[h];
                            cout << "(" << p.first << ", " << p.second << ") ";
                        }
                        cout << endl;
                    }
                    
                }
                else{
                    if(belowind == below.size()){
                        cout << "I should have filed (" << pq.top().first << ", " << pq.top().second << ")" << endl;
                        cout << "IMPOSSIBLE: cannot scroll anymore" << endl;
                        possible = false;
                        break;
                    }
                    else{
                        //scroll down
                        cout << "no emails to file so we scroll down" << endl;
                        int firstonscreen = *posOrder.begin();
                        above.push_back(posToEmail[firstonscreen]);
                        cout << "shifting up email (" << posToEmail[firstonscreen].first << ", " << posToEmail[firstonscreen].second << ")" << endl;
                        scrolledpast[firstonscreen] = true;
                        cout << "all emails scrolled past: ";
                        for(auto p : scrolledpast){
                            cout << "(" << p.first << ", " << p.second << ") ";
                        }
                        posOrder.erase(firstonscreen);
                        //estart = *posOrder.begin();
                        //cout << "estart updated to: " << estart << endl;
                        cout << "all emails ON SCREEN now: ";
                        for(int pos : posOrder){
                            auto p = posToEmail[pos];
                            cout << "(" << p.first << ", " << p.second << ") ";
                        }

                        if(belowind != below.size()){
                            pq.push(below[belowind]);
                            cout << "shifting email (" << below[belowind].first << ", " << below[belowind].second << ") up from below" << endl;
                            posOrder.insert(below[belowind].second);
                            //eend = below[belowind].second;
                            //cout << "eend updated to: " << eend << endl;
                            belowind++;
                            cout << "all emails ON SCREEN now: ";
                            for(int pos : posOrder){
                                auto p = posToEmail[pos];
                                cout << "(" << p.first << ", " << p.second << ") ";
                            }
                            cout << "all emails BELOW SCREEN now: ";
                            for(int h = belowind; h < below.size(); h++){
                                auto p = below[h];
                                cout << "(" << p.first << ", " << p.second << ") ";
                            }
                            cout << endl;
                        }
                    }
                }
                

            }
        }

        if(numfull == M){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
}