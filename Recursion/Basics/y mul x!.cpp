#include<bits/stdc++.h>
using namespace std;

int Accx(int x , int y){
	if(x < 1) return y;
	return Accx(x-1,x*y);	
}

int main(){
	int x , y;
	cin >> x >> y;
	cout << Accx(x,y);
	return 0;
}
