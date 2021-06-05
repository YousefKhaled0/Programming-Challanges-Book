#include <bits/stdc++.h>

using namespace std;

bool isPowerOf2(int n)
{
    return !(n & (n - 1));
}

int sol(int n)
{
    int ans = 0;

    while (1)
    {
        ans++;
        if (n == 1) return ans;
        else if (n % 2) n = 3 * n + 1;
        else {
            if (isPowerOf2(n)) {
                ans += log2(n);
                return ans;
            }else n = n / 2;
        }
    }


}


int main()
{
    int x, y, ans;
    while(scanf("%d%d",&x,&y)==2)
    {
        printf("%d %d ",x,y);
        if (x > y) swap(x , y);
        ans = 0;
        for (int i = x ; i <= y ; i++)
        {
            ans = max(ans, sol(i));
        }
        printf("%d\n",ans);
    }

    return 0;
}
