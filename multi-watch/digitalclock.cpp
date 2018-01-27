#include "digitalclock.h"
#include "utils.h"

#include <QLCDNumber>
#include <QString>
#include <QTimer>
#include <QTime>

DigitalClock::DigitalClock(QObject *parent) : QObject(parent) {

}

DigitalClock::~DigitalClock() {}

void DigitalClock::init(QLCDNumber *lcdPanel) {
  this->lcdPanel = lcdPanel;
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
  this->lcdPanel->display(timeString);
}
