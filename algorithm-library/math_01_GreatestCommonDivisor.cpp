// lcm(x, y) = x * y / gcd(x, y)
int gcd(int x, int y){
    if(y == 0) return x;
    else return gcd(y, x % y);
}

// {g, x, y} : a x + b y = g
tuple<ll, ll, ll> extgcd(ll a, ll b){
    if(b == 0) return {a, 1, 0};
    ll g, x, y; tie(g, x, y) = extgcd(b, a % b);
    return {g, y, x - a / b * y};
}