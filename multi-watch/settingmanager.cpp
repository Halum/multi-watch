#include "settingmanager.h"

SettingManager::SettingManager()
{

}

void SettingManager::saveTabOrder(QTabWidget *tabWidget)
{
  QSettings settings("multiWatchSetting", "multiWatch");
  int nTab = tabWidget->count();
  QString tabOrderTxt = "";
  int i;
  tabOrderTxt.append(tabWidget->tabText(0));
  for(i = 1; i< nTab; i++){
      tabOrderTxt.append("_");
      tabOrderTxt.append(tabWidget->tabText(i));
    }
  qDebug() << "saving "<< tabOrderTxt;
  settings.setValue("TabOrder", tabOrderTxt);
}

void SettingManager::loadTabOrder(QTabWidget *tabWidget)
{
  QRegExp qr("_");

  QSettings settings("multiWatchSetting", "multiWatch");
  QString tabOrderTxt = settings.value("TabOrder", "").toString();
  QStringList qs = tabOrderTxt.split(qr);
  qDebug() << "loading "<< tabOrderTxt;
  if(tabOrderTxt == "")
    return;
  int i,j;
  int nTab = qs.size();
  for(i=0; i<nTab; i++){
      qDebug() << qs[i];
      for(j = 0; j< nTab; j++){
          if(tabWidget->tabText(j) == qs[i]){
              QWidget *tab1 = tabWidget->widget(j);
              QString str = tabWidget->tabText(j);
              tabWidget->removeTab(j);
              tabWidget->insertTab(i, tab1, str);
           }
        }
    }
}
