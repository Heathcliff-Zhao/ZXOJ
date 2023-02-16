// 5回文，排版错误.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include <iostream>
#include<cstring>
using namespace std;
string leftar, midar, rightar;
string dat[120];
int cn[120], an[120], mark[120], bn[120];
bool zi(int m, string s)
{
	for (int i = 0; i < m / 2; i++)
		if (s[i] != s[m - i - 1])
			return 0;
	return 1;
}
bool hu(int m, string a, string b)
{
	for (int i = 0; i < m; i++)
		if (a[i] != b[m - i - 1])
			return 0;
	return 1;
}
int main()
{
	int n, m, p = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> dat[i];
	for (int i = 0; i < 120; i++)
	{
		an[i] = -1;
		bn[i] = -1;
		cn[i] = -1;
		mark[i] = 1;
	}
	for (int i = 0; i < n-1; i++)
		if (mark[i])
			for (int j = i + 1; j < n; j++)
				if (mark[j] && hu(m, dat[i], dat[j]))
				{
					an[p] = i;
					cn[119 - p] = j;
					p++;
					mark[i] = 0;
					mark[j] = 0;
				}
	for (int i = 0; i < n; i++)
		if (mark[i] && zi(m, dat[i]))
		{
			mark[i] = 0;
			bn[p] = i;
			p++;
		}
	int time = 1, e = 0, ee = 0, eee = 0;
	for (int i = 0; i < 120; i++)
	{
		if (an[i] != -1)
		{
			leftar += dat[an[i]];
			e++;
		}
		if (bn[i] != -1 && time--)
		{
			midar += dat[bn[i]];
			ee++;
		}
		if (cn[i] != -1)
		{
			rightar += dat[cn[i]];
			eee++;
		}
	}
	string ans = leftar + midar + rightar;
	cout << m * (e + ee + eee) << endl;
	cout << ans << endl;
}

