#include "Application.h"
#include "ResourceManager.h"
#include "Tetris.h"

using namespace BB;

int main(void){
  int retVal = EXIT_SUCCESS;
  Application<Tetris> App(300, 600, "Tetris");
  
  
  try{
    App.RunLoop();
  }
  catch(std::runtime_error &e){
    showErrorAndExit(e.what());
    retVal = EXIT_FAILURE;
  }

  ResourceManager::Clear();
  
  return retVal;
}
