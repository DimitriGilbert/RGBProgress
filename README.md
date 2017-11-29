# RGBProgress
C++ library for arduino to calculate an RGB color according to a progression

## Usage
### Basic
<pre>
'''
#include "RGBProgress.h"

// get a progress calculator 
RGBProgress rgbp(0, 100);
...
int myRGB[3] {
    // Red
    0,
    // Green
    0,
    // Blue
    0
}

rgbp.Rgb(27, myRGB);
// myRGB now contains the value coding for the color corresponding to 27%
'''
</pre>

### Set value range

<pre>
'''
#include "RGBProgress.h"

// get a progress calculator 
RGBProgress rgbp(
    [any float value inferior to the next param],
    [any float value superior to the previous param]
);
...
'''
</pre>

### Set color order

<pre>
'''
#include "RGBProgress.h"

// get a progress calculator 
RGBProgress rgbp(0, 100);

void setup()
{
    rgbp.setColorProgression(RGBProgress::R, RGBProgress::G, RGBProgress::B);
    // or 
    // rgbp.setColorProgression(RGBProgress::G, RGBProgress::R, RGBProgress::B);
}
'''
</pre>

### Set progression steps
all progression steps are describe using values between 0 and 1

<pre>
'''
#include "RGBProgress.h"

// get a progress calculator 
RGBProgress rgbp(0, 100);

void setup()
{
    // first color cut off
    // here for values above 50
    rgbp.setProgression_StartDecrementUntil_(0.5);
    // second color start
    // value above 20
    rgbp.setProgression_MediumStart_(0.2);
    //second color stop
    // value above 80
    rgbp.setProgression_MediumStop_(0.8);
    //second color peak
    // peak at 50
    rgbp.setProgression_MediumMax_(0.5);
    // last color start
    // start at 50
    rgbp.setProgression_FinishIncrementFrom_(0.5);
}
'''
</pre>