vector<ll> divisor(ll n){
    vector<ll> v;
    for(ll i=1; i*i<=n; i++){
        if(n % i == 0){
            v.emplace_back(i);
            v.emplace_back(n / i);
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    return v;
}