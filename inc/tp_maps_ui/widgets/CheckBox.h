#ifndef tp_maps_ui_CheckBox_h
#define tp_maps_ui_CheckBox_h

#include "tp_maps_ui/Widget.h"
#include "tp_utils/CallbackCollection.h"

namespace tp_maps_ui
{

//##################################################################################################
class TP_MAPS_UI_SHARED_EXPORT CheckBox : public Widget
{
public:
  //################################################################################################
  CheckBox(Widget* parent=nullptr);

  //################################################################################################
  CheckBox(const std::u16string& text, Widget* parent=nullptr);

  //################################################################################################
  ~CheckBox() override;

  //################################################################################################
  const std::u16string& text() const;

  //################################################################################################
  void setText(const std::u16string& text);

  //################################################################################################
  bool checked() const;

  //################################################################################################
  void setChecked(bool checked);

  //################################################################################################
  CheckState checkState() const;

  //################################################################################################
  void setCheckstate(CheckState checkState);

  //################################################################################################
  bool tristate() const;

  //################################################################################################
  void setTristate(bool tristate);

  //################################################################################################
  tp_utils::CallbackCollection<void(CheckState)> checkStateChanged;

protected:
  //################################################################################################
  void render(tp_maps::RenderInfo& renderInfo) override;

  //################################################################################################
  void invalidateBuffers() override;

  //################################################################################################
  bool mouseEvent(const tp_maps::MouseEvent& event) override;

  //################################################################################################
  void animate(double timestampMS) override;

private:
  struct Private;
  Private* d;
  friend struct Private;
};
}
#endif
