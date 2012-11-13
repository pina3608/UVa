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
  int correctSeq[n];
  int newSeq[n];
  int score[n];
  int new_event;

  fi(n) {
    cin >> new_event;
    correctSeq[new_event-1] = i;
  }
  fi(n) score[i] = 0;

  int times = 0;

  while (cin >> new_event){

    newSeq[new_event-1] = times;
    times++;

    if (times == n){

      int totalMax = 0;
      fi(n){
        int j = 0;
        int maxScore = 0;
        while (correctSeq[j] != newSeq[i]){
          maxScore = max(score[correctSeq[j]], maxScore);
          j++;
        }
        score[newSeq[i]] = maxScore + 1;
        totalMax = max(totalMax, maxScore+1);
      }

      fi(n) score[i] = 0;

      cout << totalMax << endl;
      times = 0;
    }


  }

}
