#include "mainwindow.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      counterValue(0)
{
    setWindowTitle("Счётчик");
    setMinimumSize(380, 520);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(35, 35, 35, 35);
    mainLayout->setSpacing(18);

    titleLabel = new QLabel("Мой счётчик", this);

    QFont titleFont;
    titleFont.setPointSize(24);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);

    QLabel *subtitleLabel =
        new QLabel("Простое приложение на C++", this);

    subtitleLabel->setAlignment(Qt::AlignCenter);

    counterLabel = new QLabel("0", this);

    QFont counterFont;
    counterFont.setPointSize(64);
    counterLabel->setFont(counterFont);
    counterLabel->setAlignment(Qt::AlignCenter);

    minusButton = new QPushButton("−", this);
    plusButton = new QPushButton("+", this);
    resetButton = new QPushButton("Сбросить", this);

    minusButton->setMinimumSize(100, 65);
    plusButton->setMinimumSize(100, 65);
    resetButton->setMinimumSize(210, 50);

    QFont buttonFont;
    buttonFont.setPointSize(22);

    minusButton->setFont(buttonFont);
    plusButton->setFont(buttonFont);

    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    buttonsLayout->setSpacing(15);
    buttonsLayout->addWidget(minusButton);
    buttonsLayout->addWidget(plusButton);

    mainLayout->addStretch();
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(subtitleLabel);
    mainLayout->addSpacing(15);
    mainLayout->addWidget(counterLabel);
    mainLayout->addSpacing(15);
    mainLayout->addLayout(buttonsLayout);
    mainLayout->addWidget(resetButton, 0, Qt::AlignHCenter);
    mainLayout->addStretch();

    connect(plusButton, &QPushButton::clicked, this, [this]()
    {
        ++counterValue;
        updateCounter();
    });

    connect(minusButton, &QPushButton::clicked, this, [this]()
    {
        --counterValue;
        updateCounter();
    });

    connect(resetButton, &QPushButton::clicked, this, [this]()
    {
        counterValue = 0;
        updateCounter();
    });
}

void MainWindow::updateCounter()
{
    counterLabel->setText(QString::number(counterValue));
}
