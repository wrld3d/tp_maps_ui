#include "tp_maps_ui/layers/UILayer.h"
#include "tp_maps_ui/Widget.h"
#include "tp_maps_ui/DrawHelper.h"
#include "tp_maps_ui/draw_helpers/DarkDrawHelper.h"

#include "tp_maps/Map.h"

#include "tp_utils/DebugUtils.h"

namespace tp_maps_ui
{

//##################################################################################################
struct UILayer::Private
{
  Widget* rootWidget{nullptr};
  tp_maps::FontRenderer* font{nullptr};
  DrawHelper* drawHelper{nullptr};
  std::vector<DrawHelper*> drawHelpers;

  int width{0};
  int height{0};
};

//##################################################################################################
UILayer::UILayer():
  d(new Private())
{
  d->rootWidget = new Widget();
  d->rootWidget->setLayer(this);
  d->rootWidget->setTransparentToMouseEvents(true);
  d->drawHelper = new DarkDrawHelper(this);

  setDefaultRenderPass(tp_maps::RenderPass::GUI);
}

//##################################################################################################
UILayer::~UILayer()
{
  delete d->rootWidget;
  delete d;
}

//##################################################################################################
Widget* UILayer::rootWidget() const
{
  return d->rootWidget;
}

//##################################################################################################
void UILayer::setFont(tp_maps::FontRenderer* font)
{
  d->font = font;
}

//##################################################################################################
tp_maps::FontRenderer* UILayer::font() const
{
  return d->font;
}

//##################################################################################################
void UILayer::setDrawHelper(DrawHelper* drawHelper)
{
  d->drawHelper = drawHelper;
}

//##################################################################################################
DrawHelper* UILayer::drawHelper() const
{
  return d->drawHelper;
}

//##################################################################################################
void UILayer::render(tp_maps::RenderInfo& renderInfo)
{
  if(renderInfo.pass != defaultRenderPass())
    return;

  if(d->width != map()->width() || d->height != map()->height())
  {
    d->width  = map()->width();
    d->height = map()->height();

    d->rootWidget->setGeometry(0.0f, 0.0f, float(d->width), float(d->height));
  }

  d->rootWidget->renderInternal(renderInfo);
}

//##################################################################################################
void UILayer::invalidateBuffers()
{
  d->rootWidget->invalidateBuffersInternal();
  for(auto drawHelper : d->drawHelpers)
    drawHelper->invalidateBuffers();
}

//##################################################################################################
bool UILayer::mouseEvent(const tp_maps::MouseEvent& event)
{
  return d->rootWidget->mouseEventInternal(event);
}

//##################################################################################################
void UILayer::animate(double timestampMS)
{
  d->rootWidget->animateInternal(timestampMS);
}

//##################################################################################################
void UILayer::addDrawHelper(DrawHelper* drawHelper)
{
  d->drawHelpers.push_back(drawHelper);
}

//##################################################################################################
void UILayer::removeDrawHelper(DrawHelper* drawHelper)
{
  tpRemoveOne(d->drawHelpers, drawHelper);
}

}
