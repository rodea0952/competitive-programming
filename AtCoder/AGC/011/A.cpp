#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n, c, k; cin>>n>>c>>k;
    vector<int> bus(100010, 0), t(n);
    for(int i=0; i<n; i++) cin>>t[i];
    sort(t.begin(), t.end());
    int cnt=0, cur=t[0], ans=1;
    for(int i=0; i<n; i++){
        if(cur+k<t[i] || c==cnt){
            cnt=1;
            ans++;
            cur=t[i];
        }
        else cnt++;
    }
    cout << ans << endl;
}
