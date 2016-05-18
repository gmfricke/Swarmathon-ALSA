#include "ALSAController.h"

#include <math.h> // for sin(), cos(), and pow()
#include <stdlib.h>  // For rand()

ALSAController::ALSAController()
{
  
}

GoalState ALSAController::getNextGoalPosition(pair<float, float> current_position)
{
  GoalState goal_state;
  
  float xmin = min_step_length; // Set the minimum step length
  pair<float, float> goal_position;

  // We don't care about the current yaw (heading) since the movement is uncorrelated
  // Use a levy walk formulation - so uniform heading.
  float goal_yaw = (rand()*1.0/RAND_MAX)*2*M_PI;
  
  //select new position with distance selected from a power law distribution
  float unif_var = rand()*1.0/RAND_MAX;
  
  float step_length = xmin*pow(unif_var,1/(mu-1));

  // Populate the position to return
  goal_state.x = current_position.first + (step_length * cos(goal_yaw));
  goal_state.y = current_position.second + (step_length * sin(goal_yaw));	   goal_state.yaw = goal_yaw;      
  
  return goal_state;
}

ALSAController::~ALSAController()
{
}
