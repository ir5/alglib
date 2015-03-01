// Addition update & Min query
SegTree s;
auto delay_op = 
[](SegTree::Data now, SegTree::DT parent) -> SegTree::Data {
  return SegTree::Data{ 1, now.value + parent, now.dinfo + parent };
};
s.init(1 << 18,
       0LL,
       1LL << 60,
       [](ll a, ll b) { return min(a, b); },
       delay_op);

// Overwrite update & Max query
SegTree s;
auto delay_op = 
[](SegTree::Data now, SegTree::DT parent) -> SegTree::Data {
  return SegTree::Data{ 1, parent, parent };
};
s.init(1 << 18,
       0LL,
       -1LL << 60,
       [](ll a, ll b) { return max(a, b); },
       delay_op);
