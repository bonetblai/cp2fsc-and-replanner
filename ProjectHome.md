The project hosts two planners for solving partially observable planning problems: **cp2fsc** and **K-Replanner**.


---


## cp2fsc ##

It is an automated tool for generating finite-state controllers (FSCs) for partially observable problems. The FSCs are Mealy machines whose transitions, conditional on observations, dictate the actions to apply in the environment.

In order to synthetise the FSC, the control problem (CP) is translated into a conformant problem and then into a classical planning problem. The solution of the classical problem define the FSC for the control problem.

Quite ofter, the FSC also works for control problems different from the input with respect to size, presence of non-deterministic actions or exogenous events.

For more details, see

  * B. Bonet, H. Palacios and H. Geffner. _Automatic Derivation of Memoryless Policies and Finite-State Controllers Using Classical Planners_. Proc. of 19th Int. Conf. on Automated Planning and Scheduling (ICAPS). 2009. Pages 34-41. [(PDF)](http://ldc.usb.ve/~bonet/reports/ICAPS09-fsc.pdf)

  * B. Bonet, H. Palacios and H. Geffner. _Automatic Derivation of Finite-State Machines for Behavior Control (Nectar Track)_. Proc. of 24th Conf. on Artificial Intelligence (AAAI). 2010. Pages 1656-1659. [(PDF)](http://ldc.usb.ve/~bonet/reports/AAAI10-nectar-fsc.pdf)


---


## K-Replanner ##

It is a closed-loop online controller that solves a given instance of a control problem. A replanner does not generate a full conditional plan. Instead, it says what action to apply at each time point, observe the effects of the actions, continues in this fashion until the problem is solved.

At each decision stage, the K-Replanner builds a classical planning problem whose solutions gives the actions to apply in the real world: given such solution (classical plan = linear sequence of actions), the actions in the plan are applied until the assumptions made in the plan are no longer valid.

Under certain conditions, the K-Replanner is sound and complete for the class of control problems considered.

For more details, see

  * B. Bonet and H. Geffner. _Planning under Partial Observability by Classical Replanning: Theory and Experiments_. Proc. of 22nd Int. Joint Conf. on Artificial Intelligence (IJCAI). 2011. Pages 1936-1941. [(PDF)](http://ldc.usb.ve/~bonet/reports/IJCAI11-replanning.pdf)


---


Notes:

  * Check the documentation at the [Wiki](http://code.google.com/p/cp2fsc-and-replanner/wiki/Introduction).
  * For obtaining the code, go to [Checkout Source](http://code.google.com/p/cp2fsc-and-replanner/source/checkout).
  * For re-generating the parser and lexical analyzer, you need flex++ and bison++. Both are available in [Downloads](http://code.google.com/p/cp2fsc-and-replanner/downloads/list).


---

