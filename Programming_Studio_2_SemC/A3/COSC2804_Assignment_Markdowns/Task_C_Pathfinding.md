# COSC2804 - Task C: Pathfinding

## Overview
Connect houses and waypoints using paths that follow terrain constraints.

## Components
1. Connect waypoints (Prim’s algorithm)
2. Connect houses to nearest waypoint
3. Find paths (Breadth-First Search)
4. Build paths and waypoint structures

## BFS Pathfinding Rules
- Avoid houses, walls, and water
- Max height difference between steps: 1 block
- Prefer flat terrain
- Must be fully walkable between all houses

## Implementation Requirement
- No STL containers allowed
- Implement custom data structures for BFS queue and visited list
