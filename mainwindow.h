#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "speedometer.h"
#include "canreceiverthread.h"
#include "kalmanfilter.h"
#include "smafilter.h"
#include "emafilter.h"
#include <QPushButton>
#include <QWidget>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Перечисление для типов фильтров
    enum FilterType {
        NO_FILTER,
        EMA,
        SMA,
        KALMAN,
        FILTER_COUNT // Количество фильтров
    };

    // Геттер для текущего фильтра
    FilterType getCurrentFilter() const;

    // Сеттер для установки типа фильтра
    void setFilterType(FilterType filterType);

private slots:
    void updateSpeed(double speed);           // Обновление скорости с применением фильтра
    void onFlatterFilterButtonClicked();      // Обработка нажатия кнопки для смены фильтра

private:
    Ui::MainWindow *ui;
    Speedometer *speedometer;                 // Виджет спидометра
    CanReceiverThread *canReceiverThread;     // Поток для получения данных с CAN-шины
    QPushButton *flatterFilterButton;         // Кнопка для смены фильтра

    KalmanFilter kalmanFilter;                // Объект KalmanFilter
    SmaFilter smaFilter;                      // Объект SmaFilter
    EmaFilter emaFilter;                      // Объект EmaFilter

    const int SCREEN_WIDTH = 1280;            // Ширина окна
    const int SCREEN_HEIGHT = 400;            // Высота окна

    FilterType currentFilter;  // Текущий тип фильтра
};

#endif // MAINWINDOW_H
