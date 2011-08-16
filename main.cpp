/* 
 * File:   main.cpp
 * Author: tomko
 *
 * Created on 16 sierpień 2011, 16:32
 */

#include <cstdlib>

#include "headers/MainWindow.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
  Gtk::Main gin(argc, argv);
  
  MainWindow mw;
  
  Gtk::Main::run(mw);

  return 0;
}

