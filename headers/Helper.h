/* 
 * File:   Helper.h
 * Author: tomko
 *
 * Created on 17 sierpień 2011, 14:55
 */

#ifndef HELPER_H
#define	HELPER_H

#include <string>

class Helper
{
public:
  static std::string itoa(int i);
private:

  Helper();
  Helper(const Helper& orig);
  virtual ~Helper();
};

#endif	/* HELPER_H */

