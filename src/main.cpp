#include <iostream>
#include <../include/AppAgent.hpp>
#include <../include/Logger.hpp>


int main(int argc, char const *argv[]) {
 
  LOG("Hello App");

  AppAgent l_appAgent{};

  l_appAgent.run();

  return 0;
  
}
