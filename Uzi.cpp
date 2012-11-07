/* 
 * File:   Uzi.cpp
 * Author: Ben Aldrich
 * 
 * Created on November 5, 2012, 4:22 PM
 */

#include "Uzi.h"

Uzi::Uzi() {
   mCtx = zctx_new();
   assert(mCtx);
   mGun = zsocket_new(mCtx, ZMQ_DEALER);
   mHits = 0;
   mInFlight = 0;
}

int Uzi::GetHighWater() {
   return 250;
}

/**
 * Where to fire our messages.
 * @param location
 */
void Uzi::Aim(std::string& location) {
   int rc = zsocket_connect(mGun, location.c_str());
   assert(rc == 0);
}

/***/
void Uzi::Fire(std::string& msg) {
   while (mInFlight >= GetHighWater()) {
      GetAllTargetHits();
   }
   zmsg_t *sMsg = zmsg_new();
   zmsg_addmem(sMsg, "", 0);
   zmsg_addmem(sMsg, msg.c_str(), msg.size());
   zmsg_send(&sMsg, mGun);
   zmsg_destroy(&sMsg);
   mInFlight++;
}

bool Uzi::GetAllTargetHits() {
   int hwm = GetHighWater() - 50;

   for (int i = 0; i <= hwm; i++) {
      TargetHit();
   }
}

bool Uzi::TargetHit() {
   zmsg_t * msg = zmsg_recv(mGun);
   mHits++;
   mInFlight--;
   printf("hits %d \n", mHits);
   printf("in flight %d \n", mInFlight);
   zmsg_destroy(&msg);
}

/**
 * 
 */
Uzi::~Uzi() {
   zsocket_destroy(mCtx, mGun);
   zctx_destroy(&mCtx);
}

