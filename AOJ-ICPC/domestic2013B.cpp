#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> Pair;
typedef tuple<int, int, int> Tuple;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};
int dx2[]={1, 1, 0, -1, -1, -1, 0, 1};
int dy2[]={0, -1, -1, -1, 0, 1, 1, 1};

int main(){
    while(1){
        int M, T, P, R; cin>>M>>T>>P>>R;
        if(M==0 && T==0 && P==0 && R==0) return 0;

        // 0-indexed
        // Problem, Time, Team
        vector<Tuple> team(T);
        for(int i=0; i<T; i++){
            team[i]=Tuple(0, 0, i);
        }

        vector<vector<int>> penalty(T, vector<int>(P, 0));

        for(int i=0; i<R; i++){
            int m, t, p, j; cin>>m>>t>>p>>j;
            t--, p--;

            if(j==0){
                // correct
                get<0>(team[t])++;
                get<1>(team[t])+=m; get<1>(team[t])+=penalty[t][p];
            }
            else{
                penalty[t][p]+=20;
            }
        }

        vector<vector<Pair>> count(P+1);

        for(int i=0; i<T; i++){
            count[get<0>(team[i])].push_back(Pair(get<1>(team[i]), get<2>(team[i])));
        }

        for(int i=0; i<=P; i++){
            sort(count[i].begin(), count[i].end());
        }

        int CountTeam=0;
        for(int i=P; i>=0; i--){
            //cout << "ProblemNumber = " << i << endl; 
            for(int j=0; j<count[i].size(); j++){
                //cout << "Time = " << count[i][j].fs << " " << "Team = " << count[i][j].sc+1 << endl;
                
                vector<int> allsame;
                while(j+1<count[i].size() && count[i][j].fs==count[i][j+1].fs){
                    // same correct and same time
                    if(!allsame.size()) allsame.push_back(count[i][j].sc+1);
                    allsame.push_back(count[i][j+1].sc+1);
                    j++;
                }

                for(int k=allsame.size()-1; k>=0; k--){
                    if(k==0){
                        CountTeam++;
                        if(CountTeam==T) cout << allsame[k] << endl;
                        else cout << allsame[k] << ",";
                    }
                    else{
                        CountTeam++;
                        cout << allsame[k] << "=";
                    }
                }

                if(!allsame.size()){
                    CountTeam++;
                    if(CountTeam==T) cout << count[i][j].sc+1 << endl;
                    else cout << count[i][j].sc+1 << ",";
                }
                
            }
        }
    }
}