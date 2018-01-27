#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "digitalclock.h"
#include "settingmanager.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->clock = new DigitalClock(this);
  clock->init(this->ui->digitalClock);

  settingM = new SettingManager();
  settingM->loadTabOrder(ui->tabWidget);
  ui->tabWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
  settingM->saveTabOrder(ui->tabWidget);
  delete ui;
}
