#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "digitalclock.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->clock = new DigitalClock(this);
  clock->init(this->ui->digitalClock);
}

MainWindow::~MainWindow()
{
  delete ui;
}

