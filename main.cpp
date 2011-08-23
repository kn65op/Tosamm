/* 
 * File:   main.cpp
 * Author: tomko
 *
 * Created on 16 sierpień 2011, 16:32
 */

#include <cstdlib>

#include "headers/MainWindow.h"

#include <gstreamer-0.10/gst/gst.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
  Gtk::Main gin(argc, argv);
  GError *err;
  if (!gst_init_check(&argc, &argv, &err))
  {
    //TODO: Info o błędzie
    return 1;
  }
  
  MainWindow mw;
  
  Gtk::Main::run(mw);

  return 0;
}

