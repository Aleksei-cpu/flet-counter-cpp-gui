#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    int counterValue;

    QLabel *titleLabel;
    QLabel *counterLabel;
    QPushButton *minusButton;
    QPushButton *plusButton;
    QPushButton *resetButton;

    void updateCounter();

public:
    explicit MainWindow(QWidget *parent = nullptr);
};

#endif
