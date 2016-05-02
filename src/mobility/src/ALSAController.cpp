#include "ALSAController.h"

#include <math.h> // for sin(), cos(), and pow()
#include <stdlib.h>  // For rand()

ALSAController::ALSAController()
{
  
}

pair<float, float> ALSAController::getNextGoalPosition(pair<float, float> current_position)
{
  float xmin = min_step_length; // Set the minimum step length
  pair<float, float> goal_position;

  // We don't care about the current yaw (heading) since the movement is uncorrelated
  // Use a levy walk formulation - so uniform heading.
  float goal_yaw = (rand()*1.0/RAND_MAX)*2*M_PI;
  
  //select new position with distance selected from a power law distribution
  float unif_var = rand()*1.0/RAND_MAX;
  float scale = (mu-1)/xmin; // Scale to have area = 1 (i.e. PDF)
  float step_length =  scale*pow(unif_var/xmin, -mu); // Calcuate how far to travel

  // Populate the position to return
  goal_position = make_pair( current_position.first + (step_length * cos(goal_yaw)),
			     current_position.second + (step_length * sin(goal_yaw)) );		      
  
  return goal_position;
}

ALSAController::~ALSAController()
{
}
