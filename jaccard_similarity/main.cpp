#include <iostream>
#include <unordered_set>
#include <vector>

float jaccardSimilarity(const std::vector<int> &setA,
                        const std::vector<int> &setB) {
  std::unordered_set<int> setAElements(setA.begin(), setA.end());
  std::unordered_set<int> setBElements(setB.begin(), setB.end());

  std::unordered_set<int> intersection;
  std::unordered_set<int> unionSet;

  std::set_intersection(setAElements.begin(), setAElements.end(),
                        setBElements.begin(), setBElements.end(),
                        std::inserter(intersection, intersection.begin()));

  std::set_union(setAElements.begin(), setAElements.end(), setBElements.begin(),
                 setBElements.end(), std::inserter(unionSet, unionSet.begin()));

  return static_cast<float>(intersection.size()) / unionSet.size();
}

int main() {
  std::vector<int> setA = {1, 2, 3, 4, 5};
  std::vector<int> setB = {4, 5, 6, 7, 8};

  float similarity = jaccardSimilarity(setA, setB);
  std::cout << "Jaccard Similarity: " << similarity << std::endl;

  return 0;
}
