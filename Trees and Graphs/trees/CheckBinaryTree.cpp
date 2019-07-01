#include<iostream>
#include<vector>
using namespace std;

struct bt{
	bt * left;
	bt * right;
	int data;
};
vector<int> datas;

void inorder(bt * r){
	if(r == NULL) return;
	else{
		inorder(r->left); 
		
		// If the given tree is binary search tree then the vector must have sorted data
		
		datas.push_back(r->data);
//		cout << r->data << " ";
		inorder(r->right);
	}
}

bt* getnewnode(int data){
	bt * a = new bt();
	a->left = NULL;
	a->right = NULL;
	a->data = data;
	return a;
}

bool CheckSorted(vector<int> d){
	for(int i = 0; i < d.size() - 1 ; i++){
		if(d[i] > d[i+1]){
			return false;
		}
	}
	return true;
}

bt* insert(bt * root,int data){
	if((root) == NULL){
		root = getnewnode(data);
	}
	else if (data <= root->data){
		root->left = insert(root->left,data);
	}
	else root->right = insert(root->right,data);
	return root;
}

int main(){
	bt * root = NULL;
	root = insert(root,10);
	root = insert(root,2);
	root = insert(root,12);
	root = insert(root,20);
	inorder(root);
	cout << "\nDatas in vector are :\n";
	for(int i = 0; i < datas.size(); i++){
		cout << datas[i] << " ";
	}
	if(CheckSorted(datas)){
		cout << "\nGiven tree is a binary search tree\n";
	}
	else{
		cout << "\n Not a binary search tree\n";
	}
	return 0;
}
