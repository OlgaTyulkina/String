#include <iostream>
#include "String.h"
#include <array>
using namespace std;

int main() {
	TString A;
	TString B("const");
	TString C(B);
	cout << B.get_s() << " access to the field" << endl;
	cout << C.get_s() << " access to the field" << endl;
	C.set_s("access to the field");
	cout << C << endl;
	TString D;
	D = B + C;
	cout << D << " operator +" << endl;
	TString E("sdsdsd");
	TString F("sdsdsd");
	cout << (F == E) << " operator ==" << endl;
	cout << (B == C) << " operator ==" << endl;
	E.set_s("sdsd");
	F.set_s("s");
	cout << (E < F) << " operator <" << endl;
	cout << (F > E) << " operator >" << endl;
	cout << F[0] << " operator []" << endl;
	TString x;
	cin >> x;
	cout << x.find("_c") << endl;
	cout << x.find_c("z") << endl;
	TString* arr;
	arr = x.Tstrtok("_");
	for (int i = 0; i < sizeof(arr) - 1; i++)
		cout << arr[i] << " ";
	cout << "Enter number of repeat: " << endl;
	int number;
	cin >> number;
	TString repeat;
	x = repeat.repeater(x, number);
	cout << x << endl;
	return 0;
}
