#include "digitalclock.h"
#include "utils.h"

#include <QLabel>
#include <QString>
#include <QTimer>
#include <QTime>
#include <QPushButton>

DigitalClock::DigitalClock(QObject *parent) : QObject(parent) {

}

DigitalClock::~DigitalClock() {}

void DigitalClock::init(QLabel *timeLabel) {
  this->timeLabel = timeLabel;
  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout,
          this, DigitalClock::showTime);
  timer->start(1000);
  showTime();
}

void DigitalClock::showTime() {
  QTime currentTime = QTime::currentTime();
  QString timeString = currentTime.toString("hh:mm:ss");
  if ((currentTime.second() % 2)) {
          timeString[5] = ' ';
    }
  this->timeLabel->setText(timeString);
}
