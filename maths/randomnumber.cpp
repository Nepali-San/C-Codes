#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int random(int i, int j) {
	return (rand() % j) + i;
}
int main() {
	srand(time(NULL));
	for(int i = 1; i <= 1000; i ++) {
		cout << random(0, 8) << " " << random(0,8) << endl;	
	}
	return 0;
}
