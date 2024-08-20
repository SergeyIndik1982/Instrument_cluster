#ifndef SMAFILTER_H
#define SMAFILTER_H

const int MAX_BUFFER_SIZE = 20;

class SmaFilter
{
public:
    explicit SmaFilter(int length = 10);
    ~SmaFilter();

    // Метод для установки длины окна фильтрации
    void setFilterParameters(int length);

    // Изменение возвращаемого типа на float
    float calculateFilteredOutput(int value);

private:
    int length;
    int buffer[MAX_BUFFER_SIZE];
    int currentIndex;
    int count;
    int sum;

    void resetFilter();  // Вспомогательный метод для сброса фильтра
};

#endif // SMAFILTER_H
