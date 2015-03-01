struct Dice {
  //        ____   back
  //       /top/| L
  //      /___/ |
  // left |fro|right
  //      |___|/
  //        ^
  //       bottom

  // each index should be 0-indexed
  int top, front, right, back, bottom, left;
  Dice() {}
  Dice(int top, int front, int right)
      : top(top),
        front(front),
        right(right),
        back(5 - front),
        bottom(5 - top),
        left(5 - right) {}

  void rot(int dir) {
    // standard rotation
    // dirs:   0
    //        /
    //  3 <--*--> 1
    //      /
    //     2
    if (dir == 0) {
      top = front;
      front = bottom;
    }  // rotation to back direction
    if (dir == 1) {
      right = top;
      top = left;
    }  // ditto
    if (dir == 2) {
      front = top;
      top = back;
    }
    if (dir == 3) {
      top = right;
      right = bottom;
    }

    back = 5 - front;
    bottom = 5 - top;
    left = 5 - right;
  }

  void rot_side(int dir) {
    // rotate toward left or right. top and front do not change.
    // 3 <-----> 1
    assert(dir % 2 == 1);
    rot(0);
    rot(dir);
    rot(2);
  }

  int naive_hash() { return top * 36 + front * 6 + right; }
  int comp_hash() { return top * 6 + front; }
};
