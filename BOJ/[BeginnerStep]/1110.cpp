#include<cstdio>
int n, t, cnt;
int main() {
   scanf("%d", &n);
   t = n;
   do {
      t = t % 10 * 10 + (t / 10 + t % 10) % 10;
      cnt++;
   } while(t^n);
   printf("%d", cnt);
   return 0;
}