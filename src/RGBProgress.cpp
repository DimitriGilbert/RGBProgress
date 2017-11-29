#include "Arduino.h"
#include "RGBProgress.h"

/**
 * 
 */
RGBProgress::RGBProgress(double from = -50, double to = 100)
{
    setFrom(from);
    setTo(to);
    setColorProgression(
        RGBProgress::B, 
        RGBProgress::G, 
        RGBProgress::R
    );
}

void RGBProgress::setProgression_StartDecrementUntil_(float progression_StartDecrementUntil)
{
    progression_StartDecrementUntil_ = progression_StartDecrementUntil;
    computeVals();
}
void RGBProgress::setProgression_MediumStart_(float progression_MediumStart)
{
    progression_MediumStart_ = progression_MediumStart;
    computeVals();
}
void RGBProgress::setProgression_MediumStop_(float progression_MediumStop)
{
    progression_MediumStop_ = progression_MediumStop;
    computeVals();
}
void RGBProgress::setProgression_MediumMax_(float progression_MediumMax)
{
    progression_MediumMax_ = progression_MediumMax;
    computeVals();
}
void RGBProgress::setProgression_FinishIncrementFrom_(float progression_FinishIncrementFrom)
{
    progression_FinishIncrementFrom_ = progression_FinishIncrementFro_
    computeVals();
} 


/**
 * 
 */
void RGBProgress::setColorProgression(int start, int medium, int finish) 
{
    progression_[0] = start;
    progression_[1] = medium;
    progression_[2] = finish;
}

/**
 * 
 */
void RGBProgress::setFrom(double from) 
{
    from_ = from;
    computeDelta();
}

/**
 * 
 */
void RGBProgress::setTo(double to) 
{
    to_ = to;
    computeDelta();
}

/**
 * 
 */
void RGBProgress::Rgb(double value, int (&tRGB)[3]) 
{
    if(value < from_) {
        tRGB[progression_[0]] = 255;
    }
    else if(value >= from_ && value <= progression_StartDecrementUntil_Val_) {
        tRGB[progression_[0]] = map(value,from_, progression_StartDecrementUntil_Val_, 255, 0);
    }
    else {
        tRGB[progression_[0]] = 0;
    }

    if(value >= progression_MediumStart_Val_ && value <= progression_MediumMax_Val_) {
        tRGB[progression_[1]] = map(value, progression_MediumStart_Val_, progression_MediumMax_Val_, 0, 255);
    }
    else if(value > progression_MediumMax_Val_ && value <= progression_MediumStop_Val_) {
        tRGB[progression_[1]] = map(value, progression_MediumMax_Val_, progression_MediumStop_Val_, 255, 0);
    }
    else {
        tRGB[progression_[1]] = 0;
    }

    if(value < progression_FinishIncrementFrom_Val_) {
        tRGB[progression_[2]] = 0;
    }
    else if(value >= progression_FinishIncrementFrom_Val_ && value <= to_) {
        tRGB[progression_[2]] = map(value, progression_FinishIncrementFrom_Val_, to_, 0, 255);
    }
    else {
        tRGB[progression_[2]] = 255;
    }

}

void RGBProgress::computeDelta()
{
    delta_ = (from_ * -1) + to_;
    computeVals();
}

void RGBProgress::computeVals()
{
    progression_StartDecrementUntil_Val_ = from_ + (progression_StartDecrementUntil_ * delta_);
    progression_MediumStart_Val_ = from_ + (progression_MediumStart_ * delta_);
    progression_MediumStop_Val_ = from_ + (progression_MediumStop_ * delta_);
    progression_MediumMax_Val_ = from_ + (progression_MediumMax_ * delta_);
    progression_FinishIncrementFrom_Val_ = from_ + (progression_FinishIncrementFrom_ * delta_);
}