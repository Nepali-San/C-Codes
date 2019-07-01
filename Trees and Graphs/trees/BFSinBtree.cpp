//Tree inserts the characters as data and traverses it in BFS and DFS...
#include<iostream>
#include<queue>
using namespace std;

struct bt{
	bt * left;
	bt * right;
	char data;
};

void insert(bt ** root, char data);
void BFS(bt * root);
void preorder(bt * root);
int height(bt * root);

int main(){
	
    bt * root = NULL;
    char  data;
    cout << "Enter any 7 characters:\n";
    for(int i = 0; i < 7; i++){
    	cin >> data;
        insert(&root,data);
	}
	cout << "BFS: \n";
	BFS(root);
	cout << endl;
	cout << "DFS(in-order):\n";
	preorder(root);
	cout << endl << "Height of tree is : " << height(root);
	return 0;	
}

void BFS(bt * root){
	if(root == NULL) return ;
	queue<bt *> Q;
	Q.push(root);
	while(!Q.empty()){
		bt * current = Q.front();
		cout << current->data << " ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
		Q.pop();
	}
}

void insert(bt ** r, char data){
	if(*r == NULL){
		(*r) = new bt();
		(*r)->data = data;
		(*r)->left = NULL;
		(*r)->right = NULL;
	}
	else if ( data <= (*r)->data){
		insert(&((*r)->left),data);
	}
	else
	insert(&((*r)->right),data);
}

void preorder(bt * root){
	if(root == NULL) return;
	preorder(root->left);
	cout << root->data << " ";
	preorder(root->right);
}

int height(bt * root){
	if (root == NULL){
		return -1;
	}
	int Lheight = height(root->left);
	int Rheight = height(root->right);
	int ans =  Lheight > Rheight ? Lheight : Rheight;
	return ans+1;
}
