#include <bits/stdc++.h>
using namespace std;

char s[50][50];
int chess[50];
int cnt;

void plans(int k, int r, int n)
{
    if (k == 0)
    {
        cnt ++;
        return ;
    }
    if (k > n) return ;
    if (r >= n) return ;
    for (int i = r; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            if (s[i][j] == '#')
            {
                if (chess[j] == 0)
                {
                    chess[j] = 1;
                    plans(k - 1, i + 1, n);
                    chess[j] = 0;
                }
            }
        }
    }
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    while (!(n == -1 && k == -1))
    {
        cnt = 0;
        memset(chess, 0, sizeof(chess));
        for (int i = 0; i < n; i ++) scanf("%s", s[i]);
        plans(k, 0, n);
        printf("%d\n", cnt);
        scanf("%d%d", &n, &k);
    }
    return 0;
}