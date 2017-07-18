#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  double total_error;
  /*
  * Coefficients
  */
  double Kp;
  double Ki;
  double Kd;
  // Initialization
  double Kp_;
  double Ki_;
  double Kd_;

  // Cross Track error
  double diff_cte;
  double int_cte;
  double prev_cte;
  double alpha;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
