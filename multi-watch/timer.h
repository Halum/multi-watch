#ifndef TIMER_H
#define TIMER_H

#include <QWidget>

class Numpad;

namespace Ui {
  class Timer;
}

class Timer : public QWidget
{
  Q_OBJECT

public:
  explicit Timer(QWidget *parent = 0);
  ~Timer();

private slots:
  void numInput(int num);
  void numCleared();
  void numDeleted();

private:
  // METHODS

  // VARIABLES
  Ui::Timer *ui;
  Numpad *numpad;
};

#endif // TIMER_H
