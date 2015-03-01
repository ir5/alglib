struct SegTree {
  typedef ll T; // type of array
  typedef ll DT; // type of delay information
  const DT init_dinfo = 0; // initial value of dinfo

  struct Data {
    bool delay; // if the node has delay information
    T value;    // node value. This must be correct if the node has no delay.
    DT dinfo;   // delay information
  };

  int n;
  vector<Data> data;
  T inf_value;
  function<T(T, T)> op;
  function<Data(Data, DT)> delay_op;

  void init(int size, T init_value_, T inf_value_, function<T(T, T)> op_,
      function<Data(Data, DT)> delay_op_) {
    n = size;
    data = vector<Data>(size * 2, {0, init_value_, init_dinfo});
    inf_value = inf_value_;
    op = op_;
    delay_op = delay_op_;
  }

  void remove_delay(int node) {
    if (data[node].delay) {
      if (node < n) {
        data[node * 2 + 0] = delay_op(data[node * 2 + 0], data[node].dinfo);
        data[node * 2 + 1] = delay_op(data[node * 2 + 1], data[node].dinfo);
      }
      data[node].delay = 0;
      data[node].dinfo = init_dinfo;
    }
  }

  void update(int fr, int to, DT value) {
    function<void(int, int, int, int, int)> sub;
    sub = [&](int node, int lp, int rp, int fr, int to) {
      if (rp <= fr || to <= lp) return;
      if (fr <= lp && rp <= to) {
        data[node] = delay_op(data[node], value);
        return;
      }
      remove_delay(node);
      int mp = (lp + rp) / 2;
      sub(node * 2 + 0, lp, mp, fr, to);
      sub(node * 2 + 1, mp, rp, fr, to);

      if (node < n) {
        data[node].value
          = op(data[node * 2 + 0].value, data[node * 2 + 1].value);
      }
    };

    sub(1, 0, n, fr, to);
  }

  T query(int fr, int to) {
    function<T(int, int, int, int, int)> sub;
    sub = [&](int node, int lp, int rp, int fr, int to) {
      if (rp <= fr || to <= lp) return inf_value;
      if (fr <= lp && rp <= to) {
        return data[node].value;
      }
      remove_delay(node);
      int mp = (lp + rp) / 2;
      T vl = sub(node * 2 + 0, lp, mp, fr, to);
      T vr = sub(node * 2 + 1, mp, rp, fr, to);
      return op(vl, vr);
    };

    return sub(1, 0, n, fr, to);
  }

  // For debug.
  void out() {
    for (int i = 1; i < 2 * n; ++i) {
      cout << "(" << data[i].value << "," << data[i].dinfo << ") ";
      if (__builtin_popcount(i+1) == 1) cout << endl;
    }
  }
};
