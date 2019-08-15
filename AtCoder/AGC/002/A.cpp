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
    int a, b; cin>>a>>b;
    if(a>0) cout << "Positive" << endl;
    else if(a<=0 && b>=0) cout << "Zero" << endl;
    else{
        if((b-a)%2==0) cout << "Negative" << endl;
        else cout << "Positive" << endl;
    }
}