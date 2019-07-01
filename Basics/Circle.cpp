#include<iostream>
using namespace std;


class Circle{
	public:
	float perimeter(int radius){
		float p = 2 * 3.1415 * radius;
		return p;
	}
	
	float area(int radius){
		float a = 3.1415 * radius * radius;
		return a;
	}
	
};

int main(){
	Circle c;
	float r;
	cout << "Enter the radius of circle : ";
	cin >> r;
	cout << "The perimeter of circle is " << c.perimeter(r) << endl;
	cout << "The area of circle is " << c.area(r) << endl;
}
