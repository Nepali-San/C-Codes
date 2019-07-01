#include<iostream>
#include<set>

using namespace std;

//auto = set<int> :: iterator it = 

//sets sorts the data on insertion i.e. it uses binary tree so search is fast 
//and no need to sort manually
int main(){
	cout << "\nOrdered set\n\n";
	set<int> st;
	
	for(int i = 10; i >=1; i--)
	    st.insert(i);
	    
	cout << "output :: \n";
	
	for(auto it = st.begin(); it != st.end(); it++){
		cout << *it << " ";
	}    
	
	// to search a data from set
	auto it = st.find(4);
	
	cout << "\n\nFound element : " << *it << endl;
	
	// to delete the searched data
	st.erase(it);
	
	 
	// set contains only unique values so repeated data are ignored for more than one time
	st.insert(1);
	st.insert(1);
	cout << "\nAfter deleting the 4 and inserting 1 three times:\n";
	for(auto it = st.begin(); it != st.end(); it++){
		cout << *it << " ";
	}
	
	
	// Multiset
	cout << "\n\n Multiset allows repeated datas\n\n";
	multiset<int> a;
	a.insert(1);
	a.insert(2);
	a.insert(1);
	a.insert(2);
	cout << "Multiset ->  ";
	for(auto it = a.begin(); it != a.end(); it++){
		cout << *it << " ";
	}
	return 0;
}
