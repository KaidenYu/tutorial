
#### P10
- Dealock: e.g. signal handler and main flow both do printf()
  - main routine execute printf() which aquires a lock, and then got interrupted by signal handler that also execute printf(), and the printf() also aquires a lock that it won't be able to get it
