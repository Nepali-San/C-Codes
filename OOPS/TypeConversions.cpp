/*
Type conversions:
	1.basic to class (by constructor)
	2.class to basic (by casting operator)
	3.one class to another class ( by casting operator in src class , or constructor in dest class)
*/

#include<iostream>
using namespace std;

//incase if we use casting operator for one class to another class conversion we must declare dest class

//Our source class
class Ticket{
	int no_of_passenger = 0;
	float ticket_price = 0;
	int dest_no = 0;
	
	public:
	Ticket(){}
	
	//we may use initalization list or assign inside block or do both in constructor
	Ticket(int x, float y ,int z):no_of_passenger(x),ticket_price(y){
		dest_no = z;  //may use this also in intialization list
		//or assign the data inside this block; block can be empty
	}
	
	int get_passenger_no(){return no_of_passenger;}
	float get_price(){return ticket_price;}
	int get_dest(){return dest_no;}
	
	operator float(){ return no_of_passenger * ticket_price;}  
	//if we assign the object to float data type by = operator float() is called
	//i.e. float a = object_of_Ticket; //this is class to basic type conversion
	
	
	 
	//this is same as float , or operator overloading for unary operator but
	//Action of converting to another class is performed by using constructor in another class 

//		operator Counter_info(){            //using casting operator but declare dest class first
//			float f = get_price() * get_passenger_no();
//			int dest = get_dest();
//			Counter_info temp(dest_no,f); //creating the object
//			return temp;
//		}
	
};

//Our dest class
class Counter_info{
	int dest_no;
	float total_value;
	public:
		Counter_info(){ dest_no = 0; total_value = 0;}
		Counter_info(int x, float y):dest_no(x),total_value(y){}
		Counter_info(Ticket &t){        //use instead of casting operator but declare src class first
			dest_no = t.get_dest();
			total_value = t.get_price() * t.get_passenger_no();
		}
		void show_data(){
			cout << "dest_no : " << dest_no << endl;
			cout << "total_value : " << total_value << endl;
		}		
};

int main(){
	Ticket t1(2,1.5,2);  //this constructor converts basic type(int,float) into class type (dest_no,ticket_price)
	
	float total_price; 
	total_price = t1;   //here we convert class to basic type
	//or total_price = (float) t1;
	cout <<  total_price << endl;
	
	Counter_info i = t1;  //here we perform one class to another class type conversion	
	i.show_data();
	
	return 0;
}
