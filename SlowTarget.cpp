/* 
 * File:   SlowTarget.cpp
 * Author: Ben Aldrich
 * 
 * Created on November 5, 2012, 1:15 PM
 */

#include "SlowTarget.h"
#include <czmq.h>

SlowTarget::SlowTarget() {
   mCtx = zctx_new();
   assert(mCtx);
   mBody = zsocket_new(mCtx, ZMQ_REP);
   assert(mBody);
}

void SlowTarget::prepareForShot(std::string& location) {
   int rc = zsocket_bind(mBody, location.c_str());
   rc = zsocket_connect(mBody, location.c_str());
   assert(rc == 0);
}

std::string SlowTarget::GetShot() {
   zmsg_t * msg = zmsg_recv(mBody);
   zstr_send(mBody, "reply!");
   std::string result = zmsg_popstr(msg);
   zmsg_destroy(&msg);
   return result;
}

SlowTarget::~SlowTarget() {
   zsocket_destroy(mCtx, mBody);
   zctx_destroy(&mCtx);
}

