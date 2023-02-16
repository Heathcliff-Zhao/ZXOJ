// 3初雪，片缕幻影.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
char G[505][505], have[505][505];
int main()
{
	int row, column, flag = 1, ti = 0, shu = 0, heng = 0;
	cin >> row >> column;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= column; j++)
			cin >> G[i][j];
	for(int i=1;i<=row;i++)
		for (int j = 1; j <= column; j++)
		{
			if (G[i][j] == '*' && G[i][j - 1] == '*' && G[i][j + 1] == '*'
				&& G[i + 1][j] == '*' && G[i - 1][j] == '*')
			{
				ti = 1;
				for (int m = 1; m <= row; m++)
				{
					if (G[m][j] == '*')
					{
						have[m][j] = 1;
						shu = 1;
					}
					else
						if(shu==1)
							break;
				}
				for (int n = 1; n <= column; n++)
				{
					if (G[i][n] == '*')
					{
						have[i][n] = 1;
						heng = 1;
					}
					else
						if (heng == 1)
							break;
				}
				for (int k = 1; k <= row; k++)
					for (int p = 1; p <= column; p++)
						if (have[k][p] == 0 && G[k][p] == '*')
						{
							flag = 0;
							goto k;
						}
			}
		}
k:
	if (flag && ti)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}