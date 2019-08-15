#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c; cin>>a>>b>>c;

    int odd = 0;
    odd += a % 2;
    odd += b % 2;
    odd += c % 2;

    cout << (2 <= odd ? "Hom" : "Tem") << endl;
}