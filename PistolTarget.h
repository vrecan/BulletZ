/* 
 * File:   PistolTarget.h
 * Author: Ben Aldrich
 *
 * Created on November 5, 2012, 1:15 PM
 */

#ifndef PISTOLTARGET_H
#define	PISTOLTARGET_H

#include <string>
#include <czmq.h>

class PistolTarget {
public:
   PistolTarget();
   void prepareForShot(std::string& location);
   virtual ~PistolTarget();
   char* GetShot();
private:
   void *mBody;
   zctx_t *mCtx;
};

#endif	/* PISTOLTARGET_H */

