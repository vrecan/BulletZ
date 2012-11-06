/* 
 * File:   Pistol.cpp
 * Author: Ben Aldrich
 * 
 * Created on November 5, 2012, 11:19 AM
 */

#include "Pistol.h"

Pistol::Pistol() {
   mCtx = zctx_new();
   assert(mCtx);
   mGun = zsocket_new(mCtx, ZMQ_REQ);
   mHits = 0;
}

/**
 * Where to fire our messages.
 * @param location
 */
void Pistol::Aim(std::string& location) {
    int rc = zsocket_connect (mGun, location.c_str());
    assert (rc == 0);
}

/***/
void Pistol::Fire(std::string& msg) {
   zstr_send(mGun, msg.c_str());
}

bool Pistol::TargetHit() {
   zmsg_t * msg = zmsg_recv(mGun);
   mHits++;
   printf("hits %d \n", mHits);
}

/**
 * 
 */
Pistol::~Pistol() {
   zsocket_destroy(mCtx, mGun);
   zctx_destroy(&mCtx);
}