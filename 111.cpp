#include <iostream>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define fi(n) forn(i,n)
#define fj(n) forn(j,n)

using namespace std;



int main(){

  int n;
  cin >> n;
  int correct_seq[n];
  int new_seq[n];
  int score[n];
  int new_event;

  fi(n) {
    cin >> new_event;
    correct_seq[new_event-1] = i;
  }
  fi(n) score[i] = 0;

  int times = 0;

  while (cin >> new_event){

    new_seq[new_event-1] = times;
    times++;

    if (times == n){

      int total_max = 0;
      fi(n){
        int j = 0;
        int max_score = 0;
        while (correct_seq[j] != new_seq[i]){
          max_score = max(score[correct_seq[j]], max_score);
          j++;
        }
        score[new_seq[i]] = max_score + 1;
        total_max = max(total_max, max_score+1);
      }

      fi(n) score[i] = 0;

      cout << total_max << endl;
      times = 0;
    }


  }

}
