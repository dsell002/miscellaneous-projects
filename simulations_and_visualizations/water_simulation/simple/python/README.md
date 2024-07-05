## Description of the Water Simulation
In this water simulation, I create a simple visual representation of water surface dynamics by simulating wave propagation and disturbances. Here's a detailed breakdown of the processes involved:

## Initialization
- Height Maps: There are two arrays, current_height and previous_height, representing the heights of the water surface at each point on the grid.
- Velocities: An additional array, velocities, is used to store the velocity of the water at each point.
## Wave Propagation
- Height Update: The core of the simulation is the update_water_surface function. For each point on the water surface, the new height is calculated based on the average height of its neighboring points. This calculation is based on the wave equation, which models how waves propagate over time.
- Energy Loss (Damping): To simulate energy loss, we apply a damping factor to the heights. This damping factor reduces the wave amplitude over time, mimicking the natural loss of energy in real water waves.
## Disturbances
Mouse Interaction: The disturb function allows the user to create disturbances on the water surface by clicking the mouse. When a disturbance occurs, it modifies the height of the water at the clicked location and its surrounding area, generating new waves.
## Rendering
- Visual Representation: In each frame, the simulation renders the water surface by mapping the height of each point to a color intensity. Higher points are represented by brighter colors (higher intensity), creating the illusion of light reflecting off the water surface.
Color Mapping: Each pixel's color is determined by its height value, with a color gradient applied to simulate the visual effect of waves.
## Overall Behavior
- Wave Generation: When the simulation starts, the water surface is initially calm. As the user interacts by clicking, disturbances are created, generating waves.
- Wave Propagation: These waves propagate outward from the disturbance points, spreading across the water surface.
- Energy Dissipation: Over time, the waves lose energy due to the damping factor, causing them to gradually diminish in amplitude.
- Continuous Update: The simulation continuously updates the water surface based on the wave equation, rendering the changes in real-time to create a dynamic and realistic water effect.
## Physics Behind the Simulation
The simulation employs a simplified version of the wave equation, which is a fundamental principle in fluid dynamics. This equation describes how waveforms evolve over time and space, capturing the behavior of waves in various mediums, including water.

## Visualization
By using Pygame for rendering, we can visually observe the effects of wave propagation and disturbances on the water surface.