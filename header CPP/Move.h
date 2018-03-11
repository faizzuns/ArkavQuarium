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
#define MOVE_DIAGONAL_TOP_LEFT 4
#define MOVE_DIAGONAL_TOP_RIGHT 5
#define MOVE_DIAGONAL_BOTTOM_RIGHT 6
#define MOVE_DIAGONAL_BOTTOM_LEFT 7

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
