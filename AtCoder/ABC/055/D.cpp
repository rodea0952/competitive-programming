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

template <typename T> inline string toString(const T &a){ostringstream oss; oss<<a; return oss.str();};

int main(){
    int n; cin>>n;
    string s; cin>>s;

    for(int bit=0; bit<(1<<2); bit++){
        string ans(n+10, 'a');

        if(bit & 1) ans[0]='W';
        else ans[0]='S';

        if(bit & 2) ans[1]='W';
        else ans[1]='S';

        for(int i=1; i<n-1; i++){
            if(ans[i]=='W' && s[i]=='o'){
                if(ans[i-1]=='W') ans[i+1]='S';
                else ans[i+1]='W';
            }
            else if(ans[i]=='W' && s[i]=='x'){
                if(ans[i-1]=='W') ans[i+1]='W';
                else ans[i+1]='S';
            }
            else if(ans[i]=='S' && s[i]=='o'){
                if(ans[i-1]=='W') ans[i+1]='W';
                else ans[i+1]='S';
            }
            else{
                if(ans[i-1]=='W') ans[i+1]='S';
                else ans[i+1]='W';
            }
        }

        bool ispossible=true;
        if(ans[n-1]=='W' && s[n-1]=='o'){
            if(!(ans[n-2]!=ans[0])) ispossible=false;
        }
        else if(ans[n-1]=='W' && s[n-1]=='x'){
            if(!(ans[n-2]==ans[0])) ispossible=false;
        }
        else if(ans[n-1]=='S' && s[n-1]=='o'){
            if(!(ans[n-2]==ans[0])) ispossible=false;
        }
        else{
            if(!(ans[n-2]!=ans[0])) ispossible=false;
        }

        if(ans[0]=='W' && s[0]=='o'){
            if(!(ans[n-1]!=ans[1])) ispossible=false;
        }
        else if(ans[0]=='W' && s[0]=='x'){
            if(!(ans[n-1]==ans[1])) ispossible=false;
        }
        else if(ans[0]=='S' && s[0]=='o'){
            if(!(ans[n-1]==ans[1])) ispossible=false;
        }
        else{
            if(!(ans[n-1]!=ans[1])) ispossible=false;
        }

        if(ispossible){
            for(int i=0; i<n; i++){
                cout << ans[i];
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}