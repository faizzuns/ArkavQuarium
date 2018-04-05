#ifndef MOVE_H
#define MOVE_H

#define GUPPY_SPEED 2
#define PIRANHA_SPEED 2
#define FISH_SPEED 2
#define SNAIL_SPEED 2
#define COIN_SPEED 1
#define FISH_FOOD_SPEED 1

#define MOVE_TOP 0
#define MOVE_BOTTOM 1
#define MOVE_RIGHT 2
#define MOVE_LEFT 3

class Move {
public:
  virtual void moveTop() = 0;
  virtual void moveBottom() = 0;
  virtual void moveRight() = 0;
  virtual void moveLeft() = 0;
};

#endif
