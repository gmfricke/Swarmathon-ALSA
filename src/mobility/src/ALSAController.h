// This is the Adaptive Levy Walk Controller.
// This class estimates the target distribution and generates a Levy search pattern with the appropriate exponent

#include <utility>

using namespace std;

struct GoalState
{
  float x;
  float y;
  float yaw;
};

class ALSAController
{
 public:
  ALSAController();
  GoalState getNextGoalPosition(pair<float, float> current_position);

  ~ALSAController();

 private:
  float min_step_length = 0.5; // Define the minimum step length to be 5 cm
  float mu = 1.5; // mu is the PDF inverse power law exponent
};
