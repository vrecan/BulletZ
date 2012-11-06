/* 
 * File:   main.cpp
 * Author: Ben Aldrich
 *
 * Created on November 5, 2012, 11:19 AM
 */

#include <stdlib.h>
#include "Pistol.h"
#include "Uzi.h"
#include "PistolTarget.h"
#include <string>

/*
 * 
 */
int main(int argc, char** argv) {
   Uzi Uzi;
   PistolTarget target;
   std::string location("ipc:///tmp/uzi.socket");
   printf("Preparing Target\n");
   target.prepareForShot(location);
   printf("Aiming\n");
   Uzi.Aim(location);
   printf("shooting\n");
   while (true) {
      std::string msg = "woo!";
      Uzi.Fire(msg);
      char* shot = target.GetShot();
      delete shot;
   }
   return 0;
}

