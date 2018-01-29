#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "digitalclock.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->clock = new DigitalClock(this);
  ui->changeTimeFormatBtn->setCheckable(true);
  clock->init(this->ui->digitalClock, ui->changeTimeFormatBtn);
}

MainWindow::~MainWindow()
{
  delete ui;
}

