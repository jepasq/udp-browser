#ifndef __PREFERENCES_DIALOG_HPP__
#define __PREFERENCES_DIALOG_HPP__

#include "ui/ui_PreferencesDialog.h" // MOC generated file

#include <QWidget>

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
  PreferencesDialog(Preferences*);

private:
  Ui::Dialog ui;  //!< The ui objects from the designer .ui file

};

#endif // !__PREFERENCES_DIALOG_HPP__
