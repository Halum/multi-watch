#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "digitalclock.h"
#include "settingmanager.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->clock = new DigitalClock(this);
  this->clock->init(this->ui->digitalClock);

  this->settingManager = new SettingManager();
  this->settingManager->loadTabOrder(ui->tabWidget);
  ui->tabWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
  this->settingManager->saveTabOrder(ui->tabWidget);
  delete ui;
}
