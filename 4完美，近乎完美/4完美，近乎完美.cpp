// 4完美，近乎完美.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<algorithm>
using namespace std;
long long a[200005], n, sumofa = 0, maxofa = 0, sem = 0, num = 0;
long long ans[200005], temp = 0, cnt = 0, k = 0, counts = 0;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		sumofa += a[i];
	for (int i = 1; i <= n; i++)
		maxofa = max(maxofa, a[i]);
	for (int i = 1; i <= n; i++)
		if (a[i] == maxofa)
		{
			num++;
			counts = i;
		}
	if (num==1)
		for (int i = 1; i <= n; i++)
			if (a[i] < maxofa)
				sem = max(sem, a[i]);
	for (int i = 1; i <= n; i++)
	{
		temp = a[i];
		a[i] = 0;
		if (i == counts && num == 1)
		{
			if (sem == sumofa - temp - sem)
				ans[cnt++] = i;
		}
		else
			if (maxofa == sumofa - temp - maxofa)
				ans[cnt++] = i;
		a[i] = temp;
	}
	if (cnt)
	{
		cout << cnt << endl;
		for (int i = 0; i < cnt; i++)
			cout << ans[i] << " ";
	}
	else
		cout << 0 << endl;
}