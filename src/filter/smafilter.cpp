#include "smafilter.h"

SmaFilter::SmaFilter(QObject* parent, int windowSize)
    : IFilter(parent), windowSize(windowSize), currentIndex(0), count(0), sum(0)
{
    this->buffer.fill(0.0f);
}

SmaFilter::~SmaFilter() {}

void SmaFilter::setFilterParameters(int windowSize)
{
    if (windowSize > MAX_BUFFER_SIZE)
    {
        this->windowSize = MAX_BUFFER_SIZE;
    }
    else
    {
        this->windowSize = windowSize;
    }
    reset();
}

float SmaFilter::calculateFilteredOutput(float value)
{
    this->sum -= buffer[currentIndex];
    buffer[currentIndex] = value;
    this->sum += value;

    this->currentIndex = (this->currentIndex + 1) % this->windowSize;

    if (this->count < this->windowSize) {
        this->count++;
    }

    return static_cast<float>(this->sum) / this->count;
}

void SmaFilter::reset()
{
    this->buffer.fill(0.0f);
    this->currentIndex = 0;
    this->count = 0;
    this->sum = 0;
}
