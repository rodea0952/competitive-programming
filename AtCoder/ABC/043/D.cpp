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

    for(int i=0; i+1<n; i++){
        if(s[i] == s[i+1]){
            cout << i+1 << " " << i+2 << endl;
            return 0;
        }
    }

    for(int i=0; i+2<n; i++){
        if(s[i] == s[i+2]){
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }

    cout << -1 << " " << -1 << endl;
}