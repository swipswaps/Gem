/*
 *  pix_posterize.h
 *  gem_darwin
 *
 *  Created by James Tittle on Fri Oct 18 2002.
 *  Copyright (c) 2002 tigital. All rights reserved.
 *
 */

#ifndef _INCLUDE__GEM_PIXES_PIX_POSTERIZE_H_
#define _INCLUDE__GEM_PIXES_PIX_POSTERIZE_H_

#include "Base/GemPixObj.h"

/*-----------------------------------------------------------------
-------------------------------------------------------------------
CLASS
    pix_posterize

KEYWORDS
    pix
    yuv

DESCRIPTION

   adjustment of the Y U V channels

-----------------------------------------------------------------*/

class GEM_EXTERN pix_posterize : public GemPixObj
{
  CPPEXTERN_HEADER(pix_posterize, GemPixObj);

public:

  //////////
  // Constructor
  pix_posterize(t_floatarg);

protected:

  //////////
  // Destructor
  virtual ~pix_posterize();

  //////////
  // Do the processing
  virtual void    processYUVImage(imageStruct &image);

  void            factorMess(float f);
  void            limitMess(int l);

  t_inlet         *inletF;
  t_inlet         *inletL;
  int             factor; // 0..1 (was 0..255) /* jmz */
  int             limit; // 0,1,2,3,4
};

#endif
