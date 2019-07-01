#include<iostream>
using namespace std;

struct bt{
	bt * left;
	bt * right;
	int data;
};

bool search(bt* root,int data){
	if(root == NULL){
		return false;
	}
	else if(root->data == data){
		return true;
	}
	else if (data <= root->data){
		return search(root->left,data);
	}
	else{
		return search(root->right,data);
	}
}

void insert(bt **sr, int data){
	if(*sr == NULL){
		*sr = new bt();
		(*sr)->left = NULL;
		(*sr)->right = NULL;
		(*sr)->data = data;
	}
	else if(data <= (*sr)->data){
		insert(&((*sr)->left),data);
	}
	else{
		insert(&((*sr)->right),data);
	}
	return;
}

void preorder(bt * r){
	if(r != NULL){
		cout << r->data << " ";
		preorder(r->left);
		preorder(r->right);
	}
}

void FindMax(bt * root){
	if(root != NULL){
		while(root->right != NULL){
			root = root->right;
		}
		cout <<  root->data << endl;
	}
	else{
	    cout << "NULL" << endl;
	}
}

/* Iterative way to find the min data in tree*/

//void FindMin(bt * root){
//	if(root != NULL){
//		while(root->left != NULL){
//			root = root->left;
//		}
//		cout <<  root->data << endl;
//	}
//	else{
//	    cout << "NULL" << endl;
//	}
//}

/*Recursive way to find the min data in tree*/

int FindMin(bt * root){
	if(root == NULL){
		cout << "Empty tree\n";
		return -1;
	}
	else if(root -> left == NULL){
		return root->data;
	}
	else
	return FindMin(root->left);
}

int height(bt* root){
	if(root == NULL){
		return -1;
	}
	else{
		int lheight = height(root->left);
		int rheight = height(root->right);
		return max(lheight,rheight) + 1;
	}
}

int main(){
     bt * root = NULL;
	 insert(&root,30);	
	 insert(&root,20);
	 insert(&root,10);
	 insert(&root,40);
	 insert(&root,05);
	 cout <<"Prorder traversal of tree\n";
	 preorder(root);
	 int data;
	 cout << endl << "Enter data to search : \t";
	 cin >> data;
	 if(search(root,data)){
	 	cout << "Found" << endl ;
	 }
	 else cout << "Not found" << endl;
	 cout << "Max data is  ";
	 FindMax(root);
	 cout << "Min data is ";
	 cout <<  FindMin(root) << endl;
	 cout <<  "Height of tree is  " << height(root);
	 return 0;
}
