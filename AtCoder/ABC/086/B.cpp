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
    string a, b; cin>>a>>b;
    string c=a+b;
    int n=stoi(c);
    for(int i=1; i<=1000; i++){
        if(n==i*i){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}