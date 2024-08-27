#ifndef KALMANFILTER_H
#define KALMANFILTER_H

#include "ifilter.h"

class KalmanFilter : public IFilter
{
public:
    explicit KalmanFilter(QObject* parent
                          , float processNoise = 1.0f
                          , float measurementNoise = 10.0f
                          , float estimationError = 100.0f);
    ~KalmanFilter();

    void setProcessNoise(float valueP, float valueM, float valueR);
    float calculateFilteredOutput(float measurement) override;
    void reset() override;

private:
    float processNoise;
    float measurementNoise;
    float estimationError;
    float kalmanGain;
    float currentEstimate;
    float initialEstimationError;
};

#endif // KALMANFILTER_H
