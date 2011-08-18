/* 
 * File:   Sampler.h
 * Author: tomko
 *
 * Created on 18 sierpień 2011, 15:30
 */

#ifndef SAMPLER_H
#define	SAMPLER_H

#include <vector>
#include "Sampel.h"

class Sampler
{
public:
  Sampler();
  Sampler(const Sampler& orig);
  ~Sampler();
private:
  std::vector<Sampel*> samples;
  int no_samples;
};

#endif	/* SAMPLER_H */

