// UnionFind
// required: <vector>
struct UnionFind {
  using T = long long; // この構造体で使う型
  vector<T> par; // 親
  vector<T> rank; // 木の深さ
  vector<T> set_size; // サイズ取得用
  T group_count; // 集合の数
  // n要素で初期化
  void init(T n) {
    group_count = n;
    par.resize(n);
    rank.resize(n);
    set_size.assign(n, 1);
    for (T i = 0; i < n; i++) {
      par[i] = i;
      rank[i] = 0;
    }
  }
  // 木の根を求める
  T find(T x) {
    if (par[x] == x) {
      return x;
    } else {
      return par[x] = find(par[x]);
    }
  }
  // xとyの属する集合を併合
  void unite(T x, T y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (rank[x] < rank[y]) {
      par[x] = y;
      set_size[y] = set_size[x] + set_size[y];
    } else {
      par[y] = x;
      set_size[x] = set_size[x] + set_size[y];
      if (rank[x] == rank[y]) rank[x]++;
    }

    group_count--;
  }
  // xとyが同じ集合に属するか否か
  bool same(T x, T y) {
    return find(x) == find(y);
  }
  // vが属する集合の大きさを求める
  T get_set_size(T v) {
    return set_size[find(v)];
  }
  
  UnionFind(T n) {
    init(n);
  }
};
