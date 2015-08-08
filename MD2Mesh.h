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

#ifndef _MD2MESH_H
#define _MD2MESH_H

#include "MD2MeshInterface.h"

namespace LaminarChaos
{

//! Public class for MD2MeshImpl

//! Public class for MD2MeshImpl
//! Loads an MD2 animated mesh from file, and renders it to OpenGL
class MD2Mesh
{
public:
   MD2Mesh();
   ~MD2Mesh();
   
   virtual void Render();   //!< Render previously loaded MD2 mesh to OpenGL
   virtual bool LoadMeshFile( char *sMeshFile ); //!< Load MD2 mesh from file

   virtual int GetNumFrames(); //!< returns total number of frames in animation
   virtual int GetLastFrameNumber(); //!< Returns last frame number

   virtual void SetFrameRate( int iNewFrameRate ); //!< Set new frame rate; frames per second
   virtual void SetStartFrame( int iNewStartFrame ); //!< first frame to show
   virtual void SetEndFrame( int iNewEndFrame ); //!< Set last frame to show
   virtual void ResetAnimation(); //!< Moves to first frame
   
protected:
   MD2MeshInterface *pMD2MeshImpl;		  //!< private implementation of this class
};

} // namespace LaminarChaos

#endif // _MD2MESH_H
