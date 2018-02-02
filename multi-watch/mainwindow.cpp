#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "digitalclock.h"
#include "settingmanager.h"
#include "numpad.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->changeTimeFormatBtn->setCheckable(true);

  this->numpad = new Numpad(parent);
  this->ui->timerTab->layout()->addWidget(this->numpad);

  this->clock = new DigitalClock(this);
  clock->init(this->ui->digitalClock, ui->changeTimeFormatBtn);

  this->settingManager = new SettingManager();
  this->settingManager->loadTabOrder(ui->tabWidget);

  this->disableTabsForRelease();

  connect(this->numpad, &Numpad::numberPressed,
          this, &MainWindow::input);
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

// this is a demo method to show that numpad works
void MainWindow::input(int num) {
  qDebug() << num;
}

