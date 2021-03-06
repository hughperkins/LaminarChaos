// Copyright Hugh Perkins 2004
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
//! \brief Wrapper for GetTickCount


#ifdef _WIN32
#include <windows.h>
//#include <GL/glut.h>
#else
#include <sys/time.h>
#endif


//! MVGetTickCount returns number of milliseconds since some arbitrary point
//! that's fixed for the life of program execution, eg system uptime
int MVGetTickCount()
{
	#ifdef _WIN32
	// return glutGet( GLUT_ELAPSED_TIME );
	  return GetTickCount();
	#else
	   struct timeval tv;
	   struct timezone tz;
	   gettimeofday( &tv, &tz );
	   return( tv.tv_sec * 1000 + tv.tv_usec / 1000 );
	#endif
}

