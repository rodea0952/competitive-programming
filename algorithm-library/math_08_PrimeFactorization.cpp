vector<ll> prime_factorization(ll n){
    vector<ll> res;
    ll num = n;
    for(ll i=2; i*i<=n; i++){
        while(num % i == 0){
            num /= i;
            res.emplace_back(i);
        }
    }

    if(num != 1){
        res.emplace_back(num);
    }

    return res;
}