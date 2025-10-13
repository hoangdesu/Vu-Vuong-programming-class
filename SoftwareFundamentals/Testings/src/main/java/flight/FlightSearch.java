package flight;

import java.util.Set;

public class FlightSearch {
   private String  departureDate;
   private String  departureAirportCode;
   private boolean emergencyRowSeating;
   private String  returnDate;
   private String  destinationAirportCode; 
   private String  seatingClass;
   private int     adultPassengerCount;
   private int     childPassengerCount;
   private int     infantPassengerCount;


   public boolean runFlightSearch(String departureDate,
                                  String departureAirportCode,
                                  boolean emergencyRowSeating,
                                  String returnDate,
                                  String destinationAirportCode,
                                  String seatingClass,            // "economy", "premium economy", "business", "first"
                                  int adultPassengerCount,
                                  int childPassengerCount,
                                  int infantPassengerCount
   ) {

      //TODO: Validate all the provided parameters.
      //if the search parameters meets the given conditions, 
      //   the function should initialise all the class attributes and return true.
      //else 
      //   the function should return false

//      Guard clause

//      Condition 1. The total number of passenger per search must be at least 1 and cannot exceed 9.
      int totalPassengers = adultPassengerCount + childPassengerCount + infantPassengerCount;
      if (totalPassengers < 1 || totalPassengers > 9) return false;


//      Condition 2. Children cannot be seated in emergency row seating or first class.
//      ...





//      Condition 9. The seating class must be one of ("economy", "premium economy", "business", "first")
//      if (!seatingClass.equals("economy") && !seatingClass.equals("economy") && !seatingClass.equals("economy") && !seatingClass.equals("economy"))
      Set<String> validSeatingClasses = Set.of("economy", "premium economy", "business", "first");
      if (!validSeatingClasses.contains(seatingClass)) return false;



//      Condition 11. Only the following airports are available: "syd" (Sydney), "mel"
//      (Melbourne), "lax" (Los Angeles), "cdg" (Paris), "del" (Delhi), "pvg" (Shanghai) and
//      "doh" (Doha). eg for a flight from Melbourne to Shanghai, the departure airport code
//      would be "mel" and the destination airport code would be "pvg".

      Set<String> validAirportCodes = Set.of("syd", "mel", "lax", "cdg", "del", "doh");
      if (!validAirportCodes.contains(departureAirportCode) || !validAirportCodes.contains(destinationAirportCode)) return false;

//      Furthermore, the departure airport and destination airport cannot be the same
      if (departureAirportCode.equals(destinationAirportCode)) return false;


      return true;
   }
}
