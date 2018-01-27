#ifndef SETTINGMANAGER_H
#define SETTINGMANAGER_H

#include <QObject>
#include <QTabWidget>
#include <QSettings>

class QSettings;
class SettingManager
{
public:
  SettingManager();
  void saveTabOrder(QTabWidget *tabWidget);
  void loadTabOrder(QTabWidget *tabWidget);

private:
  QString settingFileName;
  QString applicationName;

  QString tabSettingKey;
};

#endif // SETTINGMANAGER_H
