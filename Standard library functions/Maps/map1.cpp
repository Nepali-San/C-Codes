#include<iostream>
#include<map>

using namespace std;
int main(){
	// Let's create a map with key int and data int;
	
	map<int,int> dictionary;  // name of the map is dictionary;
	
	dictionary.insert(make_pair(1,2)); //way to insert a data (d =2 ) with key (k = 1)
	dictionary.insert(make_pair(2,21));
	dictionary.insert(pair<int,int>(9,0)); //other way to insert
	dictionary[3] = 12;   //Also maps are associative containers so next way to insert data
	dictionary.insert(make_pair(10,21)); //No duplicate key are allowed if used duplicate keys previous values are replace;
	
	cout << dictionary[3] << endl << endl << endl;
	
	//let's iterate the map
	
	for(map<int,int>::iterator it = dictionary.begin(); it != dictionary.end(); it++){
		cout << "dictionary[ " << it->first << " ] = " << it->second << endl;
	}
	
	// size of map
	cout << endl << "size = " << dictionary.size() << endl;
	//let's clear the map
	dictionary.clear();
	//to check if map is empty
	bool emp = dictionary.empty();
	cout << "\n\n" << emp << endl  << endl;
	
	map<string,string> animals;
	animals["cat"] = "small";
	animals["elephant"] = "big";
	animals.insert(pair<string,string>("horse","medium"));
	for(auto it = animals.begin(); it != animals.end(); it++){
		cout << "Size of " << it->first << " is " << it->second << endl;
	}
	
	emp = animals.empty();
	cout << "\n\n" << emp << endl << endl << endl;
	
	auto it = animals.find("cat");
	cout << it->second << endl << endl;
	
	//to delete a element of map use above it and then..
	animals.erase(it);
	
	//After deletint the data for cat
	for(auto it = animals.begin(); it != animals.end(); it++){
		cout << "Size of " << it->first << " is " << it->second << endl;
	}
	
	
	animals.clear();
	
	return 0;
}
