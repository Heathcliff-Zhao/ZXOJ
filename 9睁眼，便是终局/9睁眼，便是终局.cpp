// 9睁眼，便是终局.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
using namespace std;
int dat[250];
int deci[250];
int M = 0;
int n, k, x;
int dfs(int tic,int cnt)
{
	if (cnt == 3)
		return M;
	deci[tic] = 1;
	int nowcnt = cnt + 1;
	M = max(M, M + dat[tic]);
	dfs(tic + 1, nowcnt);
	dat[tic] = 0;
}
int main()
{
	if (n / (double)k > x)
		cout << -1 << endl;
	else
	{
		dfs(n, 0);
		cout << M << endl;
	}
}