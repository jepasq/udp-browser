#include "PreferencesDialog.hpp"

#include "Preferences.hpp"

PreferencesDialog::PreferencesDialog()
{
  ui.setupUi(this);
  
}

void
PreferencesDialog::load(Preferences* p)
{
  ui.leUsername->setText(p->getUsername());
  ui.sbQuota->setValue(p->getQuotaNum());
  // ui.cbQuota
}

void
PreferencesDialog::save(Preferences* p)
{
  p->setUsername(ui.leUsername->text());
}
