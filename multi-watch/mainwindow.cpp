#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "digitalclock.h"
#include "settingmanager.h"
#include "numpad.h"

#include <QCloseEvent>
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

  this->addTrayIcon();
}


void MainWindow::closeEvent(QCloseEvent *event){
   if(this->isVisible() && this->enableTray){
       event->ignore();
       this->hide();
       QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
       trayIcon->showMessage("Mutlti-Watch",
                             "Application running on system tray",
                              icon,
                              2000);
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
  this->enableTray = false;
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

// this is a demo method to show that numpad works
void MainWindow::input(int num) {
  qDebug() << num;
}

void MainWindow::on_trayEnabled_clicked()
{
    this->enableTray = !this->enableTray;
}
