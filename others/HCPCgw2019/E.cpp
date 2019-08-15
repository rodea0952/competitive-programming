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
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int main(){
    int n, u, v, m; cin>>n>>u>>v>>m;
    map<int, P> Uboard, Nboard;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int x; cin>>x;
            Uboard[x] = P(i, j);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int x; cin>>x;
            Nboard[x] = P(i, j);
        }
    }

    vector<int> Uh(n, n), Uw(n, n), Nh(n, n), Nw(n, n);
    int Ud1=n, Ud2=n, Nd1=n, Nd2=n;
    bool Uvalid=false, Nvalid=false;
    int Ucnt=0, Ncnt=0;
    vector<int> q(m);
    for(int i=0; i<m; i++) cin>>q[i];
    for(int i=0; i<m; i++){
        int x=q[i];
        auto itr = Uboard.find(x);
        if(itr != Uboard.end()){
            int cy = Uboard[x].fs;
            int cx = Uboard[x].sc;

            Uh[cx]--;
            if(Uh[cx] == 0) Ucnt++;
            Uw[cy]--;
            if(Uw[cy] == 0) Ucnt++;

            if(cy == cx){
                Ud1--;
                if(Ud1 == 0) Ucnt++;
            }
            if(cy == (n - 1 - cx)){
                Ud2--;
                if(Ud2 == 0) Ucnt++;
            }
        }

        itr = Nboard.find(x);
        if(itr != Nboard.end()){
            int cy = Nboard[x].fs;
            int cx = Nboard[x].sc;

            Nh[cx]--;
            if(Nh[cx] == 0) Ncnt++;
            Nw[cy]--;
            if(Nw[cy] == 0) Ncnt++;

            if(cy == cx){
                Nd1--;
                if(Nd1 == 0) Ncnt++;
            }
            if(cy == (n - 1 - cx)){
                Nd2--;
                if(Nd2 == 0) Ncnt++;
            }
        }

        if(n == 1){
            chmin(Ucnt, 1);
            chmin(Ncnt, 1);
        }

        if(u <= Ucnt){
            Uvalid = true;
        }
        if(v <= Ncnt){
            Nvalid = true;
        }

        if(Uvalid && Nvalid){
            cout << "DRAW" << endl;
            return 0;
        }
        if(Uvalid && !Nvalid){
            cout << "USAGI" << endl;
            return 0;
        }
        if(!Uvalid && Nvalid){
            cout << "NEKO" << endl;
            return 0;
        }
    }

    cout << "DRAW" << endl;
}