#include "timer.h"
#include "ui_timer.h"
#include "numpad.h"

#include <QDebug>

Timer::Timer(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Timer),
  numpad(new Numpad(parent))
{

  ui->setupUi(this);

  this->ui->verticalLayout->addWidget(this->numpad);

  connect(this->numpad, &Numpad::numberPressed,
          this, &Timer::numInput);
  connect(this->numpad, &Numpad::numberCleared,
          this, &Timer::numCleared);
  connect(this->numpad, &Numpad::numberDeleted,
          this, &Timer::numDeleted);
}

Timer::~Timer() {
  delete ui;
}

void Timer::numInput(int num) {
  qDebug() << num;
}

void Timer::numCleared() {
  qDebug() << "clear";
}

void Timer::numDeleted() {
  qDebug() << "delete";
}




