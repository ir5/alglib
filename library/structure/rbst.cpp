struct RBST {
  typedef ll T;                         // type of node
  static const T init_val = 1LL << 60;  // initial value of operator

  // operator of query
  static T op(T a, T b) { return min(a, b); }

  T val;  // node value
  // additional info (e.g., min, max, sum, etc.)
  // It holds that info := op(l->info, val, r->info).
  T info;
  int size;  // size of subtrees
  RBST* l;   // left subtree
  RBST* r;   // right subtree
  RBST(T val) : val(val), l(NULL), r(NULL), size(1) {
    info = op(val, init_val);
  }

  RBST* update() {
    size = 1 + (l ? l->size : 0) + (r ? r->size : 0);
    info = op(op(l ? l->info : init_val, val), r ? r->info : init_val);
    return this;
  }
};

int count(RBST* t) { return t ? t->size : 0; }

// Split data[0 .. n-1] into data[0 .. k-1] and data[k .. n-1]
pair<RBST*, RBST*> split(RBST* t, int k) {
  if (t == NULL) return pair<RBST*, RBST*>(NULL, NULL);
  int lsize = count(t->l);
  if (k <= lsize) {
    auto s = split(t->l, k);
    t->l = s.second;
    return make_pair(s.first, t->update());
  } else {
    auto s = split(t->r, k - lsize - 1);
    t->r = s.first;
    return make_pair(t->update(), s.second);
  }
}

// Merge two BRSTs.
RBST* merge(RBST* a, RBST* b) {
  if (!a) {
    return b;
  }
  if (!b) {
    return a;
  }
  if (rand() % (a->size + b->size) < a->size) {
    a->r = merge(a->r, b);
    return a->update();
  } else {
    b->l = merge(a, b->l);
    return b->update();
  }
}

// op(data[lpos], data[lpos + 1], ..., data[rpos - 1])
RBST::T query(RBST* t, int lpos, int rpos) {
  if (t == NULL || rpos <= 0 || lpos >= count(t)) {
    return RBST::init_val;
  }
  if (lpos < 0 && rpos >= count(t)) return t->info;

  int lsize = count(t->l);
  RBST::T vl = query(t->l, lpos, rpos);
  RBST::T vm = (lpos <= lsize && lsize < rpos) ? t->val : RBST::init_val;
  RBST::T vr = query(t->r, lpos - lsize - 1, rpos - lsize - 1);

  return RBST::op(vl, RBST::op(vm, vr));
}

// Insert an element at k-th position
RBST* insert(RBST* t, int k, RBST::T val) {
  auto s = split(t, k);
  RBST* b = new RBST(val);
  return merge(s.first, merge(b, s.second));
}

// Erase an element at k-th position
RBST* erase(RBST* t, int k) {
  auto s1 = split(t, k + 1);
  auto s2 = split(s1.first, k);
  return merge(s2.first, s1.second);
}

// Return data[index]
RBST* at(RBST* t, int index) {
  assert(t);
  if (index < count(t->l)) {
    return at(t->l, index);
  } else {
    index -= count(t->l);
  }
  if (index == 0) {
    return t;
  }
  index--;
  return at(t->r, index);
}
