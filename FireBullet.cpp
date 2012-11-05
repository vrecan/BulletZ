/* 
 * File:   FireBullet.cpp
 * Author: Ben Aldrich
 * 
 * Created on November 5, 2012, 11:19 AM
 */

#include "FireBullet.h"
#include <czmq.h>
#include <string>

FireBullet::FireBullet() {
   ctx = zctx_new();
   assert(ctx);
   mGun = zsocket_new(ctx, ZMQ_REQ);
   mHits = 0;
}

/**
 * Where to fire our messages.
 * @param location
 */
void FireBullet::Aim(std::string& location) {
    int rc = zsocket_connect (mGun, location.c_str());
    assert (rc == 0);
}

/***/
void FireBullet::Fire(std::string& msg) {
   zstr_send(mGun, msg.c_str());
}

bool FireBullet::TargetHit() {
   zmsg_t * msg = zmsg_recv(mGun);
   mHits++;
   printf("hits %d \n", mHits);
}

/**
 * 
 */
FireBullet::~FireBullet() {
   zsocket_destroy(ctx, mGun);
   zctx_destroy(&ctx);
}

