#include <iostream>
#include <cmath>

using namespace std;

double dif_finita(double x1, double y1, double x2, double y2) {
  return (y2 - y1)/(x2 - x1);
}

void newton(double *x, double *y, int n, double value) {

	cout << "x\ty\n=============" << endl;
	for(int i = 0; i < n; i++){
		cout << x[i] << "\t" << y[i] << endl;
	}
	cout << "\nNewton\n" << "==============================" << endl;
	double *res = new double[n - 1];
	double *_final = new double[n - 1];


  for(int i = 0; i < n; i++){
    res[i] = y[i];
  }

  _final[0] = res[0];

  cout << "b["<< 0 << "] = " << _final[0] << endl;

  for(int j = 1; j < n; j++){
    for(int i = 0; i < n - j; i++){
      res[i] = dif_finita(x[i], res[i], x[i+j], res[i+1]);
    }
    _final[j] = res[0];
    cout << "b["<< j << "] = " << _final[j] << endl;
  }

  double y_aprox = 0;
  double x_prod = 0;
  for(int i = 0; i < n; i++){
    x_prod = _final[i];
    for(int j = 0; j < i; j++){
      x_prod *= (value - x[j]);
    }
    y_aprox += x_prod;
  }

  cout << endl << "Polynomial\n==============================" << endl;

  cout << "f(x) = ";
  for(int i = 0; i < n; i++){
	  cout << _final[i];
	  for(int j = 0; j < i; j++){
		  cout << "(x - " << x[j] <<  ")";
	  }
	  if(i < n - 1){
		  cout << " + ";
	  }
  }
  cout << endl << endl << "==============================" << endl;

  cout << "f("<< value <<") = " << y_aprox << endl;
}

int main() {
  int n = 4;
  double x[] = { 2,6,8,10};
  double y[] = {0.69314718056,1.79175946923,2.07944154168,2.30258509299};

  newton(x, y, n, 4);

  return 0;
}

//En an�lisis num�rico, el polinomio de Lagrange, llamado as� en honor a Joseph-Louis de Lagrange, es una forma de presentar el polinomio que interpola un conjunto de puntos dado.
//El polinomio de interpolaci�n de Lagrange, simplemente es una reformulaci�n del polinomio de Newton que evita los c�lculos de las diferencias divididas.

