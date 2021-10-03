#include<iostream>
#define INF 20001;

using namespace std;


int main() {
	int x1, x2, x3, y1, y2, y3;
	int a1 = INF;
	int a2 = INF; //±â¿ï±â
	int ans;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	x2 -= x1;
	y2 -= y1;
	x3 -= x1;
	y3 -= y1;

	//check the points are on same line
	if (x2 == x3 && !x2) {
		cout << "0";
		return 0;
	}
	if (x2) a1 = y2 / x2;
	if (x3) a2 = y3 / x3;

	if (a1 == a2) {
		cout << "0";
		return 0;
	}


	//check clockwise or not
	if (x2 == 0) {
		ans = -y2 * x3;
	}
	else if (y2 == 0) {
		ans = x2 * y3;
	}
	else {
		if (y3 < a1*x3) ans = -1;
		else ans = 1;

		if (x2 < 0) ans *= -1;
	}
	
	//if (!x3) {
	//	if(y3<0) ans = -1;
	//	else ans = 1;
	//}
	//else if (y3 < a1*x3) {
	//	ans = -1;
	//}
	//else ans = 1;

	//if (!a1) ans = x2 * y3;
	//else if (a1 * a1 * x2 < 0) {
	//	ans *= -1;
	//}

	cout << ans;
}
