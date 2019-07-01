#include <bits/stdc++.h>

//to update a range with given value...

using namespace std;

vector<int> st;

vector<int> create(int size){

	int h = ceil(log2(size));
	int max = 2*pow(2,h) - 1;
	vector<int> tt(max,0);
	return tt;
}

int get_sum(int start, int end, int qs, int qe,int idx){
	if(qs > end || start > qe)		return 0;
	if(qs <= start && qe >= end)	return st[idx];
	int mid = start + (end - start)/2;
	return get_sum(start,mid,qs,qe,2*idx+1) + get_sum(mid+1,end,qs,qe,2*idx+2);
}

void update(int qs , int qe, int start,int end, int idx,int nv){

	if(start > qe || end < qs){
		return;
	}

	if(start == end){	
		st[idx] = nv;		
		return;
	}

	int mid = start + (end - start)/2;
	update(qs,qe,start,mid,2*idx+1,nv);
	update(qs,qe,mid+1,end,2*idx+2,nv);
	
	st[idx] = st[idx*2 + 1] + st[idx * 2 + 2];

}

int main() {
	
	vector<int> arr(5,0);
	int size = 5;

	st = create(size);

	cout << get_sum(0,size-1,3,4,0) << endl;

	//update index 2-4 to 10...
	for(int i = 2; i <= 4; i++) arr[i] = 10;

	update(2,4,0,size-1,0,10);

	for(int i = 0; i < size; i++) cout << arr[i] << " ";
	cout << endl;

	cout << get_sum(0,size-1,3,4,0) << endl;

	return 0;
}
