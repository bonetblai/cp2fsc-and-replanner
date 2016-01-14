# LW1 Solver inference flow


For every problem instance:

1. A _LW1_Solver_ object named `solver` is created and initialized using:
  * A _Instance_ object named `instance`.
  * A pointer to a _LW1_Instance_ object named `kp_instance`.
  * A pointer to a _ClassicalPlanner_ object named `planner`.
  * A integer named `opt_time_bound`.
  * A integer named `opt_ncalls_bound`.

  (So far, details of this creation and initialization are irrelevant).

2. If _preload_ is enabled:
  * `instance` is initialized further.
  * If _watched-literals_ is enabled:
    * A *WatchedLiterals* object named `wl` is created.
    * A list of axioms are preloaded into `wl`.

3. If _arc-consistency_ is enabled:
  * A _CSP_ object named `csp` is created.
  * `csp` is initialized using a list of variables in `kp_instance` and
    map of indexes of atoms to indexes of vars in `solver`.

4. The `solve` method in `solver` is called.

   This method theorically should be called only once per problem instance as it
   should iterate until it finds a solution.

5. Inside `solve` some variables are initialized and the method `apply_inference`
   is called.

   This method receives:
      * The last action made by the agent as a pointer to an instance of the
      _Action_ object named `last_action`.
      * A set of the atoms sensed at the last step.
      * An instance of the _LW1_State_ object called `state`

   The first call to this method is made with no `last_action` (integer 0), an
   empty set for the `sensed_at_step` and an initial state.

6. Still inside, a replan loop is iterated until a solution is found.

   [Needs details]
`