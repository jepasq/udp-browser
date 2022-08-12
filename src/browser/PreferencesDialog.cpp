#include "PreferencesDialog.hpp"

#include "Preferences.hpp"

PreferencesDialog::PreferencesDialog(Preferences* p)
{
  ui.setupUi(this);
  ui.leUsername->setText(p->getUsername());
  // sbQuota and cbQuota
}
