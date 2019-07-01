#include<iostream>
using namespace std;

class Matrix{
	private:
	int **p;
	int d1,d2;
	public:
		Matrix(int x, int y);	
		void get_element(int i, int j , int value);
		int & put_element(int i, int j);
		~Matrix();
};

inline int & Matrix::put_element(int i, int j){
			return p[i][j];
		}

inline void Matrix::get_element(int i, int j , int value){
			p[i][j] = value;
		}

Matrix::Matrix(int x , int y){
	d1 = x; d2 = y;
	p = new int * [d1];
	for(int i = 0; i < d1; i++){
		p[i] = new int [d2];
	}
}

//Using destructor to free allocated memory
Matrix::~Matrix(){
	for(int i = 0; i < d1; i++){
		delete p[i];
	}
	delete p;
}

int main(){
	int m, n;
	cout << "Enter the size of matrix ";
	cin >> m >> n;
	Matrix mat(m,n);
	cout << "Enter matrix elements row by row\n";
	int value;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> value;
			mat.get_element(i,j,value);
		}
	}
	//cout << "\n mat[2][2] = " << mat.put_element(2,2);
}
