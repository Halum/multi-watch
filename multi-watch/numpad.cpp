#include "numpad.h"
#include "ui_numpad.h"

#include <QPushButton>

Numpad::Numpad(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Numpad)
{
  ui->setupUi(this);
  this->setupSignals();
}

Numpad::~Numpad() {
  delete ui;
}

void Numpad::setupSignals() {
  // signal for numbered buttons
  this->connectNumberedButton(this->ui->numZero, 0);
  this->connectNumberedButton(this->ui->numOne, 1);
  this->connectNumberedButton(this->ui->numTwo, 2);
  this->connectNumberedButton(this->ui->numThree, 3);
  this->connectNumberedButton(this->ui->numFour, 4);
  this->connectNumberedButton(this->ui->numFive, 5);
  this->connectNumberedButton(this->ui->numSix, 6);
  this->connectNumberedButton(this->ui->numSeven, 7);
  this->connectNumberedButton(this->ui->numEight, 8);
  this->connectNumberedButton(this->ui->numNine, 9);
  // signal for clear button
  connect(this->ui->numClear, &QAbstractButton::clicked,
          this, &Numpad::numberCleared);
  // signal for delete button
  connect(this->ui->numDelete, &QAbstractButton::clicked,
          this, &Numpad::numberDeleted);
}

void Numpad::connectNumberedButton(QPushButton *button, int signalValue) {
  connect(button, &QAbstractButton::clicked,
          this, [=]() { this->numberPressed(signalValue); });
}
