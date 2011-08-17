/* 
 * File:   MainWindow.cpp
 * Author: tomko
 * 
 * Created on 16 sierpień 2011, 17:20
 */

#include <iostream>

#include "../headers/MainWindow.h"

using namespace std;

MainWindow::MainWindow()
{
  init();
  show_all_children(true);
}

MainWindow::~MainWindow()
{
}

void MainWindow::init(void)
{
  initWindow();
  initMainVbox();
}

void MainWindow::initWindow(void)
{
  program_name = "Tosamm";
  set_title(program_name);
  set_default_size(800, 600);
  add(main_vbox);
}

void MainWindow::initMainVbox(void) //menu górne
{
  action_group = Gtk::ActionGroup::create();
  action_group->add(Gtk::Action::create("MenuFile", "_File"));
  action_group->add(Gtk::Action::create("New", Gtk::Stock::NEW));
  action_group->add(Gtk::Action::create("Exit", Gtk::Stock::QUIT));

  ui_manager = Gtk::UIManager::create();
  ui_manager->insert_action_group(action_group);
  add_accel_group(ui_manager->get_accel_group());

  Glib::ustring ui_info = "<ui>"
          " <menubar name='MenuBar'>"
          "   <menu action='MenuFile'>"
          "     <menuitem action='New'/>"
          "     <separator/>"
          "     <menuitem action='Exit'/>"
          "   </menu>"
          " </menubar>"
          "</ui>";
  try
  {
    ui_manager->add_ui_from_string(ui_info);
  }  catch (const Glib::Error& ex)
  {
    std::cerr << "building menus failed: " << ex.what();
  }
  Gtk::Widget *pMenuBar = ui_manager->get_widget("/MenuBar");
  if (pMenuBar)
  {
    main_vbox.pack_start(*pMenuBar, Gtk::PACK_SHRINK);
  }

}


