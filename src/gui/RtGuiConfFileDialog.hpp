#ifndef _RT_GUI_CONF_FILE_DIALOG_
#define _RT_GUI_CONF_FILE_DIALOG_

#include <QFileDialog>

namespace Rt
{
  namespace Gui
  {
    class ConfFileDialog : public QFileDialog
    {
      Q_OBJECT;

    public:
      
      ConfFileDialog();
      ~ConfFileDialog();
      

    };

  }
}

#endif
