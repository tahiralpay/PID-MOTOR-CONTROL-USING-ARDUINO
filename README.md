# PID-MOTOR-CONTROL-USING-ARDUINO

PID is a method of minimizing the error value of the control signal obtained by feedback and reference, which is generally used by industrial systems.

The difference between the reference value entered into the system and the output of the process is taken. This difference is called an error.

P control is obtained by multiplying the obtained error value with the kp coefficient. This control type is used in open-loop systems, that is, in systems where a direct output is required when energy is applied to the system. This control type has a steady state error. If the control signal is excessive, kp is high.

PI control is obtained by multiplying the integral of the error by the coefficient ki and adding it with the P control. This control type is used in systems where the steady state error is required to be reduced to zero. If the control signal does not fit the setpoint value (in case the steady state error is not equal to zero), it indicates that the value of ki is low. Therefore, it can be said that when a PI control is applied to a system, there can be no steady state error (if the coefficient is of sufficient value).

PID control is obtained by multiplying the derivative of the error with the coefficient kd and summing it with the PI control. This type of control is used in systems where the system response is slow and it is desired to increase the transient performance. In systems where the system response is fast, PID is not preferred because it causes the system to work on-off.

![Adsız](https://user-images.githubusercontent.com/75435070/214575535-238b204a-d7a5-46ad-b139-d5638fba121d.png)

## Circuit Diagram
![DEVRE SEMASI](https://user-images.githubusercontent.com/75435070/214575604-359a8bdc-2e55-461e-bc0a-aca0eac7c92e.png)
