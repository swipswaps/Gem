/*-----------------------------------------------------------------
LOG
    GEM - Graphics Environment for Multimedia

    Copyright (c) 2003 James Tittle
    ported from pete's_plugins (www.petewarden.com)
    For information on usage and redistribution, and for a DISCLAIMER OF ALL
    WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.

-----------------------------------------------------------------*/

#ifndef _INCLUDE__GEM_PIXES_PIX_LEVELS_H_
#define _INCLUDE__GEM_PIXES_PIX_LEVELS_H_

#include "Base/GemPixObj.h"

const int nChannelFunction_Levels=256;

/*-----------------------------------------------------------------
-------------------------------------------------------------------
CLASS
    pix_levels



KEYWORDS
    pix

DESCRIPTION



-----------------------------------------------------------------*/
class GEM_EXTERN pix_levels : public GemPixObj
{
  CPPEXTERN_HEADER(pix_levels, GemPixObj);

public:

  //////////
  // Constructor
  pix_levels();

protected:

  //////////
  // Destructor
  virtual ~pix_levels();

  //////////
  // Do the processing
  virtual void    processYUVImage(imageStruct &image);

  //////////
  // Do the processing
  virtual void    processRGBAImage(imageStruct &image);

  imageStruct     myImage;
  int             nHeight;
  int             nWidth;
  int             init;

  U32*            pSource;
  U32*            pOutput;

  bool m_DoAuto;
  bool m_DoUniform;
  bool m_DoAllowInversion;

  float m_UniformInputFloor;
  float m_UniformInputCeiling;
  float m_UniformOutputFloor;
  float m_UniformOutputCeiling;

  float m_RedInputFloor;
  float m_RedInputCeiling;
  float m_RedOutputFloor;
  float m_RedOutputCeiling;

  float m_GreenInputFloor;
  float m_GreenInputCeiling;
  float m_GreenOutputFloor;
  float m_GreenOutputCeiling;

  float m_BlueInputFloor;
  float m_BlueInputCeiling;
  float m_BlueOutputFloor;
  float m_BlueOutputCeiling;

  float m_AlphaInputFloor;
  float m_AlphaInputCeiling;
  float m_AlphaOutputFloor;
  float m_AlphaOutputCeiling;

  float m_LowPercentile;
  float m_HighPercentile;

  int m_nRedTable[nChannelFunction_Levels];
  int m_nGreenTable[nChannelFunction_Levels];
  int m_nBlueTable[nChannelFunction_Levels];
  int m_nAlphaTable[nChannelFunction_Levels];

  void Pete_Levels_SetupCFSettings(int colour=GEM_RGBA);
  void Pete_Levels_CalculateAutoLevels(int colour=GEM_RGBA);
  void Pete_ChannelFunction_Render();
  void Pete_ChannelFunction_RenderYUV();


private:

  //////////
  // Static member functions
  static void     autoCallback(void *data, t_float m_DoAuto);
  static void     uniCallback(void *data, t_float m_DoUniform);
  static void     invCallback(void *data, t_float m_DoAllowInversion);
  static void     uniformCallback(void *data, t_float m_UniformInputFloor,
                                  t_float m_UniformInputCeiling, t_float m_UniformOutputFloor,
                                  t_float m_UniformOutputCeiling);
  static void     redCallback(void *data, t_float m_RedInputFloor,
                              t_float m_RedInputCeiling, t_float m_RedOutputFloor,
                              t_float m_RedOutputCeiling);
  static void     greenCallback(void *data, t_float m_GreenInputFloor,
                                t_float m_GreenInputCeiling, t_float m_GreenOutputFloor,
                                t_float m_GreenOutputCeiling);
  static void     blueCallback(void *data, t_float m_BlueInputFloor,
                               t_float m_BlueInputCeiling, t_float m_BlueOutputFloor,
                               t_float m_BlueOutputCeiling);
  static void     lowPCallback(void *data, t_float m_LowPercentile);
  static void     hiPCallback(void *data, t_float m_HighPercentile);
};

#endif  // for header file
