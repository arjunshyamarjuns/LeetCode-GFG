// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}
// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/


int l=0;
Node *solve(int post[],int sz,int lb,int ub){
   
   if(l<0 || post[l]<=lb || post[l]>=ub) return NULL;
   Node *root=new Node(post[l]);
   int val=post[l];
   l--;
   root->right=solve(post,sz,val,ub);
   root->left=solve(post,sz,lb,val);
   return root;
   
}
Node *constructTree (int post[], int size)
{
//code here
 l=size-1;
 Node *head=solve(post,size,INT_MIN,INT_MAX);
 return head;
 
}