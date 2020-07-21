#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(int a, int b) {
	long long A = a;
	long long B = b;
	return ((A + B) * (abs(A - B) + 1) / 2);
}