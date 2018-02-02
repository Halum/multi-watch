#ifndef NUMPAD_H
#define NUMPAD_H

#include <QWidget>

namespace Ui {
  class Numpad;
}

class Numpad : public QWidget
{
  Q_OBJECT

public:
  explicit Numpad(QWidget *parent = 0);
  ~Numpad();

private:
  Ui::Numpad *ui;
};

#endif // NUMPAD_H
