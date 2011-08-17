/* 
 * File:   Helper.cpp
 * Author: tomko
 * 
 * Created on 17 sierpień 2011, 14:55
 */

#include "../headers/Helper.h"

#include <sstream>

using namespace std;

Helper::Helper()
{
}

Helper::Helper(const Helper& orig)
{
}

Helper::~Helper()
{
}

std::string Helper::itoa(int i)
{
  std::stringstream ss;
  ss << i;
  return ss.str();
}