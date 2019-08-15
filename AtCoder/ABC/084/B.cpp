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
    int a, b; cin>>a>>b;
    string s; cin>>s;
    bool canans=true;
    for(int i=0; i<s.size(); i++){
        if(i==a){
            if(s[i]!='-') canans=false;
        }
        else{
            if(isdigit(s[i])==0) canans=false;
        }
    }

    if(canans) cout << "Yes" << endl;
    else cout << "No" << endl;
}