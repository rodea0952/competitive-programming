#include <bits/stdc++.h>
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

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n; cin>>n;
    vector<int> a(n);
    map<int, int> mp;
    for(int i=0; i<n; i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    sort(a.begin(), a.end(), greater<int>());

    int ans=0;
    for(int i=0; i<n; i++){
        for(ll num=2; num<=1e18; num*=2){
            if(num/2<=(ll)a[i] && (ll)a[i]<num){
                int x=num-a[i];

                if(a[i]==x){
                    if(1<mp[a[i]]){
                        mp[a[i]]-=2;
                        ans++;
                    }
                }
                else if(mp[a[i]] && mp[x]){
                    mp[a[i]]--;
                    mp[x]--;
                    ans++;
                }
                break;
            }
        }
    }
    cout << ans << endl;
}