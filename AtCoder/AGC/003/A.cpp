#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    string s; cin>>s;
    int n=s.size();
    int ncnt=0, wcnt=0, scnt=0, ecnt=0;
    for(int i=0; i<n; i++){
        if(s[i]=='N') ncnt++;
        else if(s[i]=='W') wcnt++;
        else if(s[i]=='S') scnt++;
        else ecnt++;
    }

    bool home;
    if(ncnt>0 && wcnt>0 && scnt>0 && ecnt>0) home=true;
    else if(wcnt==0 && ecnt==0 && ncnt>0 && scnt>0) home=true;
    else if(wcnt>0 && ecnt>0 && ncnt==0 && scnt==0) home=true;
    else home=false;

    if(home) cout << "Yes" << endl;
    else cout << "No" << endl;
}