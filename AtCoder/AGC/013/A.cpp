#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    int ans=0, i=0;
    while(i<n){
        if(i==n-1){
            ans++;
            break;
        }

        if(a[i]==a[i+1]){
            i++;
            continue;
        }

        while(a[i]<=a[i+1] && i<n-1){
            i++;
            if(a[i]>a[i+1]){
                i++;
                ans++;
                goto END;
            }
        }

        while(a[i]>=a[i+1] && i<n-1){
            i++;
            if(a[i]<a[i+1]){
                i++;
                ans++;
                break;
            }
        }
        END:;
    }
    cout << ans << endl;
}