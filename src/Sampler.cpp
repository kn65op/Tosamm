/* 
 * File:   Sampler.cpp
 * Author: tomko
 * 
 * Created on 18 sierpień 2011, 15:30
 */

#include "../headers/Sampler.h"

using namespace std;

Sampler::Sampler()
{
  no_samples = 10;
  for (int i=0; i<10 ;i++)
  {
    samples.push_back(0);
  }
}

Sampler::Sampler(const Sampler& orig)
{
}

Sampler::~Sampler()
{
  for (Sampel* s: samples) //C++0x
  {
    if (s) delete s;
  }
}

