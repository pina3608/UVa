/*
 * @author Santiago Pina (santiago.pina1@gmail.com)
 *
 */

#include <iostream>

#define MAX 7490

using namespace std;

int table[MAX];

int res(int a){

  if (a < 0) return 0;
  else return table[a];

}

int main(){

  int n;
  int coins[5] = {1, 5, 10, 25, 50};
  table[0] = 1;

  for(int i = 1; i < MAX; i++) table[i] = 0;

  for(int j = 0; j < 5; j++){
    for (int i = 1; i < MAX; i++){
      table[i] += res(i-coins[j]);
    }
  }

  while (cin >> n){
    cout << res(n) << endl;
  }

}
