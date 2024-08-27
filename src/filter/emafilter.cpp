#include "emafilter.h"

EmaFilter::EmaFilter(QObject* parent, float alpha)
    : IFilter(parent), alpha(alpha), oneMinusAlpha(1.0f - alpha), ema(0.0f)
{}

EmaFilter::~EmaFilter()
{}

float EmaFilter::getEma() const
{
    return this->ema;
}

void EmaFilter::setEma(float value)
{
    this->ema = value;
}

void EmaFilter::setAlpha(float value)
{
    this->alpha = value;
    this->oneMinusAlpha = 1 - value;
}

float EmaFilter::calculateFilteredOutput(float value)
{
    this->ema = this->alpha * value + this->oneMinusAlpha * ema;
    return this->ema;
}

void EmaFilter::reset()
{
    this->ema = 0.0f;
}
