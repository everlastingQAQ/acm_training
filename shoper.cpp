#include <bits/stdc++.h>
using namespace std;

char *p1, *p2, buf[100000];
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++)

int read()
{
    int x = 0, f = 1;
    char ch = gc();

    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = gc();
    }

    while ('0' <= ch && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = gc();
    }

    return x * f;
}

int s[20][20];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int fa[400], rk[400], sz[400];

struct DSU
{
    int comps;
    DSU(int n = 0)
    {
        init(n);
    }

    void init(int n)
    {

    }
    
    int find(int x)
    {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }
    bool uni(int i, int j)
    {
        int x = find(i), y = find(j);
        if (x == y)
            return false;
        if (rk[x] < rk[y])
            swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
        if (rk[x] == rk[y])
            rk[x]++;
        comps--;
        return true;
    }
    int size(int x)
    {
        return sz[find(x)];
    }
};

int id(int x, int y)
{
    return (x * 19 + y);
}

int remove_dead(int tar)
{
    DSU dsu(400);
    for (int i = 1; i <= 400; i++)
    {
        fa[i] = i;
        rk[i] = 1;
        sz[i] = 1;
    }

    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
        {
            if (!s[i][j])
                continue;

            for (int k = 0; k < 4; k++)
            {
                int xx = i + dx[k];
                int yy = j + dy[k];

                if (xx < 1 || xx > 19 || yy < 1 || yy > 19)
                    continue;

                if (s[xx][yy] == s[i][j])
                {
                    dsu.uni(id(i, j), id(xx, yy));
                }
            }
        }
    }

    bool qi[400] = {0};

    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
        {
            if (!s[i][j])
                continue;

            int root = dsu.find(id(i, j));

            for (int k = 0; k < 4; k++)
            {
                int xx = i + dx[k];
                int yy = j + dy[k];

                if (xx < 1 || xx > 19 || yy < 1 || yy > 19)
                    continue;

                if (!s[xx][yy])
                {
                    qi[root] = true;
                }
            }
        }
    }

    int count = 0;

    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
        {
            if (s[i][j] != tar)
                continue;

            int root = dsu.find(id(i, j));

            if (!qi[root])
            {
                count++;
                s[i][j] = 0;
            }
        }
    }

    return count;
}

void solve()
{
    int n = read();

    for (int q = 1; q <= n; q++)
    {
        int x = read();
        int y = read();

        s[x][y] = (1 + q % 2);

        int a = 0, b = 0;

        if (q % 2 == 1)
        {
            a += remove_dead(1);
            b += remove_dead(2);
        }
        else
        {
            b += remove_dead(2);
            a += remove_dead(1);
        }

        printf("%d %d\n", b, a);
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);

    // int t = 1;
    // while (t--)
    // {
        solve();
    // }

    return 0;
}

////