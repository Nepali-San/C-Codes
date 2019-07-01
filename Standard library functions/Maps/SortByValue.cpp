//  Counts the occurence of letters in given number of strings and displays 
//  them in sorted order of their count
//  If both have same number of count put them in alphabeticall order 
//  i.e. if both A and U have count 1 then list A first .
//  Sample input given below...

/*
3
Hello how are you?
what !!!
okay got it.
*/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

struct mapper{
	char c;
	int in;
};

//int mycomp(const void *a , const void *b){
//	struct mapper *a1 = (struct mapper *) a;
//	struct mapper *b1 = (struct mapper *) b;
//	return a1->i <= b1->i;
//}

void sort(struct mapper datas[],int size){
	int temp; 
	char temps;
	for(int i = 0; i < size - 1; i++){
		for(int j = i+1; j < size ;j++){
			//Sorts accoriding to count
			if(datas[i].in < datas[j].in){
				temp = datas[i].in;
				temps = datas[i].c;
				datas[i].in = datas[j].in;
				datas[i].c = datas[j].c;
				datas[j].in  = temp;
				datas[j].c = temps;
				
			}
			//For same count sort accoriding to alphabets
			else if(datas[i].c > datas[j].c && datas[i].in == datas[j].in){
				temp = datas[i].in;
				temps = datas[i].c;
				datas[i].in = datas[j].in;
				datas[i].c = datas[j].c;
				datas[j].in  = temp;
				datas[j].c = temps;
			}
			
		}
	}
	for(int j = 0; j < size; j++){
 	cout << datas[j].c << " " << datas[j].in << endl;
 }
}

int main(){
	
	int n;
	cin >> n;
	
	string s;
	map<char,int> data;
	vector<int> vec;
	
	cin.ignore();
	for(int i = 1; i <= n; i++){
		getline(cin,s);
	  for(int j = 0; j < s.size(); j++){
	  	if(isalpha(s[j])){
	  	 s[j] = toupper(s[j]);
	     if(data.find(s[j]) != data.end()){
	     	data[s[j]]++;
		 }
		 else{
		 	data.insert(make_pair(s[j],1));
		 }	
		  }
	  }
  }
  int size  = data.size();
  mapper datas[size];
  int j = 0;
  for(map<char,int>::iterator it = data.begin(); it != data.end(); it++){
  //	cout << it->first << " " << it->second << endl;
    datas[j].c = it->first;
    datas[j].in = it->second;
    j++;
  }
 
 // qsort(datas,size,sizeof(datas[0]),mycomp);
 sort(datas,size);
  
// for(int j = 0; j < data.size(); j++){
// 	cout << datas[j].c << " " << datas[j].in << endl;
// }
  return 0;
}
