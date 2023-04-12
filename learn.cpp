#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int b_search(int ara[], int n, int val)
{
	int lo = 0, hi = n-1, ans = -1;
	while(hi>=lo)
	{
		int mid = lo+(hi-lo)/2;
		if(ara[mid]>val) lo = mid+1;
		else{
			hi = mid-1;
			ans = mid;
		}
	}
	return ans; 
}
int binary_search(int ara[], int hi, int lo, int val)
{
	//int lo = 0, hi = n-1;
	while(hi>=lo)
	{
		int mid = lo+(hi-lo)/2;
		if(ara[mid]==val) return mid;
		if(ara[mid]>val) hi = mid-1;
		else lo = mid+1;
	}
	return -1;
}

int main(void)
{
	int n,ara[1000],target;
	cin >> n;
	for(int i=0; i<n; i++) cin >> ara[i];
	cin >> target;
	int in = b_search(ara,n,ara[0]);
	if(in == -1) cout << binary_search(ara,n-1,0,target);

	else
	{
		int ans = binary_search(ara,in-1,0,target); 
		if(ans==-1) cout << binary_search(ara,n-1,in,target) << "\n";
	}
	
	return 0;
}
