/*
 * Santiago Pina (santiago.pina1@gmail.com)
 *
 */

#include <iostream>

using namespace std;

int count_ones(int d){

  int count = 0;

  while(d > 0){
    if (d%2 == 1) count++;
    d /= 2;
  }

  return count;

}

int main(){

  int n;

  cin >> n;

  while (n--){

    int d;
    cin >> d;

    cout << count_ones(d);

    int count = 0;
    while (d > 0){
      int last = d%10;
      count += count_ones(last);
      d /= 10;
    }

    cout << " " << count << endl;

  }


}
