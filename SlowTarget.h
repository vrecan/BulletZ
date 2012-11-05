/* 
 * File:   SlowTarget.h
 * Author: Ben Aldrich
 *
 * Created on November 5, 2012, 1:15 PM
 */

#ifndef SLOWTARGET_H
#define	SLOWTARGET_H

#include <string>
#include <czmq.h>

class SlowTarget {
public:
   SlowTarget();
   void prepareForShot(std::string& location);
   virtual ~SlowTarget();
   std::string GetShot();
private:
   void *mBody;
   zctx_t *mCtx;
};

#endif	/* SLOWTARGET_H */

