#include<iostream>

using namespace std;

bool math(int a, int b, int c);

int main() {
	int side1;
	int side2;
	int side3;
	cout << "please input a side:" << endl;
	cin >> side1;
	cout << "please input a side:" << endl;
	cin >> side2;
	cout << "please input a side:" << endl;
	cin >> side3;

	cout << "the triangle is a right triangle? 0 = false, 1 = true: "<<math(side1,side2,side3) << endl;
	system("pause");
}

bool math(int a, int b, int c) {
	int firstanswer;
	int secondanswer;

	firstanswer = (a^2) + (b^2);
	secondanswer = c ^ 2;
	if (firstanswer == secondanswer) {
		return true;
	}
	else {
		return false;
	}
}