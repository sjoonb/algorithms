#include <iostream>
using namespace std;

void sovle() {
	int max = 0;
	int current = 0;
	for(int i=0; i<10; ++i) {
		int out, in;
		cin >> out >> in;
		current -= out;
		current += in;
		if(current > max)
			max = current;
	}
	printf("%d", max);
}

int main() {
	sovle();	
}
