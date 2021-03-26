#include "sensor-validate.h"

int CheckSuddenJump(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 0;
  }
  return 1;
}

int validateSOCreadings(double* values, int numOfValues, double maxDelta) {
  int lastButOneIndex = numOfValues - 1;
  for(int i = 0; i < lastButOneIndex; i++) {
    if(!CheckSuddenJump(values[i], values[i + 1], maxDelta)) {
      return 0;
    }
  }
  return 1;
}

int validateCurrentreadings(double* values, int numOfValues, double maxDelta) {
  int lastButOneIndex = numOfValues - 1;
  int returnvalue = 1;
  if(values != 0)
  {
      returnvalue = validateSOCreadings(values,lastButOneIndex,maxDelta);
  }
  return returnvalue;
}
