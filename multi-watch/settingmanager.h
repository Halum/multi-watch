#ifndef SETTINGMANAGER_H
#define SETTINGMANAGER_H

#include <QObject>
#include <QTabWidget>
#include <QSettings>
#include <QApplication>
#include <QDebug>

class QApplication;
class QSettings;
class SettingManager
{
public:
  SettingManager();
  void saveTabOrder(QTabWidget *tabWidget);
  void loadTabOrder(QTabWidget *tabWidget);

private:
  QString settingsPath;
};

#endif // SETTINGMANAGER_H
