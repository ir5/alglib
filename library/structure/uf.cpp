struct UF {
  vector<int> data;
  void init(int size) { data = vector<int>(size, -1); }
  int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
  bool find(int x, int y) { return root(x) == root(y); }
  void merge(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[x] < data[y]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
  }
};
