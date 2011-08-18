/* 
 * File:   Sampel.h
 * Author: tomko
 *
 * Created on 18 sierpień 2011, 15:31
 */

#ifndef SAMPEL_H
#define	SAMPEL_H

#include <string>

class Sampel
{
public:
  Sampel(std::string File);
  Sampel(const Sampel& orig);
  ~Sampel();
  
  void play();
  void load(std::string);
private:

};

#endif	/* SAMPEL_H */

