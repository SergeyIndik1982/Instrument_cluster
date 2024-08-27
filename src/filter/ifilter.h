#ifndef IFILTER_H
#define IFILTER_H

#include <QObject>

class IFilter : public QObject
{
    Q_OBJECT
public:
    explicit IFilter(QObject *parent = nullptr): QObject(parent) {}
    virtual ~IFilter() {};

    virtual float calculateFilteredOutput(float value) = 0;
    virtual void reset() = 0;
};

#endif // IFILTER_H
