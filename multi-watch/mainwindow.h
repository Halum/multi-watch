#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>

class DigitalClock;
class SettingManager;
class Timer;

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
private slots:
  void iconActivated(QSystemTrayIcon::ActivationReason reason);
private:
  // METHODS
  void disableTabsForRelease();
  void addTrayIcon();
  void closeEvent(QCloseEvent *event);

  // VARIABLES
  Ui::MainWindow *ui;
  DigitalClock *clock;
  SettingManager *settingManager;
  Timer *timer;

  QSystemTrayIcon *trayIcon;

};

#endif // MAINWINDOW_H
