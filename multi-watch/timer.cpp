#include "timer.h"
#include "ui_timer.h"
#include "numpad.h"
#include "clickablelabel.h"

#include <QDebug>
#include <QFont>


Timer::Timer(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Timer),
  numpad(new Numpad(parent))
{

  ui->setupUi(this);

  this->setupWatchLabel(parent);

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

void Timer::setupLabelConnection() {
  connect(this->hourCount, &ClickableLabel::clicked,
          this, &Timer::watchCounterSelected);
  connect(this->minuteCount, &ClickableLabel::clicked,
          this, &Timer::watchCounterSelected);
  connect(this->secondCount, &ClickableLabel::clicked,
          this, &Timer::watchCounterSelected);
}

void Timer::watchCounterSelected() {
  qDebug() << "clicked";
}

void Timer::setupWatchFont(ClickableLabel *label, QString defalutVal) {
  label->setText(defalutVal);
  QFont font = label->font();
  font.setBold(true);
  font.setPointSize(25);
  font.setWeight(75);
  font.setKerning(true);
  label->setFont(font);
}

void Timer::setupWatchLabel(QWidget *parent) {
  this->hourCount = new ClickableLabel(parent);
  this->minuteCount = new ClickableLabel(parent);
  this->secondCount = new ClickableLabel(parent);

  this->setupWatchFont(this->hourCount);
  this->setupWatchFont(this->minuteCount);
  this->setupWatchFont(this->secondCount, "00");

  this->ui->horizontalLayout->addWidget(this->hourCount);
  this->ui->horizontalLayout->addWidget(this->minuteCount);
  this->ui->horizontalLayout->addWidget(this->secondCount);

  this->setupLabelConnection();
}
