//segment Tree to find the max value in a given segment...

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int getMid(int start, int end){
	return start+(end-start)/2;
}

int constructUtil(int arr[],int* st, int size, int start, int end,int idx){
	if(start == end){
		st[idx] = arr[start];
		return arr[start];
	}

	int mid = getMid(start,end);

	st[idx] =
				  constructUtil(arr,st,size,start,mid,2*idx+1)^
			      constructUtil(arr,st,size,mid+1,end,2*idx+2);			 

	return st[idx];	
}


int* construct(int arr[],int size){
	int h = ceil(log2(size));
	int m = 2* pow(2,h) -1;
	int *st = new int[m];

	constructUtil(arr,st,size-1,0,size-1,0);

	return st;
}

int getmax(int* st, int qs , int qe,int start,int end,int idx){
	if(qs <= start && qe >= end ){
		return st[idx];
	}
	if(qs > end || qe < start) return 0;
	int mid = getMid(start,end);

	return getmax(st,qs,qe,start,mid,2*idx+1) ^
				getmax(st,qs,qe,mid+1,end,2*idx+2);
			
}


int main(){
	
	int t;
	cin >> t;

	while(t--){
		int s;
		cin >> s;
		int arr[s];
		int data;
		for(int i = 0; i < s; i++){		
			cin >> data;
			arr[i] = data;
		}	

		int* st = construct(arr,s);	
		
		int q;
		cin >> q;
		while(q--){
			int l,r;
			cin >> l >> r;
			cout << getmax(st,l,r,0,s-1,0) << endl;
		}
	}

	return 0;
}

