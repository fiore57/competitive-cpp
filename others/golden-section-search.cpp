constexpr double GRAITO = 1.6180339887498948482045868343656;
// 黄金分割探索
// f(x)が区間[lb, ub]で下に凸ならば、その極値を取るxを返す
// 反復時に値が使い回せるので、fの計算が1回で済む
// f: 凸関数
// lb: 下限
// ub: 上限
// k: 反復回数
double goldenSectionSearch(function<double(double)> f, double lb, double ub,
                           int k) {
    double x1 = (ub - lb) / (GRAITO + 1) + lb; // 内分点(1:GRAITO)
    double x2 = (ub - lb) / GRAITO + lb;       // 内分点(GRAITO:1)
    double f1 = f(x1), f2 = f(x2);

    rep(i, k) {
        if (f1 < f2) {
            // 右側の区間を除外する
            ub = x2;
            x2 = x1; // 内分点（左）を次の内分点（右）に採用する
            f2 = f1;
            x1 = (ub - lb) / (GRAITO + 1) + lb; // 次の内分点（左）を計算する
            f1 = f(x1);
        } else {
            // 左側の区間を除外する
            lb = x1;
            x1 = x2; // 内分点（右）を次の内分点（左）に採用する
            f1 = f2;
            x2 = (ub - lb) / GRAITO + lb; // 次の内分点（右）を計算する
            f2 = f(x2);
        }
    }
    return (lb + ub) / 2;
}