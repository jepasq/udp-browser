#include "PreferencesDialog.hpp"


#include <iostream>


PreferencesDialog::PreferencesDialog()
{
  ui.setupUi(this);

  units["KBytes"] = QU_KB;
  units["MB"]     = QU_MB;
  units["GB"]     = QU_GB;

  // Can't get the map added in right order, let's adding it another way
  QString us[] = {"KBytes", "MB", "GB"};
  
  for (auto u : us)
    ui.cbQuota->addItem(u);
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
