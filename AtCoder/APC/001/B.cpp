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
    int n; cin>>n;
    vector<int> a(n), b(n);
    ll asum=0, bsum=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        asum+=a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
        bsum+=b[i];
    }

    if(asum>bsum){
        cout << "No" << endl;
    }
    else{
        ll agap=0, bgap=0;
        for(int i=0; i<n; i++){
            if(a[i]<b[i]){
                agap+=(b[i]-a[i]+1)/2;
            }
            else if(a[i]>b[i]){
                bgap+=a[i]-b[i];
            }
        }

        if(agap<=bsum-asum && bgap<=bsum-asum){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}