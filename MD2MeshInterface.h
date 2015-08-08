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

#ifndef _MD2MESHINTERFACE_H
#define _MD2MESHINTERFACE_H

namespace LaminarChaos
{

//! Public interface class for MD2MeshImpl

//! Public interface class for MD2MeshImpl
//! Loads an MD2 animated mesh from file, and renders it to OpenGL
class MD2MeshInterface
{
public:
//   MD2MeshInterface();
//   ~MD2MeshInterface();
   
   virtual void Render() = 0;   //!< Render previously loaded MD2 mesh to OpenGL
   virtual bool LoadMeshFile( char *sMeshFile ) = 0; //!< Load MD2 mesh from file

   virtual int GetNumFrames() = 0; //!< returns total number of frames in animation
   virtual int GetLastFrameNumber() = 0; //!< Returns last frame number

   virtual void SetFrameRate( int iNewFrameRate ) = 0; //!< Set new frame rate; frames per second
   virtual void SetStartFrame( int iNewStartFrame ) = 0; //!< first frame to show
   virtual void SetEndFrame( int iNewEndFrame ) = 0; //!< Set last frame to show
   virtual void ResetAnimation() = 0; //!< Moves to first frame
};

} // namespace LaminarChaos

#endif // _MD2MESHINTERFACE_H
