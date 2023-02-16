// 8落雪，交错重叠.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstdio>
using namespace std;
char dat[105][105];
int visit[105][105];
int row, column, snowsize;
int im[105], jm[105], snow[105];
void color(int x, int y)
{
	int shang = 0, xia = 0, zuo = 0, you = 0;
	for (int i = x+1; i <= row; i++)
	{
		if (dat[i][y] == '*')
			xia++;
		else
			break;
	}
	for (int i = x-1; i > 0; i--)
	{
		if (dat[i][y] == '*')
			shang++;
		else
			break;
	}
	for (int i = y+1; i <= column; i++)
	{
		if (dat[x][i] == '*')
			you++;
		else
			break;
	}
	for (int i = y-1; i > 0; i--)
	{
		if (dat[x][i] == '*')
			zuo++;
		else
			break;
	}
	snowsize = min(min(min(shang, xia), zuo), you);
	for (int i = x; i <= x + snowsize; i++)
		visit[i][y] = 0;
	for (int i = x; i >= x - snowsize; i--)
		visit[i][y] = 0;
	for (int i = y; i <= y + snowsize; i++)
		visit[x][i] = 0;
	for (int i = y; i >= y - snowsize; i--)
		visit[x][i] = 0;
}
bool fullf()
{
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= column; j++)
			if (visit[i][j] == 1)
				return false;
	return true;
}
int main()
{
	scanf("%d%d", &row, &column);
	for (int i = 1; i <= row; i++)
	{
		scanf("%s", dat[i] + 1);
		for (int j = 1; j <= column; j++)
		{
			if (dat[i][j] == '*')
				visit[i][j] = 1;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= column; j++)
			if (dat[i][j] == '*' && dat[i][j - 1] == '*' && dat[i][j + 1] == '*'
				&& dat[i - 1][j] == '*' && dat[i + 1][j] == '*')
			{
				color(i, j);
				im[cnt] = i;
				jm[cnt] = j;
				snow[cnt] = snowsize;
				cnt++;
			}
	if (fullf())
	{
		cout << cnt << endl;
		for (int i = 0; i < cnt; i++)
			cout << im[i] << ' ' << jm[i] << ' ' << snow[i] << endl;
	}
	else
		cout << -1 << endl;
}

