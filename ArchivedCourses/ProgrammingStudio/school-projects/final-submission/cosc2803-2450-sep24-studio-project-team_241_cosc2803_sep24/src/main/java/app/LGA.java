package app;

/**
 * Class represeting a LGA from the Studio Project database
 * In the template, this only uses the code and name for 2018 (so you will need to update this to handle all years)
 *
 * @author Halil Ali, 2024. email: halil.ali@rmit.edu.au
 */

 public class LGA {
    // LGA Code
    private int code;
 
    // LGA Name
    private String name;

    private String regionType;
 
    /**
     * Create an LGA and set the fields
     */
    public LGA(int code, String name) {
       this.code = code;
       this.name = name;
    }
    public LGA(int code, String name, String regionType) {
      this.code = code;
      this.name = name;
      this.regionType = regionType;
   }
 
    public int getCode() {
       return code;
    }
 
    public String getName() {
       return name;
    }
    public String getRegionType() {
      return this.regionType;
    }

    public String toString() {
      return String.format("code: %d - name: %s - regionType: %s", code, name, regionType);
    }
 }
 