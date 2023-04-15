#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int SIZE = 100;

class Queue{
private:
	int data[SIZE],front,rear;
public:
	Queue(){
		front = -1; rear = -1;
	}
	bool is_full(){
		if(rear==SIZE-1) return true;
		return false;
	}
	bool is_empty(){
		if(front==-1) return true;
		return false;
	}
	void enQueue(int num){
		if(front==-1) front = 0;
		rear++;
		data[rear] = num;
	}
	int deQueue(){
		int num = data[front];
		if(front>=rear){
			front = -1;
			rear = -1;
		}
		else front++;
		return num;
	}
	void clear(){
		front = -1;
		rear = -1;
	}
	void display(){
		for(int i=front; i<=rear; i++) cout << data[i] << " ";
		cout << "\n"; 	
	}
};

int main(void)
{
	Queue q1,q2;
	int n,a,f=0,x,sum = 0;
	cin >> n >> x; 
	for(int i=1; i<=n; i++)
	{
		cin >> a;
		sum+=a;
		if(sum>x) f = 1;
		if(f==0){
		 q1.enQueue(a);
		 q2.enQueue(a);
		}
		else
		{
			if(sum<=x){
				q1.enQueue(a);
				q2.clear();
				while(!q1.is_empty())
				{
					int k = q1.deQueue();
					q2.enQueue(k);
					q1.enQueue(k);
				}
			}
			else
			{
				q1.enQueue(a);
				sum-=q1.deQueue();
			}			
		}
	}
	q2.display();
	return 0;
}
