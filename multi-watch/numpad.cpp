#include "numpad.h"
#include "ui_numpad.h"

Numpad::Numpad(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Numpad)
{
  ui->setupUi(this);
}

Numpad::~Numpad()
{
  delete ui;
}
