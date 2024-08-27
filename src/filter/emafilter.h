#ifndef EMAFILTER_H
#define EMAFILTER_H

#include "ifilter.h"

class EmaFilter : public IFilter
{
public:
    explicit EmaFilter(QObject* parent, float alpha = 0.2);
    ~EmaFilter();

    float getEma() const;
    void setEma(float value);
    void setAlpha(float value);
    float calculateFilteredOutput(float value) override;
    void reset() override;

private:
    float alpha;
    float oneMinusAlpha;
    float ema;
};

#endif // EMAFILTER_H
