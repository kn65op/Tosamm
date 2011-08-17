/* 
 * File:   MainWindow.h
 * Author: tomko
 *
 * Created on 16 sierpień 2011, 17:20
 */

#ifndef MAINWINDOW_H
#define	MAINWINDOW_H

#include <gtkmm-3.0/gtkmm.h>
#include <string>

class MainWindow : public Gtk::Window
{
public:
  MainWindow();
  ~MainWindow();
private:
  void init(void);
  void initWindow(void);
  void initMainVbox(void);
  
  std::string program_name;
  Gtk::VBox main_vbox;
  Glib::RefPtr<Gtk::ActionGroup> action_group;
  Glib::RefPtr<Gtk::UIManager> ui_manager;
};

#endif	/* MAINWINDOW_H */

