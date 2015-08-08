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
//! \brief MD2Mesh is the public interface class for MD2MeshImpl, which renderer md2 animated meshes


#include "MD2Mesh.h"
#include "MD2MeshImpl.h"

namespace LaminarChaos
{
   MD2Mesh::MD2Mesh()
   	{
 	  	   pMD2MeshImpl = 0;
 		     pMD2MeshImpl = new MD2MeshImpl;
   	}
   	
   MD2Mesh::~MD2Mesh()
   {
   		// cout << "MD2Mesh::~MD2Mesh()" << endl;
   	  if( pMD2MeshImpl != 0 )
   	  {
   	  	delete pMD2MeshImpl;
   	  	pMD2MeshImpl = 0;
   	  }
   }
   
   void MD2Mesh::Render()
   	{
   		if( pMD2MeshImpl != 0 )
   		{
   			pMD2MeshImpl->Render();
   		}
   	}
   	
   bool MD2Mesh::LoadMeshFile( char *sMeshFile )
   	{
   		if( pMD2MeshImpl != 0 )
   		{
   			return pMD2MeshImpl->LoadMeshFile( sMeshFile );
   		}
   		else
   		{
   			return false;
   		}
   	}
   int MD2Mesh::GetNumFrames()
      {
   		if( pMD2MeshImpl != 0 )
   		{
   			return pMD2MeshImpl->GetNumFrames();
   		}
   		else
   		{
   			return 0;
   		}
      }
      
   int MD2Mesh::GetLastFrameNumber()
      {
   		if( pMD2MeshImpl != 0 )
   		{
   			return pMD2MeshImpl->GetLastFrameNumber();
   		}
   		else
   		{
   			return 0;
   		}
      }

   void MD2Mesh::SetFrameRate( int iNewFrameRate )
      {
   		if( pMD2MeshImpl != 0 )
   		{
   			pMD2MeshImpl->SetFrameRate( iNewFrameRate );
   		}
      }

   void MD2Mesh::SetStartFrame( int iNewStartFrame )
      {
   		if( pMD2MeshImpl != 0 )
   		{
   			pMD2MeshImpl->SetStartFrame( iNewStartFrame );
   		}
      }
      
   void MD2Mesh::SetEndFrame( int iNewEndFrame )
      {
   		if( pMD2MeshImpl != 0 )
   		{
   			pMD2MeshImpl->SetEndFrame( iNewEndFrame );
   		}
      }
      
   void MD2Mesh::ResetAnimation()
      {
   		if( pMD2MeshImpl != 0 )
   		{
   			pMD2MeshImpl->ResetAnimation();
   		}
      }
   
} // namespace LaminarChaos

