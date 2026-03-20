# COSC2804 - Task A: Finding House Plots & Terraforming

## Overview
Task A focuses on generating the high-level structure of the village and consists of:
1. Finding suitable building locations
2. Terraforming land surrounding plots
3. Building a village wall
4. Placing waypoints for path generation

## Plot Validation
- Village area is centered around player (x, z)
- Plot sizes: 14–20 blocks, border = `--plot-border`
- Valid plots must:
  - Have ≤15% water coverage
  - Have ≤15 block slope delta
  - Not intersect other plots or walls
  - Have accessible entrances facing inward

## Terraforming
- Flatten land using maximum height
- Smooth terrain using a function like:
  
`block_height(d, yg, yp, p) = round(yg + (yp - yg) * (p - d) / p)`
- Function can be linear or sine-based for aesthetics

## Village Wall
- Height: 3–4 blocks
- Must be unjumpable by players

## Waypoints
- Group plots into 3’s and place waypoints in open spaces
- ≥1 waypoint per 3 plots (minimum 1 per 5 plots)
