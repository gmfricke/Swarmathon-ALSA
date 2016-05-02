// This is the Adaptive Levy Walk Controller.
// This class estimates the target distribution and generates a Levy search pattern with the appropriate exponent

#include <utility>

using namespace std;

class ALSAController
{
 public:
  ALSAController();
  pair<float, float> getNextGoalPosition(pair<float, float> current_position);

  ~ALSAController();

 private:
  float min_step_length = 0.05; // Define the minimum step length to be 5 cm
  float mu = 1.2; // mu is the PDF inverse power law exponent
};
