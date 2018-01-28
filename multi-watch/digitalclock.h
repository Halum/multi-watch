#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QObject>
// Forward declaration
class QLabel;
class QPushButton;
class DigitalClock : public QObject
{
  Q_OBJECT
public:
  explicit DigitalClock(QObject *parent = nullptr);
  ~DigitalClock();

public slots:
  void showTime();

public:
  // METHODS
  void init(QLabel *timeLabel);

private:
  // METHODS
  // VARIABLES
  QLabel *timeLabel;
};

#endif // DIGITALCLOCK_H
