/*
 * Santiago Pina (santiago.pina1@gmail.com)
 *
 */

#include<iostream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fi(n) forn(i,n)
#define fj(n) forn(j,n)
#define mp make_pair

#define fs first
#define sc second

typedef pair<int,int> pii;

pii table[100][100];
int M, N;

pii set_find(pii x){

  if ( x == table[x.fs][x.sc] ) return x;
  pii root = set_find (table[x.fs][x.sc]);
  table[x.fs][x.sc] = root;
  return root;


}

void set_union(int x1, int y1, int x2, int y2){

  if (x2 < 0 || y2 < 0 || x2 >= M || y2 >= N
      || table[x2][y2] == mp(-1,-1) ) return;

  pii aux = set_find(mp(x2,y2));

  table[aux.fs][aux.sc] = mp(x1,y1);

}

int main(){

  while(true){

    cin >> M >> N;

    if (M == 0) break;

    fi(M){
      fj(N){
        char aux;
        cin >> aux;
        if( aux == '@') {
          table[i][j] = mp(i,j);
          set_union(i, j, i-1, j);
          set_union(i, j, i-1, j-1);
          set_union(i, j, i-1, j+1);
          set_union(i, j, i, j-1);
        }
        else table[i][j] = mp(-1,-1);

      }
    }

    int count = 0;

    fi(M){
      fj(N){
        if (table[i][j] == mp(i,j))
          count++;

      }
    }

    cout << count << endl;



  }


  return 0;

}
