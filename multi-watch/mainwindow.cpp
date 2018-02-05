#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "digitalclock.h"
#include "settingmanager.h"
#include "timer.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->changeTimeFormatBtn->setCheckable(true);

  this->timer = new Timer(parent);
  this->ui->timerTab->layout()->addWidget(this->timer);

  this->clock = new DigitalClock(this);
  clock->init(this->ui->digitalClock, ui->changeTimeFormatBtn);

  this->settingManager = new SettingManager();
  this->settingManager->loadTabOrder(ui->tabWidget);

  this->disableTabsForRelease();
}

void MainWindow::disableTabsForRelease(){
  this->ui->tabWidget->setTabEnabled(1, false);
//  this->ui->tabWidget->setTabEnabled(2, false);
  this->ui->tabWidget->setTabEnabled(3, false);
}

MainWindow::~MainWindow()
{
  this->settingManager->saveTabOrder(ui->tabWidget);
  delete ui;
}

