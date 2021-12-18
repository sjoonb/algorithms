#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class State {
	vector<State> getAdjacent() const;
	bool operator<(const State& rhs) const;
	bool operator==(const State& rhs) const;
};

typedef map<State, int> StateMap;



int main() {
}


