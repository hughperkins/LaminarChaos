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

#ifdef _WIN32
#include <windows.h> 
#endif

#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
#include <iostream>
using namespace std;

#include "MD2Renderer.h"

#include "md2.h"
#include "model.h"

namespace LaminarChaos
{

#define DEBUG( a ) cout << a << endl;

MD2 MD2RendererClass::MD2ModelLoader;
   
void MD2RendererClass::RenderMesh()
{
	if( pModel != 0 )
	{
	//	DEBUG(  "rendering mesh.." ); // DEBUG
		glPushMatrix();
		
		const POS &boxmin = pModel->GetBoundingBoxMin();
		const POS &boxmax = pModel->GetBoundingBoxMax();
		
	//	DEBUG(  "boundingboxes " << boxmin << " " << boxmax ); // DEBUG

//		glTranslatef( - ( boxmax.x - boxmin.x ) / 2.0f, - ( boxmax.y - boxmin.y ) / 2.0f, - ( boxmax.z - boxmin.z ) / 2.0f );
		
		glScalef( 1.0f / (boxmax.x - boxmin.x), 1.0f / (boxmax.y - boxmin.y), 1.0f / (boxmax.z - boxmin.z) );
		
		glRotatef( 90, 1,0,0);
		
		pModel->DrawTimeFrame(0,framepos);
		framepos+= 0.125;
		if( framepos >= pModel->GetNumFrames() )
		{
			framepos = 0;
		}	 
		glPopMatrix();

	//	DEBUG(  "...done" ); // DEBUG
	}
}

bool MD2RendererClass::LoadMeshFile( string sMeshFile )
{
	DEBUG(  "loading mesh file " << sMeshFile << " ... " ); // DEBUG
	
	//if( MD2ModelLoader != 0 )
//	{
		 DEBUG(  "MD2ModelLoader present" ); // DEBUG
		 if( pModel != 0 )
		 {
    		DEBUG(  "Model class has been created" ); // DEBUG
    		//DEBUG(  "number of frames prior to load is " << pModel->GetNumFrames() ); // DEBUG
    		//DEBUG(  "number of frames prior to load is " << pMD2ModelLoader->GetNumFrames() ); // DEBUG
	      if( !pModel->Load( sMeshFile, MD2ModelLoader ) )
	      {
		       DEBUG(  "couldnt load modelfile " << sMeshFile ); // DEBUG
		       return false;
	      }
	      else
	      {
						numframes= pModel->GetNumFrames();
					//	boundingboxmin = OBJECT::pMD2ModelLoader->GetBoundingBoxMin();  // htis should really be shifted into the model
					//	boundingboxmax = OBJECT::pMD2ModelLoader->GetBoundingBoxMax();
						bMeshLoaded = true;
						return true;
	      }
	  // }
	  // else
	  // {
	  // 	 DEBUG(  "ERROR: Model class not loaded" ); // DEBUG
	   //}
  }
  else
  {
  	DEBUG(  "ERROR: MD2ModelLoader not present" ); // DEBUG
  }

	// get the number of frames
	return false;
}

} // namespace LaminarChaos
