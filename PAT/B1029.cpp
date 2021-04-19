#include <cctype>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAXL = 80;
int N;
bool isBroken[128];
vector<char> broken;
char good[MAXL], bad[MAXL];

void toupper(char *s, int n) {
  for (int i = 0; i < n; i++)
    s[i] = toupper(s[i]);
}

int main(void) {
//  freopen("in.txt", "r", stdin);
  memset(isBroken, false, sizeof isBroken);
  broken.clear();
  scanf("%s\n%s", good, bad);
  int nGood = strlen(good), nBad = strlen(bad);
  toupper(good, nGood);
  toupper(bad, nBad);
  for (int i = 0, j = 0; i < nGood; i++) {
    if (isBroken[int(good[i])])
      continue;
    if (j >= nBad || good[i] != bad[j]) {
      isBroken[int(good[i])] = true;
      broken.push_back(good[i]);
    } else
      j++;
  }
  for (char c : broken)
    putchar(c);
  putchar('\n');
  return 0;
}

/*
7_This_is_a_test
_hs_s_a_es

7TI
*/
