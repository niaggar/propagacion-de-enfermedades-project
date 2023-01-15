#include <functional>

using namespace std;

class Runge4
{
private:
    double k11, k12, k13, k14;
    double k21, k22, k23, k24;
    double k31, k32, k33, k34;
    double b, k;
    function<double(double, double, double, double, double, double)> f1;
    function<double(double, double, double, double, double, double)> f2;
    function<double(double, double, double, double, double, double)> f3;

public:
    Runge4(double, double, function<double(double, double, double, double, double, double)>, function<double(double, double, double, double, double, double)>, function<double(double, double, double, double, double, double)>);
    double *Calc(double, double, double, double, double);
};
