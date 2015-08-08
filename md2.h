//! \file
//! \brief From NeHe, http://nehe.gamedev.net
//
// Stored in the CVS because that way we can control updates to this file
// and customize it to our needs

/*	Nehe SDK
	Copyright 2002 Jeff Molofee, Gregory Austwick and Others

	Title:
		MD2 class

	Version History:
		v1.00	New file		(GA 29/11/02)

	Notes:
		Used "OpenGL Game Programming" by Kevin Hawkins and Dave Astle
		as a reference for the MD2 format (Great book guys!)

	Licence:

	This SDK/library is free software, written primarily for
	teaching purposes. You can redistribute and modify it to 
	your heart's content. However, any use of this library is 
	at the user's own risk. There is no warranty. The authors 
	will not be held responsible for ANYTHING that happens as 
	a result of the use of this software. All financial/emotional/health 
	problems or anything else that happens after using this 
	software is therefore the user's own responsibility. 
	Nevertheless, if the user finds it useful, an email or a 
	mention in any credits would be appreciated, but is not 
	necessary.
*/

#ifndef MD2_H
#define MD2_H

#include "nehegeometry.h"
#include "modelloader.h"

namespace LaminarChaos {

struct TriangleMD2;
struct TexCoordsMD2;

//! Stores an MD2 Mesh; from NeHe
class MD2 : public ModelLoaderClass {
	int				numframes;		//!< the number of frames
	int				numverts;		//!< number of vertices
	int				numtexs;		//!< number of texture coords
	int				numtris;		//!< number of triangles
	int				numtextures;	//!< number of textures
	int				texx,texy;		//!< texture dimensions
	int				skinnum;		//!< skin number
	
	POS boundingboxmin;  //!< one corner of boundingbox
	POS boundingboxmax;  //!< opposite corner of boundingbox
	
	Vector			**verts;		//!< list of vertices by frame
	TriangleMD2		*tris;			//!< list of triangles
	TexCoordsMD2	*texs;			//!< list of texture coords
	std :: string	*textures;		//!< list of texture names
	// helper functions
	Vector CalcNormal(Vector v1,Vector v2,Vector v3);
public:
	MD2();
	virtual ~MD2();
	//! load a ms3d file
	virtual bool Load(const std :: string file);
	//! clear the file
	virtual void Clear();

	//! Get a mesh from a specific frame
	virtual bool Get(int frameno,int meshno,Mesh *mesh);

	//
	//	Data Access routines
	//
	//! Get the number of meshes in a frame
	virtual int GetNumMeshes() const	{ return 1; };
	//! Get the number of frames
	virtual int GetNumFrames() const	{ return numframes; };
	//! Get the number of frames per second
	virtual int GetFPS() const			{ return 1; };

	virtual const POS &GetBoundingBoxMin()  // Added Hugh Perkins 28 July 2004
	{
		 return boundingboxmin;
	}
	virtual const POS &GetBoundingBoxMax()  // Added Hugh Perkins 28 July 2004
	{
		 return boundingboxmax;
	}

	//
	//	Special MD2 routines
	//
	//! Choose a skin
	void ChooseSkin(int skin)	{ skinnum=skin; };


};

};	// namespace NeHe

#endif
