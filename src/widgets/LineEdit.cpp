#include "tp_maps_ui/widgets/LineEdit.h"

namespace tp_maps_ui
{

//##################################################################################################
struct LineEdit::Private
{

};

//##################################################################################################
LineEdit::LineEdit(Widget* parent):
    Widget(parent),
    d(new Private())
{

}

//##################################################################################################
LineEdit::~LineEdit()
{
  delete d;
}

//##################################################################################################
void LineEdit::render(tp_maps::RenderInfo& renderInfo)
{
  Widget::render(renderInfo);
}

//##################################################################################################
void LineEdit::invalidateBuffers()
{
  Widget::invalidateBuffers();
}

//##################################################################################################
bool LineEdit::mouseEvent(const tp_maps::MouseEvent& event)
{
  return Widget::mouseEvent(event);
}

//##################################################################################################
void LineEdit::animate(double timestampMS)
{
  Widget::animate(timestampMS);
}

}
