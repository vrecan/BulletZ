/* 
 * File:   FireBullet.h
 * Author: Ben Aldrich
 *
 * Created on November 5, 2012, 11:19 AM
 */

#ifndef FIREBULLET_H
#define	FIREBULLET_H

#include <czmq.h>
#include <stdlib.h>
#include <string>

class FireBullet {
public:
   FireBullet();
   void Aim(std::string& location);
   void Fire(std::string& msg);
   bool TargetHit();
   virtual ~FireBullet();
private:
   void *mGun;
   zctx_t *ctx;
   int mHits;

};

#endif	/* FIREBULLET_H */

