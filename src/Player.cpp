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
  playbin = gst_element_factory_make("playbin2", "playbin");
}

Player::Player(const Player& orig)
{
}

Player::~Player()
{
  gst_object_unref(GST_OBJECT(playbin));
}

bool Player::play(std::string file)
{
  GstBus *bus;
  
  g_object_set(G_OBJECT(playbin), "uri", file.c_str(), NULL);

  bus = gst_pipeline_get_bus(GST_PIPELINE(playbin));
  gst_bus_add_watch(bus, bus_callback, 0);
  gst_object_unref(bus);

  gst_element_set_state(playbin, GST_STATE_PLAYING);

  /* now run */
  //g_main_loop_run(loop);

  /* also clean up */
  gst_element_set_state(playbin, GST_STATE_NULL);
  //gst_object_unref(GST_OBJECT(play));
  return true;
}

int Player::bus_callback(GstBus* bus, GstMessage* mes, gpointer data)
{
  return 0;
}