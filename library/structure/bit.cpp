struct BIT {
  typedef ll T;
  vector<T> data;
  void init(int size, T init_val) { data = vector<T>(size, init_val); }
  void add(int i, T value) {
    for (; i < len; i |= i+1) data[i] += value;
  }
  T sum(int i) {
    int s = 0;
    for (; i >= 0; i = (i & i + 1) - 1) s += data[i];
    return s;
  }
};
