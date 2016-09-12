#ExponentialSmoothFunc for Arduino
Functions for smoothing data, especially good for analogRead().
##Description
ExponentialSmoothFunc has 4 simple function objects.

+ "ExponentialSmooth" : returns exponential moving average from incoming data.
+ "IsCHANGED" : returns whether incoming data is changed from previous data.
+ "IsINCREASED" : returns whether incoming data is larger than previous data.
+ "IsDECREASED" : returns whether incoming data is less than previous data.


##Installation
[Download ZIP](https://github.com/ttatsf/ExponentialSmoothFunc/archive/master.zip) and [follow instructions here.](https://www.arduino.cc/en/Guide/Libraries)

##Typical usage
As these are "function" objects, you can(and have to) handle each instance as  "function" directly.


```
#include <ExponentialSmoothFunc.h>

//  set reaction rate :
const long REACT_RATE_0 = 5;  // from 0 (no reaction)
                            //  up to 100 (just current data, no average)

//  Instantiate function objects :
ExponentialSmooth exponentialSmooth0(REACT_RATE_0);
IsCHANGED isCHANGED0;  

//  set reaction rate :
const long REACT_RATE = 5;

//  Instantiate object arrays :
ExponentialSmooth exponentialSmooth[4] = { REACT_RATE
                                          , REACT_RATE
                                          , REACT_RATE
                                          , REACT_RATE
                                        };
IsCHANGED isCHANGED[4];

const int PIN_0 = 5;
const int PIN[4]={0,1,2,3};

void setup(){
//...//
}
void loop(){
  //  regular pattern :
  const int RAW_DATA = analogRead(PIN_0);
  const int SMOOTHED_DATA = exponentialSmooth0(RAW_DATA);
  if (isCHANGED0(SMOOTHED_DATA)) {

    //  Do anything you want only when the data changed.

  }

  //  regular pattern for array :
  for (int i = 0; i < 4; i++) {
    const int RAW_DATA = analogRead(PIN[i]);
    const int SMOOTHED_DATA = exponentialSmooth[i](RAW_DATA);
    if (isCHANGED[i](SMOOTHED_DATA)) {

      //  Do anything you want only when the data changed.

    }
  }
  delay(10);
}
```




#License
This code is available under the [MIT License](http://opensource.org/licenses/mit-license.php).
