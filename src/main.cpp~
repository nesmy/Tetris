#include "Application.h"
#include "Menu.h"
#include "Pong.h"
#include "ResourceManager.h"
#include "Setting.h"
#include "OverMenu.h"
#include "MainSetting.h"

using namespace BB;

int main(void){
  int retVal = EXIT_SUCCESS;
  Application<MenuScene> App;
  
  ResourceManager::LoadScene<MenuScene>("Main");
  ResourceManager::LoadScene<Pong>("Game");
  ResourceManager::GetScene("Game")->start();
  ResourceManager::GetScene("Game")->loadResources();
  ResourceManager::LoadScene<SettingScene>("Setting");
  ResourceManager::LoadScene<MainSettingScene>("MainSetting");
  ResourceManager::LoadScene<OverMenuScene>("Over");
  // ResourceManager::LoadSound("Resources/Sound/over.mp3", "Over");
  // ResourceManager::LoadSound("Resources/Sound/hit.mp3", "Hit");
  // ResourceManager::LoadSound("Resources/Sound/music.mp3", "Music");
  // ResourceManager::LoadSound("Resources/Sound/coin.mp3", "Coin");

  // PlaySound(BB::ResourceManager::GetSound("Music"));
  
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
