#include "problem14.h"

NODE root;

unsigned int __node_count;

void __init_tree(){
	root = NULL;
	__node_count = 0;
}

unsigned int max(unsigned int x,unsigned int y){
	return (x>y) ? x : y;
}

unsigned int depth(NODE node){
	if(node==NULL) return 0;
	return max(depth(node->left)+1, depth(node->right)+1);
}

void rotate_left(){
	NODE left,right;
	if(root==NULL) return;
	left = root->left;
	right = root->right;
	if(right==NULL) return;
	root->right = right->left;
	right->left = root;
	root = right;
}

void rotate_right(){
	NODE left,right;
	if(root==NULL) return;
	left = root->left;
	right = root->right;
	if(left==NULL) return;
	root->left = left->right;
	left->right = root;
	root = left;
}

void rebalance(){
	unsigned int dl,dr,diff;
	if(root==NULL) return;
	while(1){
		dl = depth(root->left);
		dr = depth(root->right);
		diff=(dl-dr);
		if(diff==0 || diff==-1 || diff==1) break;
		if(dl>dr) { rotate_right(); continue; }
		rotate_left();
	}
}

void add(unsigned int n, unsigned int len){
    NODE node = root,new_node=NULL;
    unsigned int flag=0;
    
	new_node=(NODE)malloc(sizeof(struct __seq_tree_node));
	new_node->left=new_node->right=NULL;
	new_node->start=n;
	new_node->length=len;
	__node_count++;
	
    if(root==NULL) { root = new_node; return; }
    
    while(node->start!=n){
        if(node->start<n){ 
            if(node->right!=NULL)
                node=node->right;
            else         
            {   
                flag=1;
                break;
            }
        }
        if(node->start>n){
            if(node->left!=NULL)
                node=node->left;
            else
            {
                flag=0;
                break;
            }
        }
   }
   if(flag==1)node->right=new_node;
   else node->left=new_node;
   if(__node_count%1000==0) rebalance();
}

unsigned int get_seq_len(unsigned int n){
	NODE node=root;
    while(node!=NULL && node->start!=n){
        if(node->start>n) node=node->left;
        else node=node->right;
    }
    if(node==NULL) return 0;
    return node->length;
}
