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
    string s; cin>>s;
    int n=s.size();

    if(n%2==0){
        if(s[0]==s[n-1]) cout << "First" << endl;
        else cout << "Second" << endl;
    }
    else{
        if(s[0]==s[n-1]) cout << "Second" << endl;
        else cout << "First" << endl;
    }
}