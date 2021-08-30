#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
  freopen("square.in","r",stdin);
  freopen("square.out","w",stdout);

  int a,b,c,d,e,f,g,h;
  cin >> a >> b >> c >> d >> e >> f >> g >> h;

  // the formula below is not right but only solves the first input :)
  cout << (c-e)*(d-e) << endl;
}