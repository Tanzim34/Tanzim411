#include<bits/stdc++.h>
using namespace std;

int parent[100005];
int size[100005];

void make_set(int v)
{
	parent[v] = v;
	size[v] = 1;
}

int find_set(int v)
{
	if(parent[v]==v) return v;
	parent[v] = find_set(parent[v]);
	return parent[v];
}

void union_set(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if(size[a]<size[b]) swap(a,b);
	parent[b] = a;
	size[a] += size[b];
} 

int main(void)
{
	//set<int> s;
	make_set(2);
	make_set(5);
	make_set(10);
	make_set(7);
	make_set(8);
	union_set(2,5);
	union_set(2,10);
	union_set(7,8);

	// check if they are in the same set

	if(find_set(5)==find_set(10)) cout << "Yes\n";

	// Return the root of the set

	cout << find_set(8) << "\n";

	return 0;
}