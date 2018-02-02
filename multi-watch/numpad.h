#ifndef NUMPAD_H
#define NUMPAD_H

#include <QWidget>

class QPushButton;

namespace Ui {
  class Numpad;
}

class Numpad : public QWidget
{
  Q_OBJECT

public:
  explicit Numpad(QWidget *parent = 0);
  ~Numpad();

signals:
  void numberPressed(int num);
  void numberCleared();
  void numberDeleted();


private:
  // METHODS
  void setupSignals();
  void connectNumberedButton(QPushButton *button, int signalValue);
  // VARIABLES
  Ui::Numpad *ui;
};

#endif // NUMPAD_H
