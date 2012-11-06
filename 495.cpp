/*
 *
 * @author Santiago Pina (santiago.pina1@gmail.com)
 *
 */

#include <string>
#include <iostream>


using namespace std;

/*
 * Add two positive big integers
 */

string add(string a, string b){

  string sol = "";
  int carry = 0;
  int aindex = a.size()-1;
  int bindex = b.size()-1;

  while ( aindex >= 0 || bindex >= 0 || carry != 0){

    if (aindex >= 0) {
      carry+= (a[aindex] - '0');
      aindex--;
    }
    if (bindex >= 0) {
      carry+= (b[bindex] - '0');
      bindex--;
    }

    sol.insert(sol.begin(),'0' + (carry%10));
    carry /= 10;

  }

  return sol;

}

string sol[5001];

string fib(int a){

  if (sol[a].size() > 0) return sol[a];
  else {
    string aux = add(fib(a-1), fib(a-2));
    sol[a] = aux;
    return aux;

  }

}

int main(){

  int n;
  sol[0] = "0";
  sol[1] = "1";

  while (cin >> n){
    cout << "The Fibonacci number for " << n << " is " << fib(n) << endl;
  }

  return 0;


}
