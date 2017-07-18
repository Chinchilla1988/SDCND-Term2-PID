#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {

    prev_cte=0;
    int_cte=0;
    diff_cte=0;

    p_error=0;
    i_error=0;
    d_error=0;

    total_error=0;

    Kp=Kp_;
    Ki=Ki_;
    Kd=Kd_;

    return;
}

void PID::UpdateError(double cte) {

    i_error+=cte;
    d_error=cte-p_error;
    p_error=cte;

    return;
}

double PID::TotalError() {

    total_error=-Kp*p_error-Kd*d_error-Ki*i_error;

    return total_error;
}

