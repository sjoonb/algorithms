#include <iostream>
using namespace std;

double balance(double amount, int duration, double rates, double monthlyPayment) {
	double balance = amount;
	for(int i=0; i<duration; ++i) {
		balance *= (1.0 + (rates / 12.0) / 100.0);		
		balance -= monthlyPayment;
	}
	return balance;
}

double payment(double amount, int duration, double rates) {
	double lo = 0, hi = amount * (1.0 + (rates / 12.0) / 100.0);	
	for(int iter=0; iter<100; ++iter) {
		double mid = (lo + hi) / 2.0;
		if(balance(amount, duration, rates, mid) <= 0)
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(8);
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		double n, p;
		int m;
		cin >> n >> m >> p;
		cout << fixed << payment(n, m, p) << "\n";
	}
}
