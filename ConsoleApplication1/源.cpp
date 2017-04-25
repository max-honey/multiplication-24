#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<set>
#include<vector>
#include<math.h>
using namespace std;
double tag = 0;
char ch[4] = { '+','-','*','/' };
double operate(double a,double b,int i)
{
	if (ch[i] == '+')       return (a + b);
	else if (ch[i] == '-')  return (a - b);
	else if (ch[i] == '*')  return (a*b);
	else if (ch[i] == '/')
	{
		if (b == 0)return(0.0);
		else       return (a / b);
	}
}
void  calcu(int i, int j, int k, double a, double b, double c, double d)
{

if (fabs(operate(operate(a, b, i), operate(c, d, k), j) - 24.0) <= 1E-5)
	{
		//cout << "yes" << endl;
		tag = 1;
		return;
	}
	else if (fabs(operate(operate(operate(a, b, i), c, j), d, k) - 24.0) <= 1E-5)
	{
		//cout << "yes" << endl;
		tag = 1;
		return;
	}
	else if (fabs(operate(operate(a, operate(b, c, j),i), d, k) - 24.0) <= 1E-5)
	{
		//cout << "yes" << endl;
		tag = 1;
		return;
	}
	else if (fabs(operate(a, operate(operate(b, c, j), d, k),i) - 24.0) <= 1E-5)
	{
		//cout << "yes" << endl;
		tag = 1;
		return;
	}
	//else if (operate(operate(a, operate(b, c, i), j), d, k) == 24)cout << "yes" << endl;
	else if (fabs(operate(a, operate(b, operate(c, d, k), j),i) - 24.0) <= 1E-5)
	{
		//cout << "yes" << endl;
		tag = 1;
		return;
	}
}
int main()
{
	double sum[4];
	memset(sum, 0.00, 4);
	int p, m, q, t;
	while (scanf("%lf %lf %lf %lf", &sum[0], &sum[1], &sum[2], &sum[3]) != EOF)
	{
		tag = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{

					for (p = 0; p < 4; p++)//移动a,b,c,d的位置
					{
						for (q = 0; q < 4; q++)
						{
							for (m = 0; m < 4; m++)
							{
								for (t = 0; t < 4; t++)
								{
									if (p != q&&p != m&&p != t&&q != m&&q != t&&m != t)
										calcu(i, j, k, sum[p], sum[q], sum[m], sum[t]);
									if (tag != 0)break;
								}
								if (tag != 0)break;
							}
							if (tag != 0)break;
						}
						if (tag != 0)break;
					}//移动a,b,c,d的位置
					if (tag != 0)break;
				}
				if (tag != 0)break;
			}
			if (tag != 0)break;
		}
		if (tag == 0)cout << "no" << endl;
		else cout << "yes" << endl;
	}
	system("pause");
	return 0;
}