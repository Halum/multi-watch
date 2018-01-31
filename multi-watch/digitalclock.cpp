#include "digitalclock.h"
#include "utils.h"

#include <QLabel>
#include <QString>
#include <QTimer>
#include <QTime>
#include <QPushButton>

#include <QDebug>

DigitalClock::DigitalClock(QObject *parent) : QObject(parent) {

}

DigitalClock::~DigitalClock() {}

void DigitalClock::init(QLabel *timeLabel, QPushButton *changeFormatBtn) {
  this->timeLabel = timeLabel;
  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout,
          this, &DigitalClock::showTime);
  timer->start();
  showTime();
  this->show24HourFormat = true;
  this->timeFormatButton = changeFormatBtn;
  connect(timeFormatButton, &QAbstractButton::clicked,
          this, &DigitalClock::changeTimeFormat);
}

void DigitalClock::showTime() {
  QTime currentTime = QTime::currentTime();
  QString timeString;
  if (this->show24HourFormat) {
    timeString = currentTime.toString("hh:mm:ss");
  }
  else {
      timeString = currentTime.toString("hh:mm:ss:AP");
      timeString[8] = ' ';
  }
  if ((currentTime.second() % 2)) {
          timeString[5] = ' ';
  }
  this->timeLabel->setText(timeString);
}


void DigitalClock::changeTimeFormat(){
  if(this->show24HourFormat){
      this->timeFormatButton->setText("Show 12 Hour Fomat");
      this->show24HourFormat = false;
  }
  else {
      this->timeFormatButton->setText("Show 24 Hour Fomat");
      this->show24HourFormat = true;
  }
}
