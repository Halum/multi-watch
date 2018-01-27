#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QObject>

// Forward declaration
class QLCDNumber;

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
  void init(QLCDNumber *lcdPanel);

private:
  // METHODS
  // VARIABLES
  QLCDNumber *lcdPanel;
};

#endif // DIGITALCLOCK_H
