#include <QThread>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , canReceiverThread(new CanReceiverThread(this))
    , currentFilter(NO_FILTER) // Start with NO filter
    , emaFilter(0.25) // Инициализация EmaFilter с alpha по умолчанию
    , smaFilter(10)   // Инициализация SmaFilter с длиной окна по умолчанию
    , kalmanFilter(1.0, 10.0, 100.0) // Инициализация KalmanFilter с параметрами по умолчанию
{
    ui->setupUi(this);
    this->setWindowTitle("Instrument Cluster");
    this->setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    this->setStyleSheet("background-color: black");

    this->speedometer = new Speedometer(this);
    setCentralWidget(this->speedometer);
    flatterFilterButton = new QPushButton("FlatterFilter", this);
    flatterFilterButton->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));

    // Устанавливаем начальный стиль кнопки: серый фон и белый текст
    flatterFilterButton->setStyleSheet("background-color: black; color: white; border: 1px solid white;");

    // Подключаем сигнал нажатия кнопки к слоту
    connect(flatterFilterButton, &QPushButton::clicked, this, &MainWindow::onFlatterFilterButtonClicked);

    // Подключаем слот updateSpeed к сигналу от CanReceiver
    connect(this->canReceiverThread->getCanReceiver(), &CanReceiver::speedUpdated, this, &MainWindow::updateSpeed);

    // Обработка завершения потока CanReceiverThread
    connect(this->canReceiverThread, &QThread::finished, this->canReceiverThread->getCanReceiver(), &CanReceiver::deleteLater);
    connect(this->canReceiverThread, &QThread::finished, this->canReceiverThread, &QThread::deleteLater);

    this->canReceiverThread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::FilterType MainWindow::getCurrentFilter() const
{
    return currentFilter;
}

void MainWindow::setFilterType(MainWindow::FilterType filterType)
{
    currentFilter = filterType;
}

void MainWindow::updateSpeed(double speed)
{
    float filteredSpeed = speed;

    // Применение фильтров в зависимости от текущего типа фильтра
    switch (currentFilter)
    {
    case EMA:
        filteredSpeed = emaFilter.calculateFilteredOutput(static_cast<float>(speed));
        break;

    case SMA:
        filteredSpeed = smaFilter.calculateFilteredOutput(static_cast<int>(speed));
        break;

    case KALMAN:
        filteredSpeed = kalmanFilter.calculateFilteredOutput(static_cast<float>(speed));
        break;

    case NO_FILTER:
    default:
        // Ничего не делаем, используем необработанное значение скорости
        break;
    }

    // Обновляем отображаемую скорость на спидометре
    this->speedometer->setSpeed(filteredSpeed);
}

void MainWindow::onFlatterFilterButtonClicked()
{
    // Переключаем фильтр
    currentFilter = static_cast<MainWindow::FilterType>((currentFilter + 1) % FILTER_COUNT);

    // Обновляем настройки и стиль кнопки в зависимости от выбранного фильтра
    switch (currentFilter)
    {
    case NO_FILTER:
        flatterFilterButton->setStyleSheet("background-color: gray; color: white; border: 2px solid white;");
        flatterFilterButton->setText("No Filter");
        break;

    case EMA:
        flatterFilterButton->setStyleSheet("background-color: green; color: white; border: 2px solid white;");
        flatterFilterButton->setText("EMA");
        break;

    case SMA:
        flatterFilterButton->setStyleSheet("background-color: blue; color: yellow; border: 2px solid white;");
        flatterFilterButton->setText("SMA");
        break;

    case KALMAN:
        flatterFilterButton->setStyleSheet("background-color: red; color: black; border: 2px solid white;");
        flatterFilterButton->setText("KALMAN");
        break;

    default:
        break;
    }
}
