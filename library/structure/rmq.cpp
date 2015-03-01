struct RMQ {
  typedef ll T;
  T init_val; // initial value (-INFTY if query max and +INFTY if query=min)
  function<T(T, T)> op; // max or min
  int n; // length of array
  vector<T> data; // contains 2n elements

  void init(int size, T init_val_, function<T(T, T)> op_) {
    n = size;
    data = vector<T>(2 * n, init_val);
    init_val = init_val_;
    op = op_;
  }

  // data[pos] := value
  void overwrite(int pos, T value) {
    data[n + pos] = value;
    pos = (n + pos)/2;
    while(pos > 1) {
      int lpos = pos * 2, rpos = pos * 2 + 1;
      data[pos] = op(data[lpos], data[rpos]);
      pos = pos / 2;
    }
  }

  // Returns op(data[fr], data[fr + 1], ..., data[to - 1]).
  T query(int fr, int to) {
    function<T(int, int, int, int, int)> sub;
    sub = [&](int fr, int to, int node, int la, int ra) -> T {
      if (ra <= fr || to <= la) return init_val;
      if (fr <= la && ra <= to) return data[node];

      T vl = sub(fr, to, node * 2 + 0, la, (la + ra) / 2);
      T vr = sub(fr, to, node * 2 + 1, (la + ra) / 2, ra);
      return op(vl, vr);
    };
    return sub(fr, to, 1, 0, n);
  }
};
