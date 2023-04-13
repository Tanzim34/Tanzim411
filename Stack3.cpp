#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Stack{

private :
	int ara[100];
	int size = 0;
public:
	void push(int k)
	{
		ara[size++] = k;
	}
	int peek()
	{
		return ara[size-1];
	}
	void pop(){
	  size--;
	}
	void display()
	{
		for(int i=size-1; i>=0; i--) cout << ara[i] << " ";
		cout << "\n";	
	}	
};

int StringToint(string s)
{
	int ans = 0, f = 0;
	if(s[0]=='-') f = 1;
	else ans = (s[0]-'0');
	for(int i = 1; i<s.size(); i++)
	{		
		int a = s[i]-'0';
		ans = ans*10+a;
	}
	if(f==1) ans = (-1)*ans;
	return ans;
}

int main(void)
{
	Stack st;
	string ch;
	while(1)
	{
		cin >> ch;
		if(ch=="0") break;
		if(ch!="+" && ch!="-" && ch!="*" && ch!="/")
		{
			int a = StringToint(ch);
			st.push(a);
		}
		else
		{
			int a = st.peek();
			st.pop();
			int b = st.peek();
			st.pop();
			if(ch=="+") st.push(a+b);			
			else if(ch=="-") st.push(b-a);
			else if(ch=="*") st.push(b*a);
			else st.push(b/a);
		}
	}
	int ans = st.peek();
		st.pop();
		cout << ans << "\n";
	return 0;
}
