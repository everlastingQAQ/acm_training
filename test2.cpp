#include <cstdio>
#include <cctype>
int read()
{
    int ans = 0;
    char c = getchar();
    while (!isdigit(c))
        c = getchar();
    while (isdigit(c))
    {
        ans = (ans << 3) + (ans << 1) + c - '0';
        c = getchar();
    }
    return ans;
}
int fa[150005], rank[150005];
int find(int a)
{
    return (fa[a] == a) ? a : (fa[a] = find(fa[a]));
}
int query(int a, int b)
{
    return find(a) == find(b);
}
void merge(int a, int b)
{
    int x = find(a), y = find(b);
    if (rank[x] >= rank[y])
        fa[y] = x;
    else
        fa[x] = y;
    if (rank[x] == rank[y] && x != y)
        rank[x]++;
}
void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        rank[i] = 1;
        fa[i] = i;
    }
}
int main()
{
    int n = read(), m = read(), ans = 0;
    init(n * 3); //i吃i+n，被i+2n吃
    for (int i = 0; i < m; ++i)
    {
        int opr, x, y;
        scanf("%d%d%d", &opr, &x, &y);
        if (x > n || y > n) //特判x或y不在食物链中的情况
            ans++;
        else if (opr == 1)
        {
            if (query(x, y + n) || query(x, y + 2 * n)) //如果已知x吃y，或者x被y吃，说明这是假话
                ans++;
            else
            {
                merge(x, y);                 //这是真话，则x和y是一族
                merge(x + n, y + n);         //x的猎物和y的猎物是一族
                merge(x + 2 * n, y + 2 * n); //x的天敌和y的天敌是一族
            }
        }
        else if (opr == 2)
        {
            if (query(x, y) || query(x, y + 2 * n)) //如果已知x与y是一族，或者x被y吃，说明这是假话
                ans++;
            else
            {
                merge(x, y + n);         //这是真话，则x吃y
                merge(x + n, y + 2 * n); //x的猎物吃y的猎物
                merge(x + 2 * n, y);     //x的天敌吃y的天敌，或者说y吃x的天敌
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}