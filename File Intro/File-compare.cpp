 #include<iostream>
 #include<fstream>
 #include<cstring>
 using namespace std;
 
 int main(){
 	char line[500]; 
	char line2[500];	
	bool is_different = false;
	
 	ifstream fin1,fin2;
 	fin1.open("op1.txt");
 	fin2.open("op2.txt");
 	
 	while(fin1 && fin2){
		 fin1.getline(line,500);
		 fin2.getline(line2,500);
//		 cout << line << endl;
//		 cout << line2 << endl;
		 if(strcmp(line,line2)){		 	
		 	is_different = true;
		 	break;
		 }
	}
	
	if(is_different) cout << "differce found" << endl;
	else cout << "Duplicate data's on files" << endl;

 	return 0;
 }
