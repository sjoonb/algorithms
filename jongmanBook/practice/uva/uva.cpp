#include <iostream>
#include <vector>
using namespace std;

double t;
vector<double> runSpeed, cycleSpeed;

double time(int i, double run) {
	double cycle = t - run;
	return run / runSpeed[i] + cycle / cycleSpeed[i];
}

double diff(double r) {
	int n = runSpeed.size();
	double cheater = time(n-1, r);
	double others = time(0, r);
	for(int i=1; i<n-1; ++i)
		others = min(others, time(i, r));
	return others - cheater;
}

double maxDifference() {
	double lo = 0, hi = t;	
	for(int it=0; it<100; ++it) {
		double aab = (2*lo + hi) / 3;
		double abb = (lo + 2*hi) / 3;
		if(diff(aab) > diff(abb))
			hi = abb;
		else 
			lo = aab;
	}
	return (lo+hi)/2;
}
