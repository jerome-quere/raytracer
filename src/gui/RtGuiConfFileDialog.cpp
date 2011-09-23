#include "RtGuiConfFileDialog.hpp"


namespace Rt
{
  namespace Gui
  {
    ConfFileDialog::ConfFileDialog()
    {
      setModal(true);
      setNameFilter("XML files (*.xml)");
    }
    
    ConfFileDialog::~ConfFileDialog()
    {
    }

  }
}
