/* 
 * File:   Pistol.h
 * Author: Ben Aldrich
 *
 * Created on November 5, 2012, 11:19 AM
 */

#ifndef PISTOL_H
#define	PISTOL_H

#include <czmq.h>
#include <stdlib.h>
#include <string>

class Pistol {
public:
   Pistol();
   void Aim(std::string& location);
   void Fire(std::string& msg);
   bool TargetHit();
   virtual ~Pistol();
private:
   void *mGun;
   zctx_t *mCtx;
   int mHits;

};

#endif	/* PISTOL_H */

