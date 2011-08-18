/* 
 * File:   MainWindow.cpp
 * Author: tomko
 * 
 * Created on 16 sierpień 2011, 17:20
 */

#include <iostream>

#include "../headers/MainWindow.h"
#include "../headers/Helper.h"

using namespace std;

MainWindow::MainWindow() :
but_tab(3, 3, true),
sam_buttons()
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
  initMainHbox();
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
  //przyciski menu
  action_group = Gtk::ActionGroup::create();
  //menu plik
  action_group->add(Gtk::Action::create("MenuFile", "_Plik"));
  action_group->add(Gtk::Action::create("New", Gtk::Stock::NEW));
  action_group->add(Gtk::Action::create("Exit", Gtk::Stock::QUIT), sigc::mem_fun(*this, &MainWindow::menu_quit));

  //tworzenie uimanager
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
  } catch (const Glib::Error& ex)
  {
    std::cerr << "building menus failed: " << ex.what();
  }
  Gtk::Widget *pMenuBar = ui_manager->get_widget("/MenuBar");
  if (pMenuBar)
  {
    main_vbox.pack_start(*pMenuBar, Gtk::PACK_SHRINK);
  }
  main_vbox.pack_start(main_hbox, Gtk::PACK_SHRINK);
}

void MainWindow::initMainHbox(void)
{
  Gtk::Button* tmp;
  main_hbox.pack_end(but_tab, Gtk::PACK_SHRINK);
  for (int i = 0; i < 9; i++)
  {
    tmp = new Gtk::Button(Helper::itoa(i));
    tmp->set_border_width(5);
    tmp->set_size_request(100, 75);
    sam_buttons.push_back(tmp);
    but_tab.attach(*(sam_buttons[i]), i % 3, i % 3 + 1, i/ 3, i / 3 + 1);  }
}


void MainWindow::menu_quit()
{
  hide();
}