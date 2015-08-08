//! \file
//! \brief From NeHe, http://nehe.gamedev.net, the licence for this file is freeware
//
// Stored in the CVS because that way we can control updates to this file
// and customize it to our needs

/*	Nehe SDK
	Copyright 2002 Jeff Molofee, Gregory Austwick and Others

	Title:
		Model class

	Version History:
		v1.00	New file				(GA 21/11/02)
		v1.01	Added Access function 
					and proxies			(GA 05/01/03)

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

#ifndef MODEL_H
#define MODEL_H

//#include "opengl.h"
#include "modelframe.h"
#include "modelloader.h"
#include <string>

namespace LaminarChaos {

class MeshModel
{
public:
	int			numframes;	// number of frames
	float		fps;		// frames per second
	ModelFrame	*frames;	// the frames themselves
	
	MeshModel();
	MeshModel(const MeshModel &model);
	~MeshModel();
	
	POS BoundingBoxMin;
	POS BoundingBoxMax;

	//
	//	Setup commands
	//

	// Setup the model
	//	Params:
	//		num:		the number of frames
	//		framesec:	the number of frames per second
	virtual bool Setup(int num,float framesec);

	// Add a frame
	//	Params:
	//		num:	the frame number
	//		frame:	the frame to add
	void Add(int num,ModelFrame &frame);

	// Load a model using a model loader class
	//	Params:
	//		name:	the file name of the model
	//		loader:	the file loader class
	virtual bool Load(std :: string name,ModelLoaderClass &loader );

	// Clear the model
	virtual void Clear();

	//
	//	Draw commands
	//

	// Draw a specific frame
	virtual void DrawFrame(int frame);
	// Draw the model at a time after a specific frame (time in seconds)
	//	if fps isn't available, fps is one.
	virtual void DrawTimeFrame(int startframe,float time);

	//
	//	Data Access functions
	//

	// Get the number of frames
	virtual int GetNumFrames()	{ return numframes; };

	// get the model frames
	ModelFrame *GetFrame(int num) { if(num<0 || num>=numframes) return &frames[num]; else return NULL; };


	virtual const POS &GetBoundingBoxMin()  // Added Hugh Perkins 28 July 2004
	{
		 return BoundingBoxMin;
	}
	virtual const POS &GetBoundingBoxMax()  // Added Hugh Perkins 28 July 2004
	{
		 return BoundingBoxMax;
	}
};

};	// namespace NeHe

// simple proxy
#define NMODEL NeHe :: MeshModel

#endif
