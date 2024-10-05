#pragma once

/** Base class for objects that need to listen to user (or AI) commands
 */

namespace BB {
  class CommandListener {
  public:
    CommandListener(){}
    virtual ~CommandListener(){}
    
    // child classes, override the methods below that you need to respond
    // to user/AI commands
    
    virtual void goUp(){}
    virtual void goLeft(){}
    virtual void goRight(){}
    virtual void goDown(){}
    
    /** Called when none of the other go*() are called
     */
    virtual void goNowhere(){}
    
    /** Select, push, pull, punch, fire, etc.
     */
    virtual void doInteractWith(){}
  };
}
