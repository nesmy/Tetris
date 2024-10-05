#pragma once

#include "CommandListener.h"
#include "Object.h"
#include "Config.h"

namespace BB {

  // class Object;
  /** Base class for "scenes"
   * A Scene is a "place where action occurs" It can be title screen, a loading screen,
   * a cut-scene, or an entire world in which players, actors, and other objects interact.
   *
   * At a technical level, a scene loads and manages all object that exist in a scene, It
   * processes or passes on user inputs to the relevant objects, and performs any simulation,
   * Artificial Intelligence (AI) calculations, etc., that are needed to display the scene.
   * Scenes can also have audio.
   *
   * Child classes can set the playerAvatar, which is the object that user input will be
   * forwarded, unless the command methods (e.g., goRight()) are overriden.
   */
  class Scene : public CommandListener {
  public:
    Scene(){
      int sceneHeight = GetScreenHeight();
      groundYPos = (3 * sceneHeight) / 4;
      gravity = 1;
      exit = false;
    }
    virtual ~Scene(){freeResources();}

    /** Loads the resources needed to display this scene (e.g, the entire game level).
     *
     * @throws std::runtime_error if something went wrong
     */
    virtual void loadResources(){}

    /** Frees up the resources used in this scene.
     * The default behaviour is to empty this object of all items, e.g., the objects, playerAvatar, etc.
     */
    virtual void freeResources(){
      playerAvatar.reset();
      Objects.clear();
    }

    /** Called when the scene starts.
     * This should start any background music or sound, and perform any other initialization
     * that isn't already handled by loadResources()
     */
    virtual void start(){}

    /** Updates the scene.
     * This should perform tasks such as:
     * - Perform any artificial Intelligence (AI) calculations
     * - Update animation
     * - Simulate the world, including triggering sound effects & maybe changing the music
     *
     * @return std::shared_ptr<Scene> the next scene, or nullptr if this scene
     */
    virtual std::shared_ptr<Scene> update(){
      // for(auto &object : ResourceManager::GetObjects()){
      //   Objects.emplace_back(object);
      // }
      for(auto &object : Objects){
      // object->Position.x += object->Velocity.x;
      // object->Position.y += object->Velocity.y;

	auto boundingRect = object->getBoundingBox();
	auto distToGround = groundYPos - (boundingRect.y + boundingRect.height);
	bool isOnGround = distToGround <= 0;
	
	if(isOnGround){
	  // object->Velocity.y = 0;
	  // object->Position.y += distToGround;
	} else {
	  // object->Velocity.y += gravity;
	}
	
	object->update(isOnGround);
      }
      
      // if(exit){
	// exit = false;
	// return std::make_unique<MenuScene>();
      // }
      // else {
	return nullptr;
      // }
    }

    /** Returns true if the program should quit.
     */
    virtual bool shouldQuit() { return false;}

    /** Draws the scene to display.
     */
    virtual void Draw(){
      ClearBackground(BLACK);
      // for(auto &object : BB::ResourceManager::GetObjects()){
      //   object->Draw();
      // }
      if(Objects.size()){
	for(auto &object : Objects){
	  object->Draw();
	}
      } else{
	// DrawText("This scene has no content. Add some objects, or override Scene::Draw()", 20, 20, 20, RED);
      }
    }

    virtual void goUp(){
    if(playerAvatar){
      playerAvatar->goUp();
    }
  }

  virtual void goLeft(){
    if(playerAvatar){
      playerAvatar->goLeft();
    }
  }

  virtual void goRight(){
    if(playerAvatar){
      playerAvatar->goRight();
    }
  }

  virtual void goDown(){
    if(playerAvatar){
      playerAvatar->goDown();
    }
  }

  virtual void goNowhere(){
    if(playerAvatar){
      playerAvatar->goNowhere();
    }
  }

  virtual void doInteractWith(){
    if(playerAvatar){
      playerAvatar->doInteractWith();
    }
  }

  virtual void doExit(){
    exit = true;
  }

  protected:
    /** The player's avatar.
     * By default, all user input will be forwarded to the object that the player(user) is
     * controlling.
     */
    std::shared_ptr<CommandListener> playerAvatar;

    /** List of objects in the scene, ordered from top to bottom.
     * NOTE: The player should also be in this list
     */
    std::list<std::shared_ptr<Object>> Objects;

    /** The ground's y position in pixels from the top of the screen.
     */
    int groundYPos;

    /** Downward acceleration due to gravity.
     */
    float gravity;

    bool exit;

    // TO CHANGE
  public:
    bool easy, medium, hard;

  };
}
