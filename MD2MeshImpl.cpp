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

#include "MD2MeshImpl.h"

#include "md2.h"
#include "model.h"
#include "TickCount.h"

namespace LaminarChaos
{

#define DEBUG( a ) cout << a << endl;

static MD2 MD2ModelLoader;
   
MD2MeshImpl::MD2MeshImpl()
{
	iFrameRate = 10;
   iStartFrame = 0;
   iEndFrame = 0;
   
	iStartTickCount = MVGetTickCount();
	
   bMeshLoaded = false;
}

MD2MeshImpl::~MD2MeshImpl()
{
   bMeshLoaded = false;
}

int MD2MeshImpl::GetNumFrames()
   { 
      return numframes;
   }
   
int MD2MeshImpl::GetLastFrameNumber()
{
    return iLastFrameNumber;
}

void MD2MeshImpl::SetFrameRate( int iNewFrameRate )
{
   iFrameRate = iNewFrameRate;
   ResetAnimation();
}

void MD2MeshImpl::SetStartFrame( int iNewStartFrame )
{
   iStartFrame = iNewStartFrame;
   ResetAnimation();
}
   
void MD2MeshImpl::SetEndFrame( int iNewEndFrame )
{
   iEndFrame = iNewEndFrame;
   ResetAnimation();
}
   
void MD2MeshImpl::ResetAnimation()
{
   iStartTickCount = MVGetTickCount();  
}

void MD2MeshImpl::Render()
{
	//if( pModel != 0 )
	//{
	//	DEBUG(  "rendering mesh.." ); // DEBUG
		glPushMatrix();
		
		const POS &boxmin = Model.GetBoundingBoxMin();
		const POS &boxmax = Model.GetBoundingBoxMax();
		
	//	DEBUG(  "boundingboxes " << boxmin << " " << boxmax ); // DEBUG

//		glTranslatef( - ( boxmax.x - boxmin.x ) / 2.0f, - ( boxmax.y - boxmin.y ) / 2.0f, - ( boxmax.z - boxmin.z ) / 2.0f );
		
		glScalef( 1.0f / (boxmax.x - boxmin.x), 1.0f / (boxmax.y - boxmin.y), 1.0f / (boxmax.z - boxmin.z) );
		
		glRotatef( 90, 1,0,0);
		
		int iTickCountDelta = MVGetTickCount() - iStartTickCount;
		int iNumRenderedFrames = iEndFrame - iStartFrame + 1;
		int iFrameToDraw = ( ( iTickCountDelta * iFrameRate ) / 1000 ) % iNumRenderedFrames;
		iLastFrameNumber = iFrameToDraw; // Store it so it's available to public class interface
		
		Model.DrawTimeFrame(0,iFrameToDraw);
		
		glPopMatrix();

	//	DEBUG(  "...done" ); // DEBUG
	//}
}

bool MD2MeshImpl::LoadMeshFile( char *sMeshFile )
{
   DEBUG(  "loading mesh file " << sMeshFile << " ... " ); // DEBUG
	
   if( !Model.Load( sMeshFile, MD2ModelLoader ) )
   {
      DEBUG(  "couldnt load modelfile " << sMeshFile ); // DEBUG
      return false;
   }
   else
   {
      numframes= Model.GetNumFrames();
      //	boundingboxmin = OBJECT::pMD2ModelLoader->GetBoundingBoxMin();  // htis should really be shifted into the model
      //	boundingboxmax = OBJECT::pMD2ModelLoader->GetBoundingBoxMax();
      bMeshLoaded = true;
      
      iStartFrame = 0;
      iEndFrame = numframes - 1;
	iStartTickCount = MVGetTickCount();
	
      return true;
   }
   return false;
}

} // namespace LaminarChaos
