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

    int m=n/2;
    if(n % 2 == 0) m--;

    int ans=0;
    for(int i=0; i<n; i++){
        if(i <= m){
            if(s[i] == 'p') ans--;
        }
        else{
            if(s[i] == 'g') ans++;
        }
    }
    cout << ans << endl;
}