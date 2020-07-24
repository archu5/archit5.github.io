#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
using namespace std;

struct Segment
{
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments)
{
  vector<int> points;
  int curr_first = segments[0].start;

  int curr_second = segments[0].end;
  int min = curr_second;
  //write your code here
  for (size_t i = 1; i < segments.size(); ++i)
  {
    if (segments[i].start <= curr_second)
    {
      if (segments[i].end < min)
        min = segments[i].end;
    }
    else
    {
      points.push_back(min);
      curr_first = segments[i].start;
      curr_second = segments[i].end;
      min = curr_second;
    }
    if (i == (segments.size() - 1))
    {
      points.push_back(min);
    }

    /* points.push_back(segments[i].start);
    points.push_back(segments[i].end);*/
  }
  return points;
}

int main()
{
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i)
  {
    std::cin >> segments[i].start >> segments[i].end;
  }
  sort(segments.begin(), segments.end(), [](const Segment &a, const Segment &b) {
    return a.start < b.start;
  });
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i)
  {
    std::cout << points[i] << " ";
  }
}
