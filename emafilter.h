#ifndef EMAFILTER_H
#define EMAFILTER_H

class EmaFilter
{
public:
    explicit EmaFilter(float alpha = 0.25);
    ~EmaFilter();

    // Объявления методов
    float getEma() const;
    void setEma(float value);
    void setAlpha(float value);
    float calculateFilteredOutput(float value);

private:
    float alpha;
    float oneMinusAlpha;
    float ema;
};

#endif // EMAFILTER_H
