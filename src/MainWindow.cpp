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
sam_buttons(),
status_bar()
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
  action_group->add(Gtk::Action::create("New", Gtk::Stock::NEW), sigc::mem_fun(*this, &MainWindow::menu_file_quit));
  action_group->add(Gtk::Action::create("LoadSample", "Wczytaj sampel"));
  action_group->add(Gtk::Action::create("LoadSample1", "Wczytaj sampel 1"), sigc::bind(sigc::mem_fun(*this, &MainWindow::menu_file_loadsample), 1));
  action_group->add(Gtk::Action::create("LoadSample2", "Wczytaj sampel 2"), sigc::bind(sigc::mem_fun(*this, &MainWindow::menu_file_loadsample), 2));
  action_group->add(Gtk::Action::create("LoadSample3", "Wczytaj sampel 3"), sigc::bind(sigc::mem_fun(*this, &MainWindow::menu_file_loadsample), 3));
  action_group->add(Gtk::Action::create("LoadSample4", "Wczytaj sampel 4"), sigc::bind(sigc::mem_fun(*this, &MainWindow::menu_file_loadsample), 4));
  action_group->add(Gtk::Action::create("LoadSample5", "Wczytaj sampel 5"), sigc::bind(sigc::mem_fun(*this, &MainWindow::menu_file_loadsample), 5));
  action_group->add(Gtk::Action::create("LoadSample6", "Wczytaj sampel 6"), sigc::bind(sigc::mem_fun(*this, &MainWindow::menu_file_loadsample), 6));
  action_group->add(Gtk::Action::create("LoadSample7", "Wczytaj sampel 7"), sigc::bind(sigc::mem_fun(*this, &MainWindow::menu_file_loadsample), 7));
  action_group->add(Gtk::Action::create("LoadSample8", "Wczytaj sampel 8"), sigc::bind(sigc::mem_fun(*this, &MainWindow::menu_file_loadsample), 8));
  action_group->add(Gtk::Action::create("LoadSample9", "Wczytaj sampel 9"), sigc::bind(sigc::mem_fun(*this, &MainWindow::menu_file_loadsample), 9));
  action_group->add(Gtk::Action::create("Exit", Gtk::Stock::QUIT), sigc::mem_fun(*this, &MainWindow::menu_file_quit));

  //tworzenie uimanager
  ui_manager = Gtk::UIManager::create();
  ui_manager->insert_action_group(action_group);
  add_accel_group(ui_manager->get_accel_group());

  Glib::ustring ui_info = "<ui>"
          " <menubar name='MenuBar'>"
          "   <menu action='MenuFile'>"
          "     <menuitem action='New'/>"
          "     <separator/>"
          "     <menu action='LoadSample'>"
          "       <menuitem action='LoadSample1'/>"
          "       <menuitem action='LoadSample2'/>"
          "       <menuitem action='LoadSample3'/>"
          "       <menuitem action='LoadSample4'/>"
          "       <menuitem action='LoadSample5'/>"
          "       <menuitem action='LoadSample6'/>"
          "       <menuitem action='LoadSample7'/>"
          "       <menuitem action='LoadSample8'/>"
          "       <menuitem action='LoadSample9'/>"
          "       </menu>"
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

  //Status bar
  main_vbox.pack_end(status_bar);

}

void MainWindow::initMainHbox(void)
{
  Gtk::Button* tmp;
  main_hbox.pack_end(but_tab, Gtk::PACK_SHRINK);
  for (int i = 0; i < 9; i++)
  {
    tmp = new Gtk::Button("_" + Helper::itoa(i + 1));
    tmp->set_use_underline(true);
    tmp->set_border_width(5);
    tmp->set_size_request(100, 75);
    tmp->signal_activate().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::sample_button_pushed), i + 1));
    tmp->signal_pressed().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::sample_button_pushed), i + 1));
    sam_buttons.push_back(tmp);
    but_tab.attach(*(sam_buttons[i]), i % 3, i % 3 + 1, i / 3, i / 3 + 1);
  }
}

void MainWindow::menu_file_quit()
{
  //TODO:  sprawdzanie zapisu
  hide();
}

void MainWindow::menu_file_loadsample(int nr)
{
  //TODO: wczytywanie sampli
  std::cout << "load: " << nr << "\n";
}

void MainWindow::sample_button_pushed(int nr)
{
  //TODO: granie sampla
  std::cout << "play: " << nr << "\n";
}