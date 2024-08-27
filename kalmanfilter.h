#ifndef KALMANFILTER_H
#define KALMANFILTER_H

class KalmanFilter
{
public:
    KalmanFilter(float processNoise = 1.0, float measurementNoise = 10.0, float estimationError = 100.0);
    ~KalmanFilter();

    void setProcessNoise(float valueP, float valueM, float valueR);   // Метод для установки шумов процесса
     // Метод для установки шумов измерений
    // Метод для установки ошибки оценки

    float calculateFilteredOutput(float measurement);

private:
    float processNoise;
    float measurementNoise;
    float estimationError;
    float kalmanGain;
    float currentEstimate;
};

#endif // KALMANFILTER_H
