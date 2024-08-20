#include "kalmanfilter.h"

KalmanFilter::KalmanFilter(float processNoise, float measurementNoise, float estimationError)
    : processNoise(processNoise),
    measurementNoise(measurementNoise),
    estimationError(estimationError),
    currentEstimate(0.0)
{
}

KalmanFilter::~KalmanFilter() {}

void KalmanFilter::setProcessNoise(float valueP, float valueM, float valueR)
{
    this->processNoise = valueP;          // Установка шума процесса
    this->measurementNoise = valueM;      // Установка шума измерений
    this->estimationError = valueR;       // Установка ошибки оценки
}

float KalmanFilter::calculateFilteredOutput(float measurement)
{
    // Предсказание (Prediction)
    // Нет необходимости в предсказании в простом фильтре

    // Обновление измерения (Correction)
    kalmanGain = estimationError / (estimationError + measurementNoise);  // Вычисление Калмановского коэффициента
    currentEstimate = currentEstimate + kalmanGain * (measurement - currentEstimate);  // Обновление оценки
    estimationError = (1 - kalmanGain) * estimationError + processNoise;  // Обновление ошибки оценки

    return currentEstimate;  // Возвращаем отфильтрованное значение
}
