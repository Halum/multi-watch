#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
  // METHODS
  void disableTabsForRelease();

  // VARIABLES
  Ui::MainWindow *ui;
  DigitalClock *clock;
  SettingManager *settingManager;
  Timer *timer;
};

#endif // MAINWINDOW_H
