#include "ExponentialSmoothFunc.h"

ExponentialSmooth::ExponentialSmooth(long reactRate): RATE(reactRate)
                                                    , previousValueMul100(0) {
}

long ExponentialSmooth::operator()(long currentValue){
  const long SMOOTHED_VALUE_MUL_100 = RATE * currentValue
                                    + (100 - RATE) * previousValueMul100 / 100
                                    + 1 ;
  previousValueMul100 = SMOOTHED_VALUE_MUL_100;
  return SMOOTHED_VALUE_MUL_100 / 100 ;
}

IsCHANGED::IsCHANGED(): previousValue(0) {
}

boolean IsCHANGED::operator()(long currentValue) {
  const boolean ANSWER = currentValue != previousValue;
  previousValue = currentValue;
  return ANSWER;
}

IsINCREASED::IsINCREASED(): previousValue(0) {
}

boolean IsINCREASED::operator()(long currentValue) {
  const boolean ANSWER = currentValue > previousValue;
  previousValue = currentValue;
  return ANSWER;
}

IsDECREASED::IsDECREASED(): previousValue(0) {
}

boolean IsDECREASED::operator()(long currentValue) {
  const boolean ANSWER = currentValue < previousValue;
  previousValue = currentValue;
  return ANSWER;
}
