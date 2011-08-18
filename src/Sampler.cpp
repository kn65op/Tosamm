/* 
 * File:   Sampler.cpp
 * Author: tomko
 * 
 * Created on 18 sierpień 2011, 15:30
 */

#include "../headers/Sampler.h"

#include <iostream>
#include <stdexcept>

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

bool Sampler::playSound(int i)
{
  try
  {
    if (samples[i])
    {
      samples[i]->play();
      return true;
    }
  }
  catch (std::out_of_range oor)
  {
  }
  return false;
}

bool Sampler::loadSound(int i, std::string file)
{
  try
  {
    if (!samples[i])
    {
      samples[i] = new Sampel(file);
    }
    else
    {
      samples[i]->load(file);
    }
  }
  catch (std::out_of_range oor)
  {
    return false;
  }
  return true;
}