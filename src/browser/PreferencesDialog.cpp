#include "PreferencesDialog.hpp"

#include "Preferences.hpp"

#include <iostream>

PreferencesDialog::PreferencesDialog()
{
  ui.setupUi(this);
  
}

void
PreferencesDialog::load(Preferences* p)
{
  ui.leUsername->setText(p->getUsername());
  ui.sbQuota->setValue(p->getQuotaNum());
  auto q = p->getQuotaUnit();
  QString qus;
  switch (q) {
  case QU_KB:
    qus = "KBytes";
    break;
  case QU_MB:
    qus = "MB";
    break;
  case QU_GB:
    qus = "GB";
    break;
  default:
    std::cout << "Quota unit not valid " << q << std::endl;
  };
  
  ui.cbQuota->setCurrentText(qus);
}

void
PreferencesDialog::save(Preferences* p)
{
  p->setUsername(ui.leUsername->text());
  auto unit = ui.cbQuota->currentText().toStdString();
  QuotaUnit_t unn;
  if (unit == "KBytes")
    unn = QU_KB;
  else if (unit == "MB")
    unn = QU_MB;
  else if (unit == "GB")
    unn = QU_GB;
  else
    std::cout << "Quota unit not valid " << unit << std::endl;
    
    
  std::cout << "Current quota unit is " << unit
	    << std::endl;
  p->setQuota(ui.sbQuota->value(), unn);
}
