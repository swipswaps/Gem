/* ------------------------------------------------------------------
 * GEM - Graphics Environment for Multimedia
 *
 *  Copyright (c) 2002-2011 IOhannes m zmölnig. forum::für::umläute. IEM. zmoelnig@iem.at
 *     zmoelnig@iem.at
 *  For information on usage and redistribution, and for a DISCLAIMER
 *  OF ALL WARRANTIES, see the file, "GEM.LICENSE.TERMS"
 *
 *  this file has been generated...
 * ------------------------------------------------------------------
 */

#ifndef _INCLUDE__GEM_OPENGL_GEMGLCOLOR3I_H_
#define _INCLUDE__GEM_OPENGL_GEMGLCOLOR3I_H_

#include "Base/GemGLBase.h"

/*
 CLASS
        GEMglColor3i
 KEYWORDS
        openGL  0
 DESCRIPTION
        wrapper for the openGL-function
        "glColor3i( GLint red, GLint green, GLint blue)"
 */

class GEM_EXTERN GEMglColor3i : public GemGLBase
{
  CPPEXTERN_HEADER(GEMglColor3i, GemGLBase);

public:
  // Constructor
  GEMglColor3i (t_float, t_float, t_float);     // CON

protected:
  // Destructor
  virtual ~GEMglColor3i ();
  // Do the rendering
  virtual void  render (GemState *state);

  // variables
  GLint red;            // VAR
  virtual void  redMess(t_float);       // FUN

  GLint green;          // VAR
  virtual void  greenMess(t_float);     // FUN

  GLint blue;           // VAR
  virtual void  blueMess(t_float);      // FUN


private:

  // we need some inlets
  t_inlet *m_inlet[3];

  // static member functions
  static void    redMessCallback (void*, t_float);
  static void    greenMessCallback (void*, t_float);
  static void    blueMessCallback (void*, t_float);
};
#endif // for header file
