#include "smafilter.h"
#include <algorithm> // для std::fill

SmaFilter::SmaFilter(int length)
    : length(length), currentIndex(0), count(0), sum(0)
{
    std::fill(buffer, buffer + MAX_BUFFER_SIZE, 0);
}

SmaFilter::~SmaFilter() {}

void SmaFilter::setFilterParameters(int length)
{
    this->length = (length > MAX_BUFFER_SIZE) ? MAX_BUFFER_SIZE : length;
    resetFilter();  // Сбрасываем фильтр при изменении параметров
}

float SmaFilter::calculateFilteredOutput(int value)
{
    sum -= buffer[currentIndex];
    buffer[currentIndex] = value;
    sum += value;

    currentIndex = (currentIndex + 1) % length;

    if (count < length) {
        count++;
    }

    // Возвращаем результат как float
    return static_cast<float>(sum) / count;
}

void SmaFilter::resetFilter()
{
    std::fill(buffer, buffer + MAX_BUFFER_SIZE, 0);
    currentIndex = 0;
    count = 0;
    sum = 0;
}
