#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>

class DigitalClock;
class SettingManager;
class Numpad;

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void input(int num);
   void iconActivated(QSystemTrayIcon::ActivationReason reason);

   void on_trayEnabled_clicked();

private:
  // METHODS
  void disableTabsForRelease();
  void closeEvent(QCloseEvent *event);
  void addTrayIcon();

  // VARIABLES
  Ui::MainWindow *ui;
  DigitalClock *clock;
  SettingManager *settingManager;
  Numpad *numpad;

  QSystemTrayIcon *trayIcon;
  bool enableTray;
};

#endif // MAINWINDOW_H
