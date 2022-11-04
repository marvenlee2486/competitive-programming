#include <bits/stdc++.h>
int n, res, ans, cnt, lst;
bool can_add;
std::array<int, 100> a;
void solve() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.begin() + n);
  ans = 1;
  for (int i = 0; i < n; ++i) {
    res = 2, cnt = 1, lst = a[i];
    can_add = true;
    for (int j = i + 1; j < n; ++j) {
      if (a[j] - lst <= 1) {
        lst = a[j], cnt++;
        can_add = true;
      } else if (a[j] - lst == 2) {
        lst = a[j], cnt++;
        can_add = false;
      } else if (a[j] - lst == 3) {
        if(res == 0) break;
        if (can_add) {
          res--;
          can_add = false;
          lst = a[j], cnt++;
        } else {
          res--;
          can_add = false;
          lst = a[j] - 1, cnt++;
        }
      } else if(a[j] - lst == 4){
        if (can_add && res == 2) {
          res = 0;
          can_add = false;
          lst = a[j] - 1;
          cnt++;
        } else {
          break;
        }
      }else{
        break;  
      }
    }
    // std::cout << cnt << " ";
    ans = ans > cnt ? ans : cnt;
  }
  std::cout << ans << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  int _ = 1;
  std::cin >> _;
  int t = 0;
  while (_--) {
    std::cout << "Case " << ++t << ": ";
    solve();
  }
}