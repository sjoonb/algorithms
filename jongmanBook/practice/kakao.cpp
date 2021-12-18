#include <iostream>
#include <vector>
using namespace std;


const string dayName[7] = {"mon", "tue", "wen", "thu", "fri", "sat", "sun"};
const string people[10] = { "kkm", "krh", "bsj", "byr", "sjw", "ljh", "jsb", "cye", "cyh", "chb" };
const bool canCome[7][10] = { {1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
							{0, 0, 1, 1, 0, 0, 0, 0, 0, 1},
							{1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
							{1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
							{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							{1, 0, 0, 1, 0, 0, 1, 1, 0, 0},
							{0, 0, 1, 0, 0, 0, 1, 1, 0, 0} };
int participated[10];

vector<vector<int> > comb;

void solve(int days, vector<int>& ret) {
	if(days == 0) {
		for(int i=0; i<10; ++i) 	
			if(participated[i] == false) {
				return;
			}
				
		for(int i=0; i<ret.size(); ++i) {
			cout << dayName[ret[i]] << " ";
		}
		cout << "\n";
		for(int i=0; i<10; ++i) {
			cout << people[i] << ": " << participated[i] << " / ";
		}
		cout << "\n";

		comb.push_back(ret);
		return;
	}
	int day = 0;
	if(!ret.empty())
		day = ret.back() + 1;	
	for(; day<7; ++day) {
		for(int entry=0; entry<10; ++entry) {
			if(canCome[day][entry])
				participated[entry]++;			
		}
		ret.push_back(day);
		solve(days-1, ret);
		for(int entry=0; entry<10; ++entry) {
			if(canCome[day][entry])
				participated[entry]--;			
		}
		ret.pop_back();
	}
}

int main() {
	memset(participated, 0, sizeof(participated));
	participated[1] = 1;
	participated[8] = 1;
	comb = vector<vector<int> >();
	vector<int> ret;
	solve(4, ret);
//	for(int i=0; i<comb.size(); ++i) {
//		for(int j=0; j<comb[i].size(); ++j) {
//			cout << dayName[comb[i][j]] << " ";		
//		}
//		cout << "\n";
//	}
}
