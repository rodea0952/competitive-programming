#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int cnt = 0;
    bool valid = true;
    for(int i=0; i<n; i++){
        char p;
        int x;
        cin>>p>>x;
        if(p == '(') cnt += x;
        else cnt -= x;

        if(cnt < 0) valid = false;
    }

    if(!valid || cnt != 0){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}