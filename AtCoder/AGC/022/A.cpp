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

    for(char cha='a'; cha<='z'; cha++){
        bool f=false;
        for(int i=0; i<n; i++){
            if(s[i]==cha) f=true;
        }

        if(!f){
            cout << s << cha << endl;
            return 0;
        }
    }

    int m;
    char tail='0';
    for(int i=n-1; i>0; i--){
        if(s[i-1]<s[i]){
            tail=s[i-1];
            m=i;
            break;
        }
    }

    if(tail=='0'){
        cout << -1 << endl;
        return 0;
    }

    char change='z';
    for(int i=n-1; i>=m; i--){
        if(tail<s[i] && s[i]<change) change=s[i];
    }

    for(int i=0; i<m-1; i++){
        cout << s[i];
    }
    cout << change << endl;
}