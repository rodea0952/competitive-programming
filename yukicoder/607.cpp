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
    int n, m; cin>>n>>m;
    vector<int> a(n), train(n, 0);
    bool just777=false;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>a[j];
            train[j]+=a[j];
        }

        int l=0, r=0, sum=0;
        while(r<n){
            sum+=train[r];
            while(777<sum && l<n){
                sum-=train[l];
                l++;
            }
            r++;
            if(sum==777) just777=true;
        }
    }

    if(just777) cout << "YES" << endl;
    else cout << "NO" << endl;
}