#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	auto f = vvl(n, vl(n));
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < n; ++j) {
			int x;
			cin >> x;

			if (0 == j) {
				f[i][j] = x;
			}
			else {
				f[i][j] = f[i][j - 1] + x;
			}
		}
	}

	while (0 < (m--)) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		--x1;
		y1 -= 2;
		--y2;

		auto ans = ll{ 0 };
		for (auto x = x1; x < x2; ++x) {
			if (y1 < 0) {
				ans += f[x][y2];
			}
			else {
				ans += f[x][y2] - f[x][y1];
			}
		}

		cout << ans << '\n';
	}

	return 0;
}