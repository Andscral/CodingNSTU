#include <iostream>
#include <cmath>
using namespace std;
class Imaginary {
public:
	double Real = 0;
	double Imag = 0;
	void Get() {
		if (Imag > 0) {
			cout << Real << " + " << Imag << "i" << endl;
		}
		else
			cout << Real << endl;
	}
	void Set(double R, double I) {
		Real = R;
		Imag = I;
	}
	char* to_string() {
		int n = floor(log10(abs(Real))) + floor(log10(abs(Imag))) + 13;
		char* string = new char[n];
		if (Imag > 0) {
			sprintf_s(string, n, "%0.2f + %0.2fi", Real, Imag);
		}
		else if (Imag = 0) {
			sprintf_s(string, n, "%0.2f", Real);
		}
		else {
			sprintf_s(string, n, "%0.2f - %0.2fi", Real, Imag);
		}
		return string;
	}
	Imaginary sum(Imaginary A, Imaginary B) {
		double new_real = A.Real + B.Real;
		double new_imaginary = A.Imag + B.Imag;
		Imaginary C;
		C.Set(new_real, new_imaginary);
		return C;
	}
	Imaginary substruct(Imaginary A, Imaginary B) {
		double new_real = A.Real - B.Real;
		double new_imaginary = A.Imag - B.Imag;
		Imaginary C;
		C.Set(new_real, new_imaginary);
		return C;
	}
	Imaginary multiplicate(Imaginary A, Imaginary B) {
		double new_real = A.Real * B.Real - A.Imag * B.Imag;
		double new_imaginary = A.Imag * B.Real + A.Real * B.Imag;
		Imaginary C;
		C.Set(new_real, new_imaginary);
		return C;
	}
	Imaginary divide(Imaginary A, Imaginary B) {
		double new_real = (A.Real * B.Real + A.Imag * B.Imag) / (B.Real * B.Real + B.Imag * B.Imag);
		double new_imaginary = (A.Imag * B.Real - A.Real * B.Imag) / (B.Real * B.Real + B.Imag * B.Imag);
		Imaginary C;
		C.Set(new_real, new_imaginary);
		return C;
	}
};