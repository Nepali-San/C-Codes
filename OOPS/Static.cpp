#include<iostream>
using namespace std;

class Static{
	int var1,var2;
	static int count;  //count is static and private
	public:
		void getdata(int a , int b){
			var1 = a , var2 = b;
			count++;
		}
		void putdata(){
			cout << var1 << " " << var2 << endl;
		}
		void getcount(){   //to get the count
			cout << "count = " << count << endl;
		}
		static void inr_count(){  //Static method can have only static properties(func or var)
			count = count + 10;
		}
};

int Static::count;

int main(){
	Static s , a, t;
	
	s.getdata(4,30);  //After each getdata() , count is increamented;
	t.getdata(5,20);
	a.getdata(4,20);
	
	s.putdata();
	t.putdata();
	
	t.getcount();          //count is same for all objects(s,a,t)
	
	Static::inr_count();  //Increases count by 10 using static function
	s.getcount();
	
	return 0;
}
