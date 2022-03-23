#include <iostream>
#include <set>
#include <iomanip>
#include <iterator>
using namespace std;

int main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	multiset<double> s;
	multiset<double>::iterator e,b;
	double num, first, third, ans;
	int i=-1;

	while (cin >> num) {

		if (num == 0) {
			break;
		}

		s.insert(num);

		if (i == -1) {
			b = s.begin();
			e = --s.end();
			cout << 0 << '\n';
			i++;
			continue;
		}
		else if (i == 0) {
			if (num < *b) {
				b--;
			}
			else {
				e++;
			}
			first = *b;
			third = *e;
		}
		else if (i % 4 == 1) {
			if (num < *b) {
				b--;
			}
			else if(num >= *e){
				e++;
			}
			first = *b;
			third = *e;
		}
		else if (i % 4 == 2 || i % 4 == 3) {
			if (num < *b) {
				b--;
			}
			else if (num >= *e) {
				e++;
			}
			
			first = (*b + *++b) / 2.0;
			third = (*e + *--e) / 2.0;
			b--;
			e++;
		}
		else if (i % 4 == 0) {
			if (num < *b) {
				e--;
			}
			else if (num >= *e){
				b++;
			}
			else {
				b++;
				e--;
			}
			first = *b;
			third = *e;
		}

		ans = third - first;

		if (int(ans) == ans) {
			cout << int(ans) << '\n';
		}
		else {
			cout << fixed << setprecision(1) << ans << '\n';
		}

		i++;
	}

}
