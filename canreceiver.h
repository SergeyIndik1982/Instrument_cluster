#ifndef CANRECEIVER_H
#define CANRECEIVER_H

#include <QObject>
#include <QCanBusDevice>

class CanReceiver : public QObject
{
    Q_OBJECT

public:
    explicit CanReceiver(QObject *parent = nullptr);
    ~CanReceiver();

    void startReceiving(const QString &interfaceName);

public slots:
    void processReceivedFrames();

signals:
    void speedUpdated(float speed);

private:
    QCanBusDevice *canDevice;
    unsigned int expectedId;
    static const int SCALE = 10000;
};

#endif // CANRECEIVER_H
