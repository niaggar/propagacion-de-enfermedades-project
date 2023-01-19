#include "Runge4.h"

Runge4::Runge4() {}

void Runge4::SetModel(Model *model)
{
    this->model = model;
}

double *Runge4::Calc(double t, double dt, double s, double i, double r)
{
    double *result = new double[3];

    k11 = model->Susceptible(t, s, i, r);
    k21 = model->Infected(t, s, i, r);
    k31 = model->Recovered(t, s, i, r);

    double tdt2 = t + dt / 2.0;

    k12 = model->Susceptible(tdt2, s + k11 * dt / 2.0, i + k21 * dt / 2.0, r + k31 * dt / 2.0);
    k22 = model->Infected(tdt2, s + k11 * dt / 2.0, i + k21 * dt / 2.0, r + k31 * dt / 2.0);
    k32 = model->Recovered(tdt2, s + k11 * dt / 2.0, i + k21 * dt / 2.0, r + k31 * dt / 2.0);

    k13 = model->Susceptible(tdt2, s + k21 * dt / 2.0, i + k22 * dt / 2.0, r + k32 * dt / 2.0);
    k23 = model->Infected(tdt2, s + k21 * dt / 2.0, i + k22 * dt / 2.0, r + k32 * dt / 2.0);
    k33 = model->Recovered(tdt2, s + k21 * dt / 2.0, i + k22 * dt / 2.0, r + k32 * dt / 2.0);

    double tdt = t + dt;

    k14 = model->Susceptible(tdt, s + k13 * dt, i + k23 * dt, r + k33 * dt);
    k24 = model->Infected(tdt, s + k13 * dt, i + k23 * dt, r + k33 * dt);
    k34 = model->Recovered(tdt, s + k13 * dt, i + k23 * dt, r + k33 * dt);

    double suc_t = s + (k11 + 2.0 * k12 + 2.0 * k13 + k14) * dt / 6.0;
    double inf_t = i + (k21 + 2.0 * k22 + 2.0 * k23 + k24) * dt / 6.0;
    double rec_t = r + (k31 + 2.0 * k32 + 2.0 * k33 + k34) * dt / 6.0;

    result[0] = suc_t;
    result[1] = inf_t;
    result[2] = rec_t;

    return result;
}

void Runge4::DoMethod(double t, double dt, double s, double i, double r, double tmax)
{
    int n = (int)(tmax / dt);
    double **result = new double *[4];

    for (int i = 0; i < 4; i++)
    {
        result[i] = new double[n];
    }

    int j = 0;
    result[0][j] = t;
    result[1][j] = s;
    result[2][j] = i;
    result[3][j] = r;

    while (t < tmax)
    {
        double *calc = Calc(t, dt, s, i, r);
        t += dt;
        s = calc[0];
        i = calc[1];
        r = calc[2];

        j++;
        result[0][j] = t;
        result[1][j] = s;
        result[2][j] = i;
        result[3][j] = r;
    }

    this->result = result;
    this->length = n;
}

double **Runge4::GetResult()
{
    return result;
}

double Runge4::GetLength()
{
    return length;
}
