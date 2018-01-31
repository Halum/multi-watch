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

private slots:
  void showTime();
  void changeTimeFormat();

public:
  // METHODS
  void init(QLabel *timeLabel, QPushButton *changeFormatBtn);

private:
  // METHODS
  // VARIABLES
  QLabel *timeLabel;
  QPushButton *timeFormatButton;
  bool show24HourFormat;
};

#endif // DIGITALCLOCK_H
