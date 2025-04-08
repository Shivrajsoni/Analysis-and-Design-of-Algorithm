#include <bits/stdc++.h>
using namespace std;

void sorting(vector<vector<int>> &a) {
  for (int i = 0; i < a.size() - 1; i++) {
    int minindex = i;
    for (int j = i + 1; j < a.size(); j++) {
      if (a[j][1] < a[minindex][1])
        minindex = j;
    }
    if (i != minindex)
      swap(a[i], a[minindex]);
  }
}

void activitySelection(
    vector<vector<int>>
        &activities) { // sort(activities.begin(), activities.end(), compare);
  sorting(activities);

  for (int i = 0; i < activities.size(); i++) {
    cout << "[" << activities[i][0] << ", " << activities[i][1] << "]" << endl;
  }

  int lastEnd = 0;
  cout << "Selected activities:" << endl;
  for (int i = 0; i < activities.size(); i++) {
    if (activities[i][0] >= lastEnd) {
      cout << "[" << activities[i][0] << ", " << activities[i][1] << "]"
           << endl;
      lastEnd = activities[i][1]; // Update last selected end time
    }
  }
}

int main() {
  vector<vector<int>> activities = {{1, 2}, {2, 5},  {3, 4},  {6, 8},
                                    {5, 7}, {9, 19}, {7, 10}, {12, 14}};
  activitySelection(activities);
}
