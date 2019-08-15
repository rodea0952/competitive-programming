#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n, t; cin>>n>>t;
    int a[n+10];
    for(int i=0; i<n; i++) cin>>a[i];

    int MIN=MOD, gap_max=0;
    for(int i=0; i<n; i++){
        MIN=min(MIN, a[i]);
        gap_max=max(gap_max, a[i]-MIN);
    }
    
    MIN=MOD;
    int ans=0;
    for(int i=0; i<n; i++){
        MIN=min(MIN, a[i]);

        if(a[i]-MIN == gap_max){
            ans++;
            MIN=MOD;
        }
    }
    cout << ans << endl;
}