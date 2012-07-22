/* 
 * File:   Player.h
 * Author: tomko
 *
 * Created on 23 sierpień 2011, 14:36
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include <gstreamer-0.10/gst/gst.h>
#include <string>

class Player
{
public:
  Player();
  Player(const Player& orig);
  ~Player();
  
  bool play(std::string file);
private:
  GstElement *playbin;
  
  int bus_callback(GstBus* bus, GstMessage *mes, gpointer data);
};

#endif	/* PLAYER_H */

