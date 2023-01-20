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
Node* insertBST(Node* root,int val)
{
	if(root==NULL)
	{
		return new Node(val);
	}
	if(val<root->data)
	{
		root->left= insertBST(root->left,val);
	}
	else
	{
		root->right= insertBST(root->right,val);
	}
	return root;
}

void Inorder(Node*root)
{
	if(root==NULL)
	{
		return;
	}
	Inorder(root->left);
	cout<<root->data;
	Inorder(root->right);

}
int leaf (Node*root)
{
	if(root==NULL)
	{
		return NULL;
	}
	 Node*current=root;
	Node*temp=root;
	while(current!=NULL)
	{
		current=current->left;
		if(current->left==NULL)
		{
			cout<<current->data;
		}
	}	
	while(temp!=NULL)
	{
		temp=temp->right;
		if(temp->right==NULL)
		{
			cout<<temp->data;
		}
	}
	
}
void secondlastval(Node*root)
{
	struct Node*current=root;
	while(current->right<NULL)
	{
		current=current->right;
	}
	cout<<current->data;
}
int main()
{
	Node*root=NULL;
	root= insertBST(root,1);
	insertBST(root,3);
	insertBST(root,4);
	insertBST(root,5);
	insertBST(root,6);
	insertBST(root,7);
	Inorder(root);
	cout<<endl;
	secondlastval(root);
	cout<<endl;
	
	return 0;
}
