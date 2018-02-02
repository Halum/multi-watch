#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
  // METHODS
  void disableTabsForRelease();

  // VARIABLES
  Ui::MainWindow *ui;
  DigitalClock *clock;
  SettingManager *settingManager;
  Numpad *numpad;
};

#endif // MAINWINDOW_H
