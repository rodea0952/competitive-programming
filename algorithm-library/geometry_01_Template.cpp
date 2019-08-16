#include <iostream>
#include <complex>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef complex<double> Point, Vector;
typedef pair<Point, Point> Segment, Line;
typedef vector<Point> Polygon;
typedef pair<Point, double> Circle;

#define X real()
#define Y imag()
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

const double pi = acos(-1);

// 角度 -> ラジアン
double torad(int deg){
    return 1. * deg * pi / 180;
}

// ラジアン -> 角度
double todeg(double ang){
    return ang * 180 / pi;
}

namespace std{
    bool operator<(const Point &a, const Point &b){
        return !equals(a.X, b.X) ? a.X < b.X : a.Y < b.Y;
    }

    bool cmp_y(const Point &a, const Point &b) {
        return !equals(a.Y, b.Y) ? a.Y < b.Y : a.X < b.X;
    }
}

double dot(Vector a, Vector b){
    return a.X * b.X + a.Y * b.Y;
}

double cross(Vector a, Vector b){
    return a.X * b.Y - a.Y * b.X;
}

double norm(Vector a){
    return a.X * a.X + a.Y * a.Y;
}

double abs(Vector a){
    return sqrt(norm(a));
}

// 直交判定
bool isOrthogonal(Vector a, Vector b){
    return equals(dot(a, b), 0);
}

// 平行判定
bool isParallel(Vector a, Vector b){
    return equals(cross(a, b), 0);
}

// 射影
Point project(Segment s, Point p){
    Vector base = s.second - s.first;
    double r = dot(p - s.first, base) / norm(base);
    return s.first + base * r;
}

// 反射
Point reflect(Segment s, Point p){
    return p + (project(s, p) - p) * 2.0;
}

// ベクトルと点の位置関係
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw(Point p0, Point p1, Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a, b) > EPS) return COUNTER_CLOCKWISE;
    if(cross(a, b) < -EPS) return CLOCKWISE;
    if(dot(a, b) < -EPS) return ONLINE_BACK;
    if(norm(a) < norm(b)) return ONLINE_FRONT;

    return ON_SEGMENT;
}

// 線分の交差判定
bool intersect(Point p1, Point p2, Point p3, Point p4){
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool intersect(Segment s1, Segment s2){
    return intersect(s1.first, s1.second, s2.first, s2.second);
}

// 線分と線分の交点
Point getCrossPointSS(Segment s1, Segment s2){
    Vector base = s2.second - s2.first;
    double d1 = abs(cross(base, s1.first - s2.first));
    double d2 = abs(cross(base, s1.second - s2.first));
    double t = d1 / (d1 + d2);
    return s1.first + (s1.second - s1.first) * t;
}

// 直線と直線の交点
Point getCrossPointLL(Line l1, Line l2){
    double a = cross(l1.second - l1.first, l2.second - l2.first);
    double b = cross(l1.second - l1.first, l1.second - l2.first);
    if(abs(a) < EPS && abs(b) < EPS) return l2.first;
    return l2.first + (l2.second - l2.first) * (b / a);
}

// 直線と点の距離
double getDistanceLP(Line l, Point p){
    return abs(cross(l.second - l.first, p - l.first) / abs(l.first - l.second));
}

// 線分と点の距離
double getDistanceSP(Segment s, Point p){
    if(dot(s.second - s.first, p - s.first) < 0.0) return abs(p - s.first);
    if(dot(s.first - s.second, p - s.second) < 0.0) return abs(p - s.second);
    return getDistanceLP(s, p);
}

// 線分と線分の距離
double getDistanceSS(Segment s1, Segment s2){
    if(intersect(s1, s2)) return 0.0;
    return min({getDistanceSP(s1, s2.first), getDistanceSP(s1, s2.second), getDistanceSP(s2, s1.first), getDistanceSP(s2, s1.second)});
}

// 多角形の面積
double convexArea(Polygon pol){
    int n = pol.size();
    double S = 0;
    for(int i=0; i<n; i++){
        S += cross(pol[i], pol[(i+1)%n]);
    }

    return S / 2;
}

// 凸多角形かどうか
bool isConvex(Polygon pol){
    int n = pol.size();

    for(int i=0; i<n; i++){
        if(ccw(pol[i], pol[(i+1)%n], pol[(i+2)%n]) == CLOCKWISE){
            return false;
        }
    }

    return true;
}

// IN := 2, ON := 1, OUT := 0
// 点の内包
int contains(Polygon g, Point p){
    int n = g.size();
    bool x = false;
    for(int i=0; i<n; i++){
        Point a = g[i] - p;
        Point b = g[(i + 1) % n] - p;
        if(abs(cross(a, b)) < EPS && dot(a, b) < EPS) return 1;
        if(a.Y > b.Y) swap(a, b);
        if(a.Y < EPS && EPS < b.Y && cross(a, b) > EPS) x = !x;
    }

    return (x ? 2 : 0);
}

// 凸包
Polygon andrewScan(Polygon s){
    Polygon u, l;
    if(s.size() < 3) return s;
    sort(s.begin(), s.end());

    u.emplace_back(s[0]);
    u.emplace_back(s[1]);

    l.emplace_back(s[s.size() - 1]);
    l.emplace_back(s[s.size() - 2]);

    // 凸包の上部を生成
    for(int i=2; i<s.size(); i++){
        for(int n=u.size(); n>=2 && ccw(u[n-2], u[n-1], s[i]) == COUNTER_CLOCKWISE; n--){
            u.pop_back();
        }
        
        u.emplace_back(s[i]);
    }

    for(int i=s.size()-3; i>=0; i--){
        for(int n=l.size(); n>=2 && ccw(l[n-2], l[n-1], s[i]) == COUNTER_CLOCKWISE; n--){
            l.pop_back();
        }

        l.emplace_back(s[i]);
    }

    reverse(l.begin(), l.end());
    
    for(int i=u.size()-2; i>=1; i--){
        l.emplace_back(u[i]);
    }

    return l;
}

// 凸包
Polygon convexHull(Polygon ps){
    int n = ps.size();
    sort(ps.begin(), ps.end(), cmp_y);
    int k = 0;
    Polygon convex(n * 2);
    for(int i=0; i<n; i++){
        while(k >= 2 && ccw(convex[k-2], convex[k-1], ps[i]) == CLOCKWISE) k--;
        convex[k++] = ps[i];
    }
    for(int i=n-2, t=k; i>=0; i--){
        while(k > t && ccw(convex[k-2], convex[k-1], ps[i]) == CLOCKWISE) k--;
        convex[k++] = ps[i];
    }
    convex.resize(k-1);
    return convex;
}

// 凸多角形の直径
double convexDiameter(Polygon pol){
    int n = pol.size();
    if(n <= 1) return 0;
    if(n == 2) return abs(pol[0] - pol[1]);

    int i = 0, j = 0;
    for(int k=0; k<n; k++){
        if(!(pol[i] < pol[k])) i = k;
        if(pol[j] < pol[k]) j = k;
    }

    double diameter = 0;
    int si = i, sj = j;
    while(i != sj || j != si){
        diameter = max(diameter, abs(pol[i] - pol[j]));
        if(cross(pol[(i+1)%n] - pol[i], pol[(j+1)%n] - pol[j]) < -EPS){
            i = (i + 1) % n;
        }
        else{
            j = (j + 1) % n;
        }
    }

    return diameter;
}

// 凸多角形を直線で切断したときの左側の凸多角形
Polygon convexCut(Polygon pol, Line l){
    Polygon q;
    int n = pol.size();
    for(int i=0; i<n; i++){
        Point a = pol[i];
        Point b = pol[(i+1)%n];
        if(ccw(l.first, l.second, a) != CLOCKWISE) q.emplace_back(a);
        if(ccw(l.first, l.second, a) * ccw(l.first, l.second, b) < 0){
            q.emplace_back(getCrossPointLL(Line(a, b), l));
        }
    }

    return q;
}

// 平面走査による線分交差
#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3

struct EndPoint{
    Point p;
    int seg, st; // 入力線分のID, 端点の種類
    EndPoint() {}
    EndPoint(Point p, int seg, int st): p(p), seg(seg), st(st) {}

    bool operator < (const EndPoint &ep) const{
        // y 座標が小さい順に整列
        if(p.Y == ep.p.Y){
            // y が同一の場合は、下端点、左端点、右端点、上端点の順に並べる
            return st < ep.st;
        }
        else{
            return p.Y < ep.p.Y;
        }
    }
};

// 端点のリスト
EndPoint EP[2 * 100000];

// 線分交差問題: マンハッタン幾何
int manhattanIntersection(vector<Segment> S){
    int n = S.size();

    for(int i=0, k=0; i<n; i++){
        // 端点 p1, p2 が左下を基準に並ぶように調整
        if(S[i].first.Y == S[i].second.Y){
            if(S[i].first.X > S[i].second.X){
                swap(S[i].first, S[i].second);
            }
        }
        else if(S[i].first.Y > S[i].second.Y){
            swap(S[i].first, S[i].second);
        }

        if(S[i].first.Y == S[i].second.Y){
            // 水平線分を端点リストに追加
            EP[k++] = EndPoint(S[i].first, i, LEFT);
            EP[k++] = EndPoint(S[i].second, i, RIGHT);
        }
        else{
            EP[k++] = EndPoint(S[i].first, i, BOTTOM);
            EP[k++] = EndPoint(S[i].second, i, TOP);
        }
    }

    // 端点の y 座標に関して昇順に整列
    sort(EP, EP + (2 * n));

    set<int> BT;
    BT.insert(1000000001);
    int cnt = 0;

    for(int i=0; i<2*n; i++){
        if(EP[i].st == TOP){
            // 上端点を削除
            BT.erase(EP[i].p.X);
        }
        else if(EP[i].st == BOTTOM){
            // 下端点を追加
            BT.insert(EP[i].p.X);
        }
        else if(EP[i].st == LEFT){
            set<int>::iterator b = BT.lower_bound(S[EP[i].seg].first.X);
            set<int>::iterator e = BT.upper_bound(S[EP[i].seg].second.X);
            cnt += distance(b, e);
        }
    }

    return cnt;
}

// 円と円の関係（共通接線数）
int intersection(Circle c1, Circle c2){
    double dist = abs(c1.first - c2.first);
    if(c1.second + c2.second < dist) return 4;
    if(equals(c1.second + c2.second, dist)) return 3;
    if(abs(c1.second - c2.second) < dist && dist < c1.second + c2.second) return 2;
    if(equals(abs(c1.second - c2.second), dist)) return 1;
    else return 0;
}

// 円と直線の交点
pair<Point, Point> getCrossPoints(Circle c, Line l){
    Vector pr = project(l, c.first);
    Vector e = (l.second - l.first) / abs(l.second - l.first);

    if(equals(getDistanceLP(l, c.first), c.second)){
        return make_pair(pr, pr);
    }

    double base = sqrt(c.second * c.second - norm(pr - c.first));
    return make_pair(pr - e * base, pr + e * base);
}

// 円の交点
// ラジアン
double arg(Vector p){
    return atan2(p.Y, p.X);
}

Vector polar(double a, double r){
    return Point(cos(r) * a, sin(r) * a);
}

pair<Point, Point> getCrossPoints(Circle c1, Circle c2){
    double d = abs(c1.first - c2.first);
    double a = acos((c1.second * c1.second + d * d - c2.second * c2.second) / (2 * c1.second * d));
    double t = arg(c2.first - c1.first);
    return make_pair(c1.first + polar(c1.second, t + a), c1.first + polar(c1.second, t - a));
}

// 点 p を通る円 c の接線
pair<Point, Point> getTangents(Circle c1, Point p1){
    Circle c2 = Circle(p1, sqrt(norm(c1.first - p1) - c1.second * c1.second));
    pair<Point, Point> p2 = getCrossPoints(c1, c2);
    if(p2.second < p2.first) swap(p2.first, p2.second);
    return p2;
}

// 共通接線
vector<Line> tangent(Circle c1, Circle c2){
    vector<Line> l1;
    if(c1.second < c2.second) swap(c1, c2);
    double g = norm(c1.first - c2.first);
    if(equals(g, 0)) return l1;
    Point u = (c2.first - c1.first) / sqrt(g);
    Point v = {-u.Y, u.X};

    for(int i=1; i>=-1; i-=2){
        double h = (c1.second + i * c2.second) / sqrt(g);

        if(equals(1 - h * h, 0)){
            l1.emplace_back(c1.first + u * c1.second, c1.first + (u + v) * c1.second);
        }
        else if(1 - h * h > EPS){
            Point uu = u * h;
            Point vv = v * sqrt(1 - h * h);
            l1.emplace_back(c1.first + (uu + vv) * c1.second, c2.first - (uu + vv) * c2.second * Point(i, i));
            l1.emplace_back(c1.first + (uu - vv) * c1.second, c2.first - (uu - vv) * c2.second * Point(i, i));
        }
    }

    return l1;
}

// 円と多角形の共通面積
double areaCP(Circle c, Polygon pol){
    double S = 0;
    double r = c.second;
    int n = pol.size();
    for(int i=0; i<n; i++){
        pol[i] -= c.first;
    }

    for(int i=0; i<n; i++){
        if(abs(pol[i] * pol[(i+1)%n]) < EPS) continue;
        double d = arg(pol[(i+1)%n] / pol[i]);
        S += r * r * d / 2.0;

        if(getDistanceSP(Segment(pol[i], pol[(i+1)%n]), Point(0, 0)) < r - EPS){
            pair<Point, Point> cps = getCrossPoints(Circle(Point(0, 0), r), Line(pol[i], pol[(i+1)%n]));
            Point a, b;
            if(ccw(pol[i], pol[(i+1)%n], cps.first) == 0 && ccw(pol[i], pol[(i+1)%n], cps.second) == 0){
                a = cps.first, b = cps.second;
            }
            else if(!ccw(pol[i], pol[(i+1)%n], cps.first)){
                a = cps.first, b = pol[(i+1)%n];
            }
            else if(!ccw(pol[i], pol[(i+1)%n], cps.second)){
                a = pol[i], b = cps.second;
            }
            else{
                a = pol[i], b = pol[(i+1)%n];
            }

            if(abs(a * b) < EPS) continue;
            d = arg(b / a);
            S += cross(a, b) / 2.0 - r * r * d / 2.0;
        }
    }

    return S;
}

// n 個の点について、最も近い 2 点の距離を求める
double closestPair(vector<Point> &points, int l, int r){
    if(r - l <= 1) return 1e100;
    int mid = (l + r) / 2;
    double x = points[mid].X;
    double d = min(closestPair(points, l, mid), closestPair(points, mid, r));
    auto iti = points.begin();
    auto itl = iti + l;
    auto itm = iti + mid;
    auto itr = iti + r;

    inplace_merge(itl, itm, itr, cmp_y);

    vector<Point> nearLine;
    for(int i=l; i<r; i++){
        if(abs(points[i].X - x) >= d) continue;

        int sz = nearLine.size();
        for(int j=sz-1; j>=0; j--){
            double dx = points[i].X - nearLine[j].X;
            double dy = points[i].Y - nearLine[j].Y;
            if(dy >= d) break;
            d = min(d, sqrt(dx * dx + dy * dy));
        }

        nearLine.emplace_back(points[i]);
    }
    
    return d;
}