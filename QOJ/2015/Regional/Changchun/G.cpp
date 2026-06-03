#include <bits/stdc++.h>
using namespace std;
#define int long long

using ff = double;

constexpr ff eps = 1e-9;

constexpr ff inf = 1e18;

template <typename T>
int sgn(T x) {
    if constexpr (std::is_floating_point_v<T>) {
        if (std::abs(x) < eps) return 0;
        return x < 0 ? -1 : 1;
    } else {
        return (x > 0) - (x < 0); 
    }
}

template <class T> 
struct Point {
    T x, y;

    Point (T _x = 0, T _y = 0) : x(_x), y(_y) {}

    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y); 
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y); 
    }

    Point operator * (const T& v) const {
        return Point(x * v, y * v); 
    }

    Point operator / (const T& v) const {
        return Point(x / v, y / v); 
    }

    T dot (const Point& p) const {
        return x * p.x + y * p.y; 
    }

    T cross (const Point& p) const {
        return x * p.y - y * p.x; 
    }

    T operator * (const Point& p) const {
        return dot(p); 
    }

    T operator ^ (const Point& p) const {
        return cross(p); 
    }

    // 向量长度的平方，避免开根号，常用于比较距离
    T len2() const {
        return x * x + y * y; 
    }

    // 向量长度，返回 double
    ff len() const {
        return hypot(x, y); 
    }

    // 向量逆时针旋转 90 度：(x, y) -> (-y, x)
    Point rot90() const {
        return Point(-y, x); 
    }

    // 向量顺时针旋转 90 度：(x, y) -> (y, -x)
    Point rot90r() const {
        return Point(y, -x); 
    }

    /*
        向量逆时针旋转 rad 弧度

        旋转公式：
            x' = x cosθ - y sinθ
            y' = x sinθ + y cosθ
    */
    Point<ff> rot(ff rad) const {
        return Point<ff>(
            x * cos(rad) - y * sin(rad), 
            x * sin(rad) + y * cos(rad)
        );
    }

    /*
        单位向量

        返回与当前向量同方向、长度为 1 的向量。

        注意：
            调用前要保证当前向量不是零向量，
            否则会除以 0。
    */
    Point<ff> unit() const {
        ff l = len();
        return Point<ff>(x / l, y / l);
    }

    bool operator < (const Point& p) const {
        return sgn(x - p.x) == 0 ? sgn(y - p.y) < 0 : sgn(x - p.x) < 0;
    }

    bool operator == (const Point& p) const {
        return sgn(x - p.x) == 0 && sgn(y - p.y) == 0;
    }

    // 输入点
    friend istream& operator>>(istream& is, Point& p) {
        return is >> p.x >> p.y;
    }

    // 输出点
    friend ostream& operator<<(ostream& os, const Point& p) {
        return os << p.x << " " << p.y;
    }
};

/*
    half(p)：判断点 / 向量处于极角排序中的哪一个半平面

    返回：
        0：上半平面，或者正 x 轴
        1：下半平面，或者负 x 轴

    作用：
        配合叉积实现极角排序，可以避免 atan2。
*/
template <class T>
int half(const Point<T>& p) {
    return p.y > 0 || (p.y == 0 && p.x > 0) ? 0 : 1;
}

/*
    polar_cmp(a, b)：极角排序比较函数

    排序规则：
        1. 先按上下半平面分组；
        2. 同一半平面内，按照叉积判断极角大小。

    结果：
        按照从正 x 轴开始逆时针的顺序排序。

    注意：
        如果 a 和 b 共线，这里没有进一步按长度排序。
        如果题目需要同角度点按距离排序，需要额外处理。
*/
template <class T>
bool polar_cmp(const Point<T>& a, const Point<T>& b) {
    int ha = half(a), hb = half(b);
    if (ha != hb) return ha < hb; 
    return sgn(a ^ b) > 0;        
}

template <class T> using Vector = Point<T>;

/*
    Line<T>：直线

    p：直线上一个点
    v：直线方向向量

    直线可以表示为：
        p + t * v
*/
template <class T>
struct Line {
    Point<T> p, v;

    Line() {}

    Line(Point<T> _p, Point<T> _v) : p(_p), v(_v) {}

    // 通过两点 a, b 构造直线，方向向量为 b - a
    static Line make(Point<T> a, Point<T> b) { 
        return Line(a, b - a); 
    }
};

/*
    online(p, l)：判断点 p 是否在直线 l 上

    判断方式：
        如果 (p - l.p) 与 l.v 共线，
        即叉积为 0，则 p 在直线上。
*/
template <class T>
bool online(Point<T> p, Line<T> l) {
    return sgn((p - l.p) ^ l.v) == 0;
}

/*
    onseg(p, a, b)：判断点 p 是否在线段 ab 上

    需要同时满足：
        1. p、a、b 三点共线；
        2. p 在 a 和 b 之间。

    第二个条件用点积判断：
        (p - a) · (p - b) <= 0
*/
template <class T>
bool onseg(Point<T> p, Point<T> a, Point<T> b) {
    return sgn((p - a) ^ (p - b)) == 0 && sgn((p - a) * (p - b)) <= 0;
}

/*
    unseg(a, b, c, d)：判断线段 ab 和线段 cd 的相交类型

    返回：
        0：不相交
        1：规范相交，即两条线段在内部交于唯一一点
        2：端点相交，例如 T 型或 L 型
        3：共线且部分 / 完全重合，有无数个交点

    判断流程：
        1. 先用包围盒快速排除；
        2. 再用叉积判断两条线段是否跨立；
        3. 特判共线重合。
*/
template <class T>
int unseg(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {
    // 包围盒不相交，则线段一定不相交
    if (max(a.x, b.x) < min(c.x, d.x) || max(c.x, d.x) < min(a.x, b.x) || 
        max(a.y, b.y) < min(c.y, d.y) || max(c.y, d.y) < min(a.y, b.y)) {
        return 0;
    }

    // c1, c2 判断 c、d 分别在 ab 的哪一侧
    int c1 = sgn((b - a) ^ (c - a));
    int c2 = sgn((b - a) ^ (d - a));

    // c3, c4 判断 a、b 分别在 cd 的哪一侧
    int c3 = sgn((d - c) ^ (a - c));
    int c4 = sgn((d - c) ^ (b - c));

    // 两条线段共线
    if (c1 == 0 && c2 == 0) {
        return 3; 
    }

    // 严格跨立：规范相交，交点在两条线段内部
    if (c1 * c2 < 0 && c3 * c4 < 0) {
        return 1;
    }

    // 非严格跨立：可能端点相交
    if (c1 * c2 <= 0 && c3 * c4 <= 0) {
        return 2; 
    }

    return 0;
}

/*
    inter(a, b)：求两条直线的交点

    直线 a：
        a.p + t * a.v

    直线 b：
        b.p + s * b.v

    注意：
        调用前要保证两条直线不平行，
        即 (a.v ^ b.v) != 0。
*/
Point<ff> inter(Line<ff> a, Line<ff> b) {
    ff t = ((b.p - a.p) ^ b.v) / (a.v ^ b.v);
    return a.p + a.v * t;
}

/*
    proj(p, l)：点 p 到直线 l 的投影点

    t 表示投影点在直线参数方程中的位置：
        projection = l.p + t * l.v
*/
Point<ff> proj(Point<ff> p, Line<ff> l) {
    ff t = ((p - l.p) * l.v) / (l.v * l.v);
    return l.p + l.v * t;
}

/*
    dist_p_s(p, a, b)：点 p 到线段 ab 的最短距离

    分三种情况：
        1. 投影在线段左侧，最近点是 a；
        2. 投影在线段右侧，最近点是 b；
        3. 投影在线段内部，最近点是投影点。
*/
ff dist_p_s (Point<ff> p, Point<ff> a, Point<ff> b) {
    // 线段退化成一个点
    if (a == b) return (p - a).len();

    Point<ff> v = b - a;

    // p 在 ab 方向上的投影比例
    ff t = ((p - a) * v) / (v * v);

    // 投影在线段 a 的外侧
    if (t < 0) return (p - a).len();

    // 投影在线段 b 的外侧
    if (t > 1) return (p - b).len();

    // 投影在线段内部
    Point<ff> proj = a + v * t;
    return (p - proj).len();
}

/*
    dist_s_s(p1, p2, p3, p4)：两条线段之间的最短距离

    如果两线段相交，距离为 0。
    否则答案是：
        一个线段端点到另一个线段的距离的最小值。
*/
ff dist_s_s (Point<ff> p1, Point<ff> p2, Point<ff> p3, Point<ff> p4) {
    if (unseg(p1, p2, p3, p4)) return 0;

    return min({
        dist_p_s(p1, p3, p4), 
        dist_p_s(p2, p3, p4), 
        dist_p_s(p3, p1, p2), 
        dist_p_s(p4, p1, p2),
    });
}

/*
    area(poly)：求多边形面积的两倍

    使用鞋带公式：
        2S = |Σ cross(p[i], p[i + 1])|

    返回的是面积的两倍，类型是 T。
*/
template <class T> 
T area(const vector<Point<T>>& poly) {
    T res = 0;
    int n = poly.size();

    for (int i = 0; i < n; i++) {
        res += (poly[i] ^ (poly[(i + 1) % n]));
    }

    return abs(res);
}

/*
    Area(poly)：求多边形真实面积

    返回 double。
*/
template <class T>
ff Area (const vector<Point<T>>& poly) {
    return area(poly) / 2.0;
}

/*
    ong(p, poly)：判断点 p 和多边形 poly 的关系

    返回：
        0：点在多边形外部
        1：点在多边形内部
        2：点在多边形边界上

    方法：
        射线法 / 奇偶规则。

    核心思想：
        从点 p 向某个方向发出射线，
        如果和多边形边相交次数为奇数，则在内部；
        如果为偶数，则在外部。

    当前实现中：
        将每条边的两个端点都平移为相对 p 的向量 v1, v2，
        然后判断边是否跨过从 p 出发的正方向射线。
*/
template <class T>
int ong (Point<T> p, const vector<Point<T>>& poly) {
    int n = poly.size();

    // in 表示当前交点次数的奇偶性
    bool in = 0;

    for (int i = 0; i < n; i++) {
        // 当前边两个端点相对 p 的向量
        Point<T> v1 = poly[i] - p;
        Point<T> v2 = poly[(i + 1) % n] - p;

        // 如果 p 在当前边上，直接返回 2
        if (sgn(v1 ^ v2) == 0 && sgn(v1 * v2) <= 0) {
            return 2;
        }

        // 保证 v1.y <= v2.y，方便统一判断
        if (sgn(v1.y - v2.y) > 0) swap(v1, v2);

        /*
            判断当前边是否向上穿过射线。

            条件：
                1. v1.y <= 0
                2. v2.y > 0
                3. v1 ^ v2 > 0

            满足则说明射线与边相交一次，翻转 in。
        */
        if (sgn(v1.y) <= 0 && sgn(v2.y) > 0 && sgn(v1 ^ v2) > 0) {
            in ^= 1;
        }
    }

    if (in) return 1;
    else return 0;
}

void solve ()
{
    int n;
    cin >> n;
    vector <Point <int> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].x >> v[i].y;
    }
    vector <vector <int> > dis2(n + 1, vector <int> (n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            dis2[i][j] = (v[i].x - v[j].x) * (v[i].x - v[j].x) + (v[i].y - v[j].y) * (v[i].y - v[j].y);
        }
    }

    map <int, int> mp;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        map <int, int> mpn;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            mpn[dis2[i][j]]++;
        }
        if (i == 1) {
            for (auto [x, y] : mpn) {
                if (y >= 2) {
                    mp[x] = true;
                    cnt++;
                }
            }
        }else {
            for (auto [x, y] : mp) {
                if (mpn[x] < 2) {
                    mp[x] = false;
                    cnt--;
                }
            }
        }
        if (cnt == 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}   
    
int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 