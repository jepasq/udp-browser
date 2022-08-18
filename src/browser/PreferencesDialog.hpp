#ifndef __PREFERENCES_DIALOG_HPP__
#define __PREFERENCES_DIALOG_HPP__

#include "ui/ui_PreferencesDialog.h" // MOC generated file

#include <QWidget>
#include <unordered_map>

#include "Preferences.hpp" //USES QuotaUnit_t

// Forward declarations
class Preferences;
// End of forward declarations


/** The Qt dialog used to view/modify user prefereneces
  *
  */
class PreferencesDialog : public QDialog
{
  Q_OBJECT

public:
  PreferencesDialog();

  void load(Preferences*);
  void save(Preferences*);
  
private:
  Ui::Dialog ui;  //!< The ui objects from the designer .ui file
  std::unordered_map<QString, QuotaUnit_t>  units; //!< The ComboBox/units map
  
};

#endif // !__PREFERENCES_DIALOG_HPP__
