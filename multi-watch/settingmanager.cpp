#include "settingmanager.h"
#include <QTabWidget>
#include <QSettings>

SettingManager::SettingManager() {
  this->settingFileName = "multiWatchSetting";
  this->applicationName = "multiWatch";
  this->tabSettingKey = "TabOrder";
}

void SettingManager::saveTabOrder(QTabWidget *tabWidget) {
  QSettings settings(this->settingFileName, this->applicationName);
  int numberOfTab = tabWidget->count();
  QString tabOrderTxt = "";
  //this additional line added to avoid unnecessary chararcter in string
  tabOrderTxt.append(tabWidget->tabText(0));
  for(int i = 1; i< numberOfTab; i++){
      tabOrderTxt.append("_");
      tabOrderTxt.append(tabWidget->tabText(i));
    }
  settings.setValue(this->tabSettingKey, tabOrderTxt);
}

void SettingManager::loadTabOrder(QTabWidget *tabWidget) {
  QRegExp qr("_");
  QSettings settings(this->settingFileName, this->applicationName);
  QString tabOrderTxt = settings.value(this->tabSettingKey, "").toString();
  QStringList qs = tabOrderTxt.split(qr);
  if(tabOrderTxt == "")
    return;
  int numberOfTab = qs.size();
  for(int i=0; i<numberOfTab; i++){
      for(int j = i; j < numberOfTab; j++){
          if(tabWidget->tabText(j) == qs[i] && j != i){
              QWidget *tab1 = tabWidget->widget(j);
              QString str = tabWidget->tabText(j);
              tabWidget->removeTab(j);
              tabWidget->insertTab(i, tab1, str);
           }
        }
    }
}
