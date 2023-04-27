#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int Max = 100;

class BinarySearchTree{
private:
	int ara[Max];
	int size;
public:

	BinarySearchTree(){
		for(int i=0; i<Max; i++) ara[i] = -1;
		size = 0;	
	}

	void insert(int val)
	{
		if(size==Max){
			cout << "BST OVERLOADED\n";
			return ;
		}
		int index = 0;
		while(ara[index]!=-1)
		{
			if(ara[index]>val) index = 2*index+1;
			else index = 2*index+2;

			if(index>=Max){
				cout << "BST OVERLOADED\n";
			return ;
			} 
		}
		ara[index] = val;
		size++; 
	}

	bool search(int val)
	{
		int index = 0;
		while(ara[index]!=-1)
		{
			if(ara[index]==val) return true;

			if(ara[index]>val) index = 2*index+1;
			else index = 2*index+2;
		}
		return false;
	}

	  void deleteNode(int value) {
        int index;
        if (!search(value)) {
            cout << "Error: value not found\n";
            return;
        }
        if (ara[2 * index + 1] == -1 && ara[2 * index + 2] == -1) {
            ara[index] = -1;
            size--;
        }
        else if (ara[2 * index + 1] == -1 || ara[2 * index + 2] == -1) {
            int childIndex = ara[2 * index + 1] == -1 ? 2 * index + 2 : 2 * index + 1;
            ara[index] = ara[childIndex];
            ara[childIndex] = -1;
            size--;
        }
        else {
            int successorIndex = 2 * index + 2;
            while (ara[2 * successorIndex + 1] != -1) {
                successorIndex = 2 * successorIndex + 1;
            }
            ara[index] = ara[successorIndex]; 
            ara[successorIndex] = -1;
            size--;
        }
    }

    void inordertraversal(int index){

    	if(ara[index==-1]) return;
    	inordertraversal(2*index+1);
    	cout << ara[index] << " ";
    	inordertraversal(2*index+2);
    }

    void preordertraversal(int index){
    	if(ara[index]==-1) return ;
    	cout << ara[index] << " ";
    	preordertraversal(2*index+1);
    	preordertraversal(2*index+2);
    }

    void postordertraversal(int index)
    {
    	if(ara[index]==-1) return;
    	postordertraversal(2*index+1);
    	postordertraversal(2*index+2);
    	cout << ara[index] << " ";
    }

     bool isPerfect() {
        int depth = log2(size + 1); 
        for (int i = 0; i < pow(2, depth - 1); i++) {
            if (ara[(int)pow(2, depth - 1) - 1 + i] == -1) {
                return false;
            }
        }
        for (int i = 0; i < pow(2, depth - 1) - 1; i++) {
            if (ara[i] != -1 && (ara[2 * i + 1] == -1 || ara[2 * i + 2] == -1)) {
                return false;
            }
        }
        return true;
    }

    bool isFull()
    {
    	for(int i=0; i<size; i++)
    	{
    		if(ara[i]!=-1)
    		{
    			if((ara[2*i+1]!=-1 && ara[2*i+2]==-1) || (ara[2*i+1]==-1 && ara[2*i+2]!=-1))
    				return false;
    		}
    	}
    	return true;
    }

     bool isComplete() {
        int depth = log2(size + 1);

        for (int i = 0; i < pow(2, depth-1) - 1; i++) { 
            if (ara[i] != -1 && (ara[2 * i + 1] == -1 || ara[2 * i + 2] == -1)) {
                return false;
            }
        }

        for (int i = pow(2, depth - 1) - 1; i < size; i++) {
            if (ara[i] == -1) {
                return false;
            }
        }

        return true;
    }

    int height(int index)
    {
    	if(ara[index]==-1) return -1;
    	int leftheight = height(2*index+1);
    	int rightheight = height(2*index+2);

    	return 1+max(leftheight,rightheight);
    }

    bool isBalancedHelper(int index) { 
        if (ara[index] == -1) {
            return true;
        }
        int left = height(2 * index + 1); 
        int right = height(2 * index + 2); 

        if (abs(left - right) > 1) { 
            return false; 
        }
        return isBalancedHelper(2 * index + 1) && isBalancedHelper(2 * index + 2); 
    }
    bool isBalanced() {
        if (size == 0) { 
            return true;
        }
        return isBalancedHelper(0);
    }

    bool isLeftskewed(){
    	for(int i=0; i<size; i++){
    		if(ara[i]!=-1 && ara[2*i+2]!=-1) return false;
    	}
    	return true;
    }

    bool isrightskewed(){
    	for(int i=0; i<size; i++)
    	{
    		if(ara[i]!=-1 && ara[2*i+1]!=-1) return false;
    	}
    	return true;
    }

};
int main(void)
{
	BinarySearchTree t;
	t.insert(8);
	t.insert(45);
	t.insert(1223);
	// t.insert(3);
	// t.insert(5);
	// t.insert(9);
	// t.insert(12);

	//if(t.isComplete()==true) cout <<"1\n";
	//if(t.isBalanced()) cout << "Yahoo\n";
	//if(t.isrightskewed()) cout << "Yahoo\n";
 	
	return 0;
}
