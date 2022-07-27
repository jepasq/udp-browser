#ifndef __PREFERENCES_DIALOG_HPP__
#define __PREFERENCES_DIALOG_HPP__

#include "ui/ui_Preferences.h" // MOC generated file

#include <QWidget>

class PreferencesDialog : public QDialog
{
  Q_OBJECT

public:
  PreferencesDialog();

private:
  Ui::Dialog ui;  //!< The ui objects from the designer .ui file

};

#endif // !__PREFERENCES_DIALOG_HPP__
