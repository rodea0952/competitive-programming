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

    if(n%2 == 0){
        for(int i=n/2; i<n; i++){
            if(s[n-i-1] != s[i]){
                cout << i << endl;
                return 0;
            }
        }
    }
    else{
        if(s[n/2] != s[n/2+1]){
            cout << n/2+1 << endl;
            return 0;
        }

        for(int i=n/2+1; i<n; i++){
            if(s[n-i-1] != s[i]){
                cout << i << endl;
                return 0;
            }
        }
    }

    for(int i=0; i<n-1; i++){
        if(s[i] != s[i+1]){
            cout << n-i-1 << endl;
            return 0;
        }
    }
    cout << n << endl;
}