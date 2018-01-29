#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class DigitalClock;
class SettingManager;

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  Ui::MainWindow *ui;

  // VARIABLES
  DigitalClock *clock;
  SettingManager *settingManager;
};

#endif // MAINWINDOW_H
