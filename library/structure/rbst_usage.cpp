RBST* root = NULL;
for (int i : range(N)) {
  int a; scanf("%d", &a);
  root = insert(root, i, a);
}
// ...
