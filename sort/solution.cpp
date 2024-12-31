#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 3e5;

int n, a[MAX_N + 5], pos[MAX_N + 5], T[MAX_N + 5];

void add(int x)
{
	while (x <= n)
	{
		T[x]++;
		x += x & -x;
	}
}

int get(int x)
{
	int r = 0;
	while (x)
	{
		r += T[x];
		x &= x - 1;
	}
	return r;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		pos[a[i]] = i;
	}

	long long answer = 0;

	for (int i = n; i; i--)
	{
		int p = pos[i];
		int relative_p = p - get(p);
		answer += min(relative_p - 1, i - relative_p);
		add(p);
	}
	printf("%lld\n", answer);
}
