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
    int scnt=0, ans=0;
    for(int i=0; i<n; i++){
        if(s[i]=='S') scnt++;
        if(scnt>0 && s[i]=='T'){
            scnt--;
            ans++;
        }
    }
    cout << n-ans*2 << endl;
}