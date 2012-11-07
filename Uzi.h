/* 
 * File:   Uzi.h
 * Author: Ben Aldrich
 *
 * Created on November 5, 2012, 4:22 PM
 */

#ifndef UZI_H
#define	UZI_H

#include <string>
#include <czmq.h>

class Uzi {
public:
   Uzi();
   void Aim(std::string& location);
   void Fire(std::string& msg);
   bool TargetHit();
   bool GetAllTargetHits();
   int GetHighWater();
   virtual ~Uzi();
private:
   void *mGun;
   zctx_t *mCtx;
   int mHits;
   int mInFlight;

};

#endif	/* UZI_H */

