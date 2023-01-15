
double RungeKutta4(double x, double y, double h, double (*f)(double, double));

double Suceptibles(double t, double s, double i, double r, double b, double k);
double Infectados(double t, double s, double i, double r, double b, double k);
double Recuperados(double t, double s, double i, double r, double b, double k);
