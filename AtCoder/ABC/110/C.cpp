#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    string s, t; cin>>s>>t;
    int n=s.size();
    for(char cha='a'; cha<='z'; cha++){
        bool flag=false;
        char cur;
        for(int i=0; i<n; i++){
            if(s[i] == cha){
                if(!flag){ // first
                    cur=t[i];
                    flag=true;
                    continue;
                }
                if(flag){ // not first
                    if(t[i] != cur){
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    for(char cha='a'; cha<='z'; cha++){
        char cur;
        bool flag=false;
        for(int i=0; i<n; i++){
            if(t[i] == cha){
                if(!flag){ // first
                    cur=s[i];
                    flag=true;
                }
                if(flag){ // not first
                    if(s[i] != cur){
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Yes" << endl;
}
