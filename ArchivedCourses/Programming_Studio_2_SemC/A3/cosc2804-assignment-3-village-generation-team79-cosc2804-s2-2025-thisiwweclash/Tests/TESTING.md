# Task A:

## Component 1 - Find Plots
**Test 1**: Normal Usage  
**Description**: Ensures valid plots are correctly detected within the wall boundaries under flat terrain.  
**Setup**: loc=123,123 village-size=50 plot-border=8 seed=123 testmode=1  
**Expected Output**: Should print that 1 valid plot(s) were found inside walls.

**Test 2**: Small Village (no plots)  
**Description**: Checks behavior when village size is too small to fit any valid plots.  
**Setup**: loc=123,123 village-size=10 plot-border=8 seed=123 testmode=1  
**Expected Output**: Should print warning: “No valid plots found.”

---

## Component 2 - Terraforming
**Test 1**: Normal Usage (flat terrain)  
**Description**: Tests that plots are flattened, slopes smoothed, and white wool borders added correctly on flat land.  
**Setup**: loc=123,123 village-size=50 plot-border=8 seed=123 testmode=1  
**Expected Output**: Should print “Terraforming complete.”

**Test 2**: Hilly Terrain  
**Description**: Ensures terraforming adjusts properly on uneven terrain without creating cliffs or floating land.  
**Setup**: loc=250,250 village-size=50 plot-border=8 seed=321 testmode=1  
**Expected Output**: Should print “Terraforming complete.”

---

## Component 3 - Place Wall
**Test 1**: Normal Usage  
**Description**: Tests adaptive wall creation to confirm smooth walls are built fully enclosing the village area.  
**Setup**: loc=123,123 village-size=50 plot-border=8 seed=123 testmode=1  
**Expected Output**: Should print “Walls built”.



# Task B:
## Component 1 - {Component name}
**Test 1**: Test name
**Description**: {Description}
**Setup**: {arguments} {other details needed to setup the test}
**Expected Output**: {Criteria}


# Task C:
## Component 1 - {Component name}
**Test 1**: Test name
**Description**: {Description}
**Setup**: {arguments} {other details needed to setup the test}
**Expected Output**: {Criteria}

# Example Test:
## Task B Subdividing Building:
**Test 1**: Normal Usage:
**Description**: Testing a normal use case for recursive subdivision.
**Setup**: loc=123,123 village-size=50, plot-border=10, seed=1, testmode
(123,123) should be within superflat terrain, to ensure no environmental disruptions.
**Expected output**
XXXXXXXXXXXXXXXXXXXXX
X    X    X    X    X
X    .    .    .    X
X    X    X    X    X
X    X    X    X    X
XXX.XXXX.XXXX.XXXX.XX
X    X    X    X    X
X    X    X    X    X
X    X    X    X    X
X    X    X    X    X
XXX.XXXX.XXXX.XXXX.XX
X    X    X    X    X
X    X    X    X    X
X    X    X    X    X
X    X    X    X    X
XXX.XXXX.XXXX.XXXX.XX
X    X    X    X    X
X    .    .    .    X
X    X    X    X    X
X    X    X    X    X
XXXXXXXXXXXXXXXXXXXXX
