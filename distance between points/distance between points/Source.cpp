#include<iostream>

using namespace std;

double math(int pointax, int  pointay, int pointbx, int pointby);

int main() {
	int point1x;
	int point1y;
	int point2x;
	int point2y;

	cout << "please input an x point:" << endl;
	cin >> point1x;

	cout << "please input a y point:" << endl;
	cin >> point1y;

	cout << "please input an x point:" << endl;
	cin >> point2x;
	
	cout << "please input a y point:" << endl;
	cin >> point2y;
	

	cout << "The distance is:" << math(point1x,point1y, point2x, point2y) << endl;
	system("pause");
}

double math(int ax, int ay, int bx, int by) {
	double firstanswer;
	firstanswer = sqrt((bx - ax)*(bx - ax) + (by - ay)*(by - ay));
	return firstanswer;

}