#pragma once

#include "CommandListener.h"
#include "Config.h"

namespace BB {

  class Object;
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
    Scene();
    virtual ~Scene();

    /** Loads the resources needed to display this scene (e.g, the entire game level).
     *
     * @throws std::runtime_error if something went wrong
     */
    virtual void loadResources();

    /** Frees up the resources used in this scene.
     * The default behaviour is to empty this object of all items, e.g., the objects, playerAvatar, etc.
     */
    virtual void freeResources();

    /** Called when the scene starts.
     * This should start any background music or sound, and perform any other initialization
     * that isn't already handled by loadResources()
     */
    virtual void start();

    /** Updates the scene.
     * This should perform tasks such as:
     * - Perform any artificial Intelligence (AI) calculations
     * - Update animation
     * - Simulate the world, including triggering sound effects & maybe changing the music
     *
     * @return std::shared_ptr<Scene> the next scene, or nullptr if this scene
     */
    virtual std::shared_ptr<Scene> update();

    /** Returns true if the program should quit.
     */
    virtual bool shouldQuit();

    /** Draws the scene to display.
     */
    virtual void Draw();
    virtual void goUp();
    virtual void goLeft();
    virtual void goRight();
    virtual void goDown();
    virtual void goNowhere();
    virtual void doInteractWith();
    virtual void doExit();

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
