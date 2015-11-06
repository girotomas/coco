#include <stdio.h>
#include <assert.h>

#include "coco.h"

#include "coco_problem.c"

static void private_f_bent_cigar_evaluate(coco_problem_t *self, const double *x, double *y) {
  static const double condition = 1.0e6;
  size_t i;
  assert(self->number_of_objectives == 1);

  y[0] = x[0] * x[0];
  for (i = 1; i < self->number_of_variables; ++i) {
    y[0] += condition * x[i] * x[i];
  }
}

static coco_problem_t *f_bent_cigar(const size_t number_of_variables) {
  size_t i, problem_id_length;
  coco_problem_t *problem = coco_problem_allocate(number_of_variables, 1, 0);
  problem->problem_name = coco_strdup("bent cigar function");
  /* Construct a meaningful problem id */
  problem_id_length = (size_t) snprintf(NULL, 0, "%s_%02lu", "bent_cigar", (long) number_of_variables);
  problem->problem_id = coco_allocate_memory(problem_id_length + 1);
  snprintf(problem->problem_id, problem_id_length + 1, "%s_%02lu", "bent_cigar", (long) number_of_variables);

  problem->number_of_variables = number_of_variables;
  problem->number_of_objectives = 1;
  problem->number_of_constraints = 0;
  problem->evaluate_function = private_f_bent_cigar_evaluate;
  for (i = 0; i < number_of_variables; ++i) {
    problem->smallest_values_of_interest[i] = -5.0;
    problem->largest_values_of_interest[i] = 5.0;
    problem->best_parameter[i] = 0.0;
  }
  /* Calculate best parameter value */
  private_f_bent_cigar_evaluate(problem, problem->best_parameter, problem->best_value);
  return problem;
}
