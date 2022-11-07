#include "PreferencesDialog.hpp"


#include <iostream>

/** The dialog constructor
  *
  * Uses the .ui file to setup UI and handle the units map.
  *
  */
PreferencesDialog::PreferencesDialog()
{
  ui.setupUi(this);

  units["KBytes"] = QU_KB;
  units["MBytes"] = QU_MB;
  units["GBytes"] = QU_GB;

  // Can't get the map added in right order, let's adding it another way
  QString us[] = {"KBytes", "MBytes", "GBytes"};
  
  for (auto u : us)
    ui.cbQuota->addItem(u);
}

/** A Preferences-based constructor
  *
  * Will override default values with Preferences ones (quota, username
  * and more ...).
  *
  * \param p The Preferences object.
  *
  */
void
PreferencesDialog::load(Preferences* p)
{
  ui.leUsername->setText(p->getUsername());
  ui.sbQuota->setValue(p->getQuotaNum());
  auto q = p->getQuotaUnit();
  QString qus;

  for (auto u : units)
    if (q == u.second)
      qus = u.first;
  
  ui.cbQuota->setCurrentText(qus);
}

/** Save the current dialog values using the given preferences object
  *
  * \param p The Preferences object.
  *
  */
void
PreferencesDialog::save(Preferences* p)
{
  p->setUsername(ui.leUsername->text());
  auto unit = ui.cbQuota->currentText();
  QuotaUnit_t unn;

  for (auto u : units)
    if (unit == u.first)
      unn = u.second;
    
  std::cout << "Current quota unit is " << unit.toStdString()
	    << std::endl;
  p->setQuota(ui.sbQuota->value(), unn);
}
