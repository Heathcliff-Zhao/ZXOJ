// 6疲倦，召之即来.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main()
{
	long long n, k, s, now = 1;
	cin >> n >> k >> s;
	if ((n - 1) * k < s || s == 0 || k == 0 || k>s)
		cout << "NO" << endl;
	else
	{
		int cnt = 1;
		cout << "YES" << endl;
		while (s - n + 1 >= k - 1 && s > 0 && k > 0)
		{
			s -= (n-1);
			k--;
			if (cnt % 2)
			{
				now = n;
				cout << now << " ";
			}
			else
			{
				now = 1;
				cout << now << " ";
			}
			cnt++;
		}
		while (s != k && s > 0 && k > 0)
		{
			if (cnt % 2)
			{
				if (2 + s - k <= n)
				{
					now = 2 + s - k;
					cout << now << " ";
					s -= (s - k + 1);
				}
				else
				{
					now = n;
					cout << now << " ";
					s -= (n - 1);
				}
			}
			else
			{
				if (n - s + k - 1 >= 1)
				{
					now = n - s + k - 1;
					cout << now << " ";
					s -= (s - k + 1);
				}
				else
				{
					now = 1;
					cout << now << " ";
					s -= (n - 1);
				}
			}
			k--;
			cnt++;
		}
		while (k--)
		{
			if (now == 1)
			{
				now++;
				cout << now << " ";
			}
			else
			{
				now--;
				cout << now << " ";
			}
		}
	}
}