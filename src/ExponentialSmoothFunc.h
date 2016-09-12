#ifndef EXPONENTIAL_SMOOTH_FUNC_H
#define EXPONENTIAL_SMOOTH_FUNC_H
#include <Arduino.h>

class ExponentialSmooth{
  private:
    const long RATE;
    long previousValueMul100;
  public:
    ExponentialSmooth(long reactRate);
    long operator()(long currentValue);
};

class IsCHANGED{
  private:
    long previousValue;
  public:
    IsCHANGED();
    boolean operator()(long currentValue);
};

class IsINCREASED{
  private:
    long previousValue;
  public:
    IsINCREASED();
    boolean operator()(long currentValue);
};

class IsDECREASED{
  private:
    long previousValue;
  public:
    IsDECREASED();
    boolean operator()(long currentValue);
};

#endif
