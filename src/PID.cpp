#include <cstddef>
#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
	this->Kp = Kp_;
	this->Ki = Ki_;
	this->Kd = Kd_;

	this->p_error = NULL;
	this->d_error = NULL;
	this->i_error = 0.0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
	if (this->p_error == NULL)
		this->p_error = cte;
	d_error = cte - p_error;
	i_error += cte;
	p_error = cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
	double ret;
	ret = this->Kp * this->p_error + this->Kd * this->d_error + this->Ki * this->i_error;
   return -ret;  // TODO: Add your total error calc here!
}