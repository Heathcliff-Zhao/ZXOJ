// 7切割，重复不止.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<algorithm>
#define inf 0x7fffffff
using namespace std;
int a[200010], ans[200010], p[200010], q[200010];
int cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int n, k, i, mn = 0;
	cin >> n >> k;
	for (int j = 0; j < n; j++)
	{
		cin >> i;
		mn = mn > i ? mn : i;
		a[i]++;
	}
	for (int i = 0; i <= mn; i++)
	{
		p[i] = a[i];
		q[i] = a[i];
	}
	sort(p, p + mn + 4, cmp);
	sort(q, q + mn + 4, cmp);
	int f = 0, g = k - 2, pre = 0;
	while (f < g)
	{
		if (q[f] >= 2 * q[g])
		{
			pre++;
			g--;
			q[f] /= 2;
		}
		else
		{
			f++;
		}
	}
	for (int i = 0; i < k; i++)
	{
		int m = 0;
		for (int j = 0; j < mn + 4; j++)
			if (m < a[j])
				m = a[j];
		for (int j = 0; j < mn + 4; j++)
			if (m == a[j])
			{
				ans[i] = j;
				a[j] -= (p[k - 1 - pre]);
				break;
			}
	}
	for (int i = 0; i < k; i++)
		cout << ans[i] << " ";
}