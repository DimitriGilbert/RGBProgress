#include "RGBProgress.h"

// get a progress calculator for temperature
// range from -25C (brrr) to 60C (quiet hot indeed...)
RGBProgress temperatureProgress(-25, 60);

// get a progress calculator for humidity
// range from 10% (sandish) to 95% (not quiet swimming)
RGBProgress humidityProgress(10, 95);

void setup()
{
    // set humidity color progression to red->green->blue
    humidityProgress.setColorProgression(
        RGBProgress::R,
        RGBProgress::G, 
        RGBProgress::B
    );

    // set red decrement limit to 37%
    humidityProgress.setProgression_StartDecrementUntil_(0.37);
    // start green increment at 35% of the range
    humidityProgress.setProgression_MediumStart_(0.35);
    // set green pick at 40%
    humidityProgress.setProgression_MediumMax_(0.4)
    // set green at 0 at 65%
    humidityProgress.setProgression_MediumSop_(0.65);
    // set blue start 40%
    humidityProgress.setProgression_FinishIncrementFrom_(0.4);
}

void loop()
{
    int temperatureColor[3] = {0,0,0};
    int humidityColor[3] = {0,0,0};

    // obviously you get myTemperature and myHumidity like grown ups :D
    temperatureProgress.Rgb(myTemperature, temperatureColor);
    humidityProgress.Rgb(myHumidity, humidityColor);

    // temperatureColor now contains the rgb code for the temperature
    // humidityColor now contains the rgb code for the humidity

    // Voila :D
}