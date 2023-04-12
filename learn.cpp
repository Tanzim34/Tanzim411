#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void bubblesort(int ara[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<(n-i-1); j++)
			if(ara[j]>ara[j+1]) swap(ara[j],ara[j+1]);
	}
}

int main(void)
{
	int m,n;
	cin >> m >> n;
	int ara[m][n];
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++) cin >> ara[i][j];
	}
	int help[10000];

	for(int i=0; i<n; i++)
	{
		int size = 0;
		int ro = m-1, col = i;
		while(ro>=0 && col>=0)
		{
			help[size++] = ara[ro--][col--];
		}
		bubblesort(help,size);
		ro = m-1;
		col = i;
		for(int i=size-1; i>=0; i--)
		{
			ara[ro--][col--] = help[i];
		}
	}

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			cout << ara[i][j] << " ";
		cout << "\n";
	}

	
	return 0;
}
