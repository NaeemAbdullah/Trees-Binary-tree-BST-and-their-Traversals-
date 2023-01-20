#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node*left,*right;
	
	Node(int val)
	{
		data=val;
		left=NULL;
		right=NULL;
	}
};
bool checkBST(Node*root , Node*min = NULL , Node*max = NULL)
{
	if(root==NULL)
	{
		return true;
	}
	if(root!=NULL && root->data<=min->data)
	{
		return false;
	}
	if(max!=NULL && root->data>=max->data)
	{
		return false;
	}
	bool leftvalid=checkBST(root->left,min,root);
	bool rightvalid=checkBST(root->right,root,max);
	return leftvalid and rightvalid;	
}

int main()
{
	Node*root1=new Node(1);
	root1->left=new Node(2);
	root1->right=new Node(3);
	cout<<"CHECK BST ";
	int x=checkBST(root1,NULL,NULL);
	if(x)
	{
		cout<<"VALID BST "<<endl;
	}
	else
	{
		cout<<"INVALID BST "<<endl;
	}
}

