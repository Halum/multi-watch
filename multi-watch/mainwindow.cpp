#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "digitalclock.h"
#include "settingmanager.h"
#include "timer.h"

#include <QCloseEvent>

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
  this->addTrayIcon();
}


void MainWindow::closeEvent(QCloseEvent *event){
   if(this->isVisible()){
       event->ignore();
       this->hide();
     }
}

void MainWindow::addTrayIcon(){
  this->trayIcon = new QSystemTrayIcon(this);
  this->trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));
  this->trayIcon->setToolTip("Multi-Watch");

  QMenu *trayMenu = new QMenu(this);
  QAction *closeApp = new QAction("Close Application",this);
  connect(closeApp, &QAction::triggered, this, &this->close);

  trayMenu->addAction(closeApp);

  this->trayIcon->setContextMenu(trayMenu);
  this->trayIcon->show();

  connect(this->trayIcon, &QSystemTrayIcon::activated, this, &this->iconActivated);
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason){
  switch (reason) {
    case QSystemTrayIcon::DoubleClick:
      if(!this->isVisible()){
          this->show();
      } else {
          this->hide();
      }
      break;
    default:
      break;
    }
}

void MainWindow::disableTabsForRelease(){
  for(int i=0; i<4; i++){
      if(this->ui->tabWidget->tabText(i) == "Alarm" || this->ui->tabWidget->tabText(i) == "StopWatch")
      {
          this->ui->tabWidget->setTabEnabled(i, false);
      }
    }
}

MainWindow::~MainWindow()
{
  this->settingManager->saveTabOrder(ui->tabWidget);
  delete ui;
}

