#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    string s; cin>>s;
    int n=s.size();
    int ans=1e9;
    for(char cha='a'; cha<='z'; cha++){
        string t=cha+s+cha;
        int maxgap=0, pid=0;
        for(int i=1; i<n+2; i++){
            if(t[i]==cha){
                maxgap=max(maxgap, i-pid-1);
                pid=i;
            }
        }
        ans=min(ans, maxgap);
    }
    cout << ans << endl;
}