#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  settingM = new SettingManager();
  settingM->loadTabOrder(ui->tabWidget);
  ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::loadTabState(){

}

void MainWindow::saveTabState(){

}

MainWindow::~MainWindow()
{
  settingM->saveTabOrder(ui->tabWidget);
  delete ui;
}
