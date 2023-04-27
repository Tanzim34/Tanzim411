#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int Max = 100;

class Maxheap{
private:
	int heap[Max];
	int size;

public:
	Maxheap(){
		for(int i=0; i<Max; i++) heap[i] = -1;
		size = 0;	
	}

	void heapify(int index)
	{
		int largest = index;
		int l = 2*index+1;
		int r = 2*index+2;

		if(heap[l]>heap[largest]) largest = l;
		if(heap[r]>heap[largest]) largest = r;

		if(largest!=index){
			swap(heap[largest],heap[index]);
			heapify(largest);
		}
	}

	void insert(int val)
	{
		if(size==Max){ 
		cout << "Heap Overloaded\n";
		return;
		}
		heap[size++] = val;
		int index = size-1;
		int parent = (size-1)/2;

		while(heap[parent]<heap[index])
		{
			swap(heap[parent],heap[index]);
			index = parent;
			parent = (index-1)/2;
		}

	}

	void Delete(int val)
	{
		int index = -1;
		for(int i=0; i<size; i++)
			if(heap[i]==val) index = i;
		if(index==-1){
			cout << "Value not found\n";
			return;
		}
		swap(heap[index],heap[size-1]);
		heap[size-1] = -1;
		size--;
		heapify(index);

		int parent = (index-1)/2;

		while(heap[parent]<heap[index])
		{
			swap(heap[parent],heap[index]);
			index = parent;
			parent = (index-1)/2;
		}

	}

	int peek(){
		return heap[0];
	}

	int extract()
	{
		Delete(heap[0]);
		return heap[0];
	}

	void printheap()
	{
		for(int i=0; i<size; i++) cout << heap[i] << " ";
		cout << "\n";	
	}

};


int main(void)
{
	Maxheap h;

	h.insert(10);
	h.insert(12);
	h.insert(5);
	h.insert(3);

	h.printheap();

	h.Delete(5);

	h.printheap();

	//cout << h.peek() << " ";
	//cout << h.extract();
 	h.printheap();
 	
	return 0;
}
