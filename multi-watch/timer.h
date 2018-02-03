#ifndef TIMER_H
#define TIMER_H

#include <QWidget>

namespace Ui {
  class Timer;
}

class Timer : public QWidget
{
  Q_OBJECT

public:
  explicit Timer(QWidget *parent = 0);
  ~Timer();

private:
  Ui::Timer *ui;
};

#endif // TIMER_H
