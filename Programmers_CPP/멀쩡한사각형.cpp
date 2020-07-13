using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	else
		return least(b, a % b);
}

long long solution(int w, int h) {
	long long answer = 1;
	int rA = 1, rB = 1;
	int temp = 1;
	long long diagonal = 1;

	if (w > h) {
		temp = gcd(w, h);
		rA = w / temp;
		rB = h / temp;
	}
	else if (w == h) {
		temp = w;
		rA = 1;
		rB = 1;
	}
	else {
		temp = gcd(h, w);
		rA = h / temp;
		rB = w / temp;
	}
	///
	if (rB == 1) //ÇÏ³ª°¡ 1
		diagonal = (long long)rA * temp;
	else
		diagonal = (long long)(rA + rB - 1) * temp;

	long long size = (long long)w * h;
	answer = size - diagonal;
	return answer;
}