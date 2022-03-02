#include <iostream>
#include <algorithm>
using namespace std;

long long solution(int price, int money, int count)
{
	long long sum = (long long) ((count * (count + 1)) / 2) * price;
	long long ret = sum - money;

	return max(ret, (long long) 0);
}
