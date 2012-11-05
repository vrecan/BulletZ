/* 
 * File:   main.cpp
 * Author: Ben Aldrich
 *
 * Created on November 5, 2012, 11:19 AM
 */

#include <stdlib.h>
#include "FireBullet.h"
#include "SlowTarget.h"
#include <string>

/*
 * 
 */
int main(int argc, char** argv) {
   FireBullet pistol;
   SlowTarget target;
   std::string location("tcp://127.0.0.1:5513");
   target.prepareForShot(location);
   pistol.Aim(location);
   while (true) {
      std::string msg = "woo!";
      pistol.Fire(msg);
      target.GetShot();
      assert(pistol.TargetHit());
   }
   return 0;
}

