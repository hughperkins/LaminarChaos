// Copyright Hugh Perkins 2005
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
// You should have received a copy of the GNU General Public License along
// with this program in the file licence.txt; if not, write to the
// Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-
// 1307 USA
// You can find the licence also on the web at:
// http://www.opensource.org/licenses/gpl-license.php
//

//! \file
//! \brief MD2Renderer renderes MD2 animated meshes

#ifndef _MD2MESHIMPL_H
#define _MD2MESHIMPL_H

#include "model.h"

#include "MD2MeshInterface.h"

namespace LaminarChaos
{

//! Implementation of MD2Mesh; loads and renders MD2 meshes to OpenGl
//!
//! Implementation of MD2Mesh; loads and renders MD2 meshes to OpenGl
//! Note that the end user will load MD2Mesh
//! MD2Mesh will load MD2MeshImpl into its pointer to MD2MeshInterface
//! This produces a fairly clean public interface, and eliminates the
//! need for calling applications to have access to more than a couple 
//! of include files
class MD2MeshImpl : public MD2MeshInterface
{
public:
   MD2MeshImpl();
   ~MD2MeshImpl();
   
   virtual void Render();
   virtual bool LoadMeshFile( char *sMeshFile );
   
   //! returns total number of frames in animation
   virtual int GetNumFrames();
   virtual int GetLastFrameNumber(); //!< Returns last frame number
   
   virtual void SetFrameRate( int iNewFrameRate ); //!< Set new frame rate; frames per second
   virtual void SetStartFrame( int iNewStartFrame ); //!< first frame to show
   virtual void SetEndFrame( int iNewEndFrame ); //!< Set last frame to show
   virtual void ResetAnimation(); //!< Moves to start frame
   
protected:
   bool bMeshLoaded;
   
   MeshModel Model;
   
   int iFrameRate; //!< animation framerate, frames per second
   int iStartFrame; //!< starting frame to show
   int iEndFrame; //!< ending frame to show
   
   int numframes;	//!< number of frames
  // float framepos;	//!< frame position
   int iLastFrameNumber; //!< number of last rendered frame
   
   int iStartTickCount; //!< Starting tick count, used to control animation real frame rate
};

} // namespace LaminarChaos

#endif // _MD2MESHIMPL_H
