#include <iostream>
#include <algorithm>
using namespace std;

char decompressed[24][24];
void decompress(string::iterator& it, int y, int x, int size) {
	char head = *it;	
	++it;

	if(head == 'b' || head == 'w') {
		for(int dy=0; dy<size; ++dy)
			for(int dx=0; dx<size; ++dx)
				decompressed[y+dy][x+dx] = head;

	} else {
		int half = size/2;
		decompress(it, y, x, half);
		decompress(it, y, x+half, half);
		decompress(it, y+half, x, half);
		decompress(it, y+half, x+half, half);
	}
}

int it;
string quadtree;

string reverse() {
	char head = quadtree[it];
	++it;
	
	if(head == 'b' || head == 'w')
		return string(1, head);

	string upperLeft = reverse();
	string upperRight = reverse();
	string lowerLeft = reverse();
	string lowerRight = reverse();
	
	return "x" + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
	int	cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		it = 0;
		cin >> quadtree;
		string::iterator it = quadtree.begin();
		cout << reverse() << "\n";
	}
	return 0;
}

