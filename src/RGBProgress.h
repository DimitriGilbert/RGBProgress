/*
  
*/
#ifndef RGBProgress_h
#define RGBProgress_h
#include "Arduino.h"
class RGBProgress
{
    int const R = 0;
    int const G = 1;
    int const B = 2;
    public:
        RGBProgress(double from = -50, double to = 100);
        void setColorProgression(int start, int medium, int finish);
        void setFrom(double from);
        void setTo(double to);
        void Rgb(double value, int (&tRGB)[3]);

        void setProgression_StartDecrementUntil_(string progression_StartDecrementUntil_);
        void setProgression_MediumStart_(string progression_MediumStart_);
        void setProgression_MediumStop_(string progression_MediumStop_);
        void setProgression_MediumMax_(string progression_MediumMax_);
        void setProgression_FinishIncrementFrom_(string progression_FinishIncrementFrom_);

    private:
        double from_ = -50.0;
        double to_ = 100.0;
        double delta_ = 150;
        int progression_[3];
        
        float progression_StartDecrementUntil_ = 0.5;
        float progression_MediumStart_ = 0.2;
        float progression_MediumStop_ = 0.8;
        float progression_MediumMax_ = 0.5;
        float progression_FinishIncrementFrom_ = 0.5;
        
        float progression_StartDecrementUntil_Val_ = 0.5;
        float progression_MediumStart_Val_ = 0.2;
        float progression_MediumStop_Val_ = 0.8;
        float progression_MediumMax_Val_ = 0.5;
        float progression_FinishIncrementFrom_Val_ = 0.5;

        void computeDelta();
        void computeVals();
};
#endif