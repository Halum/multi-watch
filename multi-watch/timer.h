#ifndef TIMER_H
#define TIMER_H

#include <QWidget>
#include <QString>

class Numpad;
class ClickableLabel;

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
  void watchCounterSelected();

private:
  // METHODS
  void setupWatchLabel(QWidget *parent);
  void setupLabelConnection();
  void setupWatchFont(ClickableLabel *label, QString defalutVal = "00:");
  // VARIABLES
  Ui::Timer *ui;
  Numpad *numpad;
  ClickableLabel *hourCount;
  ClickableLabel *minuteCount;
  ClickableLabel *secondCount;
};

#endif // TIMER_H
