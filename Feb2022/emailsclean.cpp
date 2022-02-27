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
        set<pair<int, int>> pq;
        set<int> posOrder;
        vector<pair<int, int>> below;
        for(int j = 1; j <= N; j++){
            int f;
            cin >> f;
            folderCapacity[f]++;
            pair<int, int> p = {f, j};
            emails.push_back(p);
            posToEmail[j] = p;

            if(j <= K){
                pq.insert(p);
                posOrder.insert(j);
            }
            else{
                below.push_back(p);
            }
        }

        
        int fstart = 1;
        vector<pair<int, int>> above;
        map<int, bool> scrolledpast;
        int infolder[M+1];
        memset(infolder, 0, sizeof(infolder));
        int belowind = 0;

        int numfull = 0;

        while(numfull != M){
            if(infolder[fstart] == folderCapacity[fstart]){
                numfull++;
                if(numfull == M){
                    break;
                }
                fstart++;
            }
            else{
                pair<int, int> smallest = *pq.begin();
                int folder = smallest.first;
                if(!scrolledpast[smallest.second] && folder >= fstart && folder < fstart+K){   //!scrolledpast[smallest.second] && 
                    
                    infolder[folder]++;
                    scrolledpast[smallest.second] = true;
                    pq.erase(pq.begin());
                    posOrder.erase(smallest.second);

                    if(belowind == below.size()){
                        if(!above.empty()){
                            pq.insert(above[above.size()-1]);

                            posOrder.insert(above[above.size()-1].second);
                            scrolledpast[above[above.size()-1].second] = false;

                            above.pop_back();
 
                        }
                    }
                    else{
                        pq.insert(below[belowind]);
                        posOrder.insert(below[belowind].second);

                        belowind++;
                    }
                    
                }
                else{
                    if(belowind == below.size()){

                        break;
                    }
                    else{

                        int firstonscreen = *posOrder.begin();
                        above.push_back(posToEmail[firstonscreen]);
                        pq.erase(posToEmail[firstonscreen]);
                        scrolledpast[firstonscreen] = true;
                        
                        posOrder.erase(firstonscreen);
                        
                        if(belowind != below.size()){
                            pq.insert(below[belowind]);
                            posOrder.insert(below[belowind].second);
                            
                            belowind++;
                            
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