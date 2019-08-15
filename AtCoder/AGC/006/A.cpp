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
    string s, t; cin>>s>>t;
    for(int i=0; i<n; i++){
        bool is_same=true;
        for(int j=i; j<n; j++){
            if(s[j]!=t[j-i]) is_same=false;
        }
        if(is_same){
            cout << 2*i+(n-i) << endl;
            return 0;
        }
    }
    cout << 2*n << endl;
}