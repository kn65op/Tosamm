/* 
 * File:   Player.cpp
 * Author: tomko
 * 
 * Created on 23 sierpień 2011, 14:36
 */

#include "../headers/Player.h"

using namespace std;

Player::Player()
{
  GError *err;
  if (!gst_is_initialized())
  {
    if (!gst_init_check(0, 0, &err))
    {
      //TODO: info o błędzie
    }
  }
}

Player::Player(const Player& orig)
{
}

Player::~Player()
{
}

