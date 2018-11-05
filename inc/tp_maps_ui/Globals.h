#ifndef tp_maps_ui_Globals_h
#define tp_maps_ui_Globals_h

#include "tp_utils/StringID.h"

#if defined(TP_MAPS_UI_LIBRARY)
#  define TP_MAPS_UI_SHARED_EXPORT TP_EXPORT
#else
#  define TP_MAPS_UI_SHARED_EXPORT TP_IMPORT
#endif

//##################################################################################################
//! UI conponents for use in tp_maps.
namespace tp_maps_ui
{

//##################################################################################################
enum class Orientation
{
  Horizontal,
  Vertical
};

//##################################################################################################
enum class HAlignment
{
  Left,
  Center,
  Right
};

//##################################################################################################
enum class VAlignment
{
  Top,
  Center,
  Bottom
};

//##################################################################################################
enum class CheckState
{
  Unchecked,
  PartiallyChecked,
  Checked
};

//##################################################################################################
struct Dim
{
  float sizePixels{0.0f};
  float sizeFraction{1.0f};

  //################################################################################################
  Dim()=default;

  //################################################################################################
  Dim(float sizePixels_, float sizeFraction_):
    sizePixels(sizePixels_),
    sizeFraction(sizeFraction_)
  {

  }

  //################################################################################################
  float calc(float parentSize) const
  {
    return (parentSize*sizeFraction) + sizePixels;
  }

  //################################################################################################
  static inline Dim full()
  {
    return Dim(0.0f, 1.0f);
  }

  //################################################################################################
  static inline Dim zero()
  {
    return Dim(0.0f, 0.0f);
  }
};

}

#endif