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

#include "ModelInterface.h"
#include "modelloader.h"
#include "md2.h"

namespace LaminarChaos
{

class MD2RendererClass
{
public:
   MD2RendererClass()
   {
      bMeshLoaded = false;
   }
   
   virtual void MD2RendererClass::RenderMesh();
   virtual bool MD2RendererClass::LoadMeshFile( string sMeshFile );
   
protected:
   bool bMeshLoaded;
   
   ModelInterface *pModel;		  //!< Generated from ModelFactory, to keep dependencies down.  ModelFactory is stored as static in OBJECT::
   
   static MD2 MD2ModelLoader;
   
   int numframes;	//!< number of frames
   float framepos;	//!< frame position
};

} // namespace LaminarChaos
