## General objective
Determine whether temperature, humidity, gas concentration, and their temporal behavior can be used to establish an adaptive environmental baseline and identify deviations corresponding to normal, medium-risk, and high-risk conditions while maintaining a low false-alarm rate and sufficient detection of high-risk events.
## EDA questions
- RQ1 — Data quality
Are the sensor measurements reliable and consistent enough for analysis?

- RQ2 — Normal behavior
What characterizes normal conditions in each environment?

- RQ3 — Environmental differences
How does normal behavior differ between houses, kitchens,
stores, workshops, etc.?

- RQ4 — Temporal behavior
Are changes over time more informative than individual measurements?

- RQ5 — Abnormal behavior
How do controlled abnormal events alter the sensor measurements?

- RQ6 — Feature usefulness
Which measurements and derived features contain useful information
for distinguishing normal and abnormal conditions?

- RQ7 — Adaptation
Can environmental deviations be expressed relative to the
baseline of each location?

- RQ8 — Classification
Can the system distinguish NORMAL, MEDIUM and HIGH risk?

- RQ9 — Reliability
Can high-risk situations be detected while keeping false alarms
acceptably low?

- RQ10 — Deployment
Can the resulting approach run within the computational constraints
of an ESP32?
## Methods
### Experimentation
1. Gather normal ambient data
2. Train a preeliminar model
3. Simulate outliers in the variables by creating controlled fire scenarios and gather this data
4. Evaluate the efectivity of the model to detect outliers
5. Iterate
