#include<iostream>
using namespace std;

template<class T>
class vector{
	T *v;
	int size;
	public:
	
		vector(int m){              //intialize m elements as 0
			v = new T[size = m];
			for(int i = 0; i < size; i++) v[i] = 0;
		}
		
//		vector(T *a){             //intialize vector with array
//			for(int i = 0; i < size; i++){
//				v[i] = a[i];
//			}
//		}
		
	    T at(int index){        //to get value of vector at given index
	    	if(index < size) return v[index];
	    	else return 0;
		}
		
		T operator*(vector &y){         //for scalar product
			T sum = 0;
			for(int i = 0; i < size; i++){
				sum += this->v[i] * y.v[i];
			}
			return sum;
		}
		
		void operator=(T *a){      //intialize vector with other vector/array
			for(int i =0 ; i < size; i++){
				this->v[i] = a[i];
			}
		}
		
};

int main(){
	float x[3] = {3.45,6.2,9.11};
	float y[3] = {1.01,7.77,2.0};
	vector<float> v1(3);
	vector<float> v2(3);
   
   v1 = x;
   v2 = y;
   
   cout << v1 * v2 << endl;
    return 0;
}
