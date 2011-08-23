/* 
 * File:   Player.h
 * Author: tomko
 *
 * Created on 23 sierpień 2011, 14:36
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include <gstreamer-0.10/gst/gst.h>

class Player
{
public:
  Player();
  Player(const Player& orig);
  virtual ~Player();
private:
  GstElement playbin;
};

#endif	/* PLAYER_H */

