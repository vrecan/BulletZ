/* 
 * File:   PistolTarget.cpp
 * Author: Ben Aldrich
 * 
 * Created on November 5, 2012, 1:15 PM
 */

#include "PistolTarget.h"
#include <czmq.h>

PistolTarget::PistolTarget() {
   mCtx = zctx_new();
   assert(mCtx);
   mBody = zsocket_new(mCtx, ZMQ_REP);
   assert(mBody);
}

void PistolTarget::prepareForShot(std::string& location) {
   int rc = zsocket_bind(mBody, location.c_str());
   rc = zsocket_connect(mBody, location.c_str());
   assert(rc == 0);
}

char* PistolTarget::GetShot() {
   zframe_t *shot = zframe_recv(mBody);
   zstr_send(mBody, "reply!");
   char* msg = zframe_strdup(shot);
   zframe_destroy(&shot);
   return msg;
}

PistolTarget::~PistolTarget() {
   zsocket_destroy(mCtx, mBody);
   zctx_destroy(&mCtx);
}

