#ifndef MOVE_H
#define MOVE_H

#define GUPPY_SPEED 2
#define PIRANHA_SPEED 2
#define FISH_SPEED 2
#define SNAIL_SPEED 2
#define COIN_SPEED 1
#define FISH_FOOD_SPEED 1

class Move {
private:
  int speed;
public:

  Move();
  Move(int speed);
  ~Move();
  int getSpeed();
  void setSpeed(int speed);

  virtual void moveTop() = 0;
  virtual void moveBottom() = 0;
  virtual void moveRight() = 0;
  virtual void moveLeft() = 0;
  virtual void moveDiagonalTopLeft() = 0;
  virtual void moveDiagonalTopRight() = 0;
  virtual void moveDiagonalBottomRight() = 0;
  virtual void moveDiagonalBottomLeft() = 0;
};

#endif
